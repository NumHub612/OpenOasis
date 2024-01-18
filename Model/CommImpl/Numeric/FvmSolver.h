/** ***********************************************************************************
 *    Copyright (C) 2023, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  FvmSolver.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Discrete scheme based on finite volume method.
 *
 ** ***********************************************************************************/
#pragma once
#include "Solver.h"
#include "Matrix.h"
#include "Model/CommImpl/Spatial/Grid.h"


namespace OpenOasis::CommImpl::Numeric
{
using Spatial::Grid;

class FvmSolver : public Solver
{
private:
    std::shared_ptr<Grid> mGrid;
    Matrix<double>        mCoeffMat;
    std::vector<double>   mRhs;

    std::unordered_map<int, std::shared_ptr<Boundary>> mBoundaries;

    double mCoeffHeat;
    double mInitValue;

    ScalarField<double> mTemps;

public:
    ~FvmSolver() = default;
    FvmSolver(const std::shared_ptr<Grid> &grid);

    void SetBoundary(int faceIndex, const std::shared_ptr<Boundary> &bound) override;
    void SetInitialValue(
        const std::string                                          &var,
        const std::variant<double, Vector<double>, Tensor<double>> &value) override;
    void SetCoefficient(
        const std::string                                          &var,
        const std::variant<double, Vector<double>, Tensor<double>> &coeff) override;

    void ParseTimeDerivativeTerm() override;
    void ParseConvectiveTerm() override;
    void ParseDiffusionTerm() override;
    void ParseSourceTerm() override;

    void BeforeScheme() override;
    void Scheme() override;
    void AfterScheme() override;

    void BeforeSolve() override;
    void Solve() override;
    void AfterSolve() override;

    ScalarField<double> GetScalarSolutions() const override;
};

}  // namespace OpenOasis::CommImpl::Numeric