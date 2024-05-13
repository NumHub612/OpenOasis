/** ***********************************************************************************
 *    Copyright (C) 2024, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  FvmOperator.h
 *    @License   :  Apache-2.0
 *
 ** ***********************************************************************************/
#pragma once
#include "Models/CommImp/Numeric/Operator.h"
#include "Models/Utils/RegisterFactory.h"


namespace OpenOasis::CommImp::Numeric::FVM
{
using namespace OpenOasis::Utils;


/// @brief FVM operator base class.
class FvmOperator : public Operator
{
protected:
    std::unordered_map<int, BoundaryCondition> mBounds;
    ScalarFieldFp                              mCoeffs;
    std::shared_ptr<Grid>                      mGrid;

public:
    FvmOperator()          = default;
    virtual ~FvmOperator() = default;

    virtual void
    SetBoundaryCondition(int faceIndex, const BoundaryCondition &bc) override
    {
        mBounds[faceIndex] = bc;
    }

    virtual void SetGrid(const std::shared_ptr<Grid> &grid) override
    {
        mGrid = grid;
    }

    virtual void SetParameter(const OperatorParam &param) override
    {}

    virtual void SetCoefficient(const ScalarFieldFp &coefficients) override
    {
        mCoeffs = coefficients;
    }
};


// Commomly used operators.

using CurlOperator      = FvmOperator;
using DivOperator       = FvmOperator;
using GradOperator      = FvmOperator;
using LaplacianOperator = FvmOperator;
using DdtOperator       = FvmOperator;


// Register FVM operator factory.

class FvmOperatorRegister;
RegisterFactory(FvmOperator);


}  // namespace OpenOasis::CommImp::Numeric::FVM