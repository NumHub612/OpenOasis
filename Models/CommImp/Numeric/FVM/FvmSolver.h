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
#include "Models/CommImp/Spatial/Grid.h"


namespace OpenOasis::CommImp::Numeric::FVM
{
using Spatial::Grid;
using Utils::real;

class FvmSolver : public Solver
{
private:
    std::shared_ptr<Grid> mGrid;
    Matrix<real>          mCoeffMat;
    std::vector<real>     mRhs;

    std::unordered_map<int, std::shared_ptr<Boundary>> mBoundaries;

    real mCoeffHeat;
    real mInitValue;

    ScalarField<real> mTemps;

public:
    ~FvmSolver() = default;
    FvmSolver(const std::shared_ptr<Grid> &grid);

    void SetBoundary(int faceIndex, const std::shared_ptr<Boundary> &bound) override;
    void SetInitialValue(
        const std::string                                    &var,
        const std::variant<real, Vector<real>, Tensor<real>> &value) override;
    void SetCoefficient(
        const std::string                                    &var,
        const std::variant<real, Vector<real>, Tensor<real>> &coeff) override;

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

    ScalarField<real> GetScalarSolutions() const override;
};

}  // namespace OpenOasis::CommImp::Numeric::FVM