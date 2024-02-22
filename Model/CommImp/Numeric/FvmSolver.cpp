/** ***********************************************************************************
 *    @File      :  FvmSolver.cpp
 *    @Brief     :  None
 *
 ** ***********************************************************************************/
#include "FvmSolver.h"
#include "LaplacianOperator.h"
#include "Model/Utils/Exception.h"


namespace OpenOasis::CommImp::Numeric
{
using namespace std;
using namespace Utils;


FvmSolver::FvmSolver(const shared_ptr<Grid> &grid) :
    mGrid(grid), mCoeffMat(grid->GetNumCells()), mRhs(grid->GetNumCells())
{}

void FvmSolver::SetBoundary(int faceIndex, const shared_ptr<Boundary> &bound)
{
    mBoundaries[faceIndex] = bound;
}

void FvmSolver::SetInitialValue(
    const string &var, const variant<real, Vector<real>, Tensor<real>> &value)
{
    if (var != "temp")
    {
        throw invalid_argument("only steady heat-diffusion");
    }

    mInitValue = get<real>(value);
}

void FvmSolver::SetCoefficient(
    const string &var, const variant<real, Vector<real>, Tensor<real>> &coeff)
{
    if (var != "temp")
    {
        throw invalid_argument("only steady heat-diffusion");
    }

    mCoeffHeat = get<real>(coeff);
}

void FvmSolver::ParseTimeDerivativeTerm()
{
    throw NotImplementedException();
}

void FvmSolver::ParseConvectiveTerm()
{
    throw NotImplementedException();
}

void FvmSolver::ParseDiffusionTerm()
{
    Laplacian lap(mGrid);

    lap.SetCoefficient(variant<real, Vector<real>, Tensor<real>>(mCoeffHeat));

    for (const auto &b : mBoundaries)
    {
        lap.SetBoundaryCondition(b.first, b.second->GetBoundaryCondition());
    }

    ScalarField tempField(mGrid->GetNumCells(), mInitValue);

    const auto &eqs = lap.Discretize(tempField, {});

    mCoeffMat += get<0>(eqs);

    const auto &rhs = get<1>(eqs);
    for (int i = 0; i < mGrid->GetNumCells(); ++i)
    {
        mRhs[i] += rhs[i];
    }
}

void FvmSolver::ParseSourceTerm()
{}

void FvmSolver::BeforeScheme()
{}

void FvmSolver::Scheme()
{}

void FvmSolver::AfterScheme()
{}

void FvmSolver::BeforeSolve()
{}

void FvmSolver::Solve()
{
    Eigen::Map<Eigen::Matrix<real, Eigen::Dynamic, 1>> b(mRhs.data(), (int)mRhs.size());
    Eigen::ConjugateGradient<Eigen::SparseMatrix<real>> solver;
    solver.compute(mCoeffMat.Data());
    if (solver.info() != Eigen::Success)
    {
        throw runtime_error("Solve compute failed.");
    }
    Eigen::Matrix<real, Eigen::Dynamic, 1> x = solver.solve(b);
    if (solver.info() != Eigen::Success)
    {
        throw runtime_error("Solve failed.");
    }

    mTemps.Resize(mGrid->GetNumCells());
    for (int i = 0; i < x.cols() * x.rows(); ++i)
    {
        mTemps(i) = x[i];
    }
}

void FvmSolver::AfterSolve()
{}

ScalarField<real> FvmSolver::GetScalarSolutions() const
{
    return mTemps;
}

}  // namespace OpenOasis::CommImp::Numeric