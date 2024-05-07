/** ***********************************************************************************
 *    Copyright (C) 2023, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  LaplacianOperators.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Laplacian Operators.
 *
 ** ***********************************************************************************/
#pragma once
#include "FvmOperator.h"
#include <functional>
#include <memory>


namespace OpenOasis::CommImp::Numeric::FVM
{
using Utils::real;


/// @brief Laplacian01 operator for .
class Laplacian01 : public LaplacianOperator
{
private:
    Mesh                                       mMesh;
    std::unordered_map<int, BoundaryCondition> mBcs;
    ScalarFieldFp                              mCoeffs;

public:
    Laplacian01()          = default;
    virtual ~Laplacian01() = default;

    ///////////////////////////////////////////////////////////////////////////////////
    // Overridden methods from LaplacianOperator.
    //

    virtual std::string GetName() override;

    virtual LinearEqs Discretize(
        const ScalarFieldFp &varCellField, const ScalarFieldFp &varFaceField) override;

private:
};


}  // namespace OpenOasis::CommImp::Numeric::FVM