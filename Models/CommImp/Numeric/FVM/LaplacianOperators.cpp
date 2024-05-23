/** ***********************************************************************************
 *    @File      :  LaplacianOperators.cpp
 *    @Brief     :  Laplacian Operators.
 *
 ** ***********************************************************************************/
#include "LaplacianOperators.h"
#include "Models/Utils/Exception.h"


namespace OpenOasis::CommImp::Numeric::FVM
{
using namespace std;
using namespace Utils;


// ------------------------------------------------------------------------------------

static const string LAPLACIAN01 = "FvmLaplacian01";


REGISTER_CLS(FvmOperator, Laplacian01, LAPLACIAN01)


// ------------------------------------------------------------------------------------

string Laplacian01::GetName()
{
    return LAPLACIAN01;
}

void Laplacian01::Prepare()
{
    mGrid = mSolver->GetGrid();
}

LinearEqs Laplacian01::Discretize()
{
    const auto &coeffs = mSolver->GetCoefficient("");

    auto nCells = mGrid->GetNumCells();
    auto nFaces = mGrid->GetNumFaces();

    Matrix<real> A(nCells);
    vector<real> b(nCells);

    return LinearEqs(A, b);
}


}  // namespace OpenOasis::CommImp::Numeric::FVM