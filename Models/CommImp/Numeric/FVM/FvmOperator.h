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
private:
    std::unordered_map<int, BoundaryCondition> mBounds;
    ScalarFieldFp                              mCoeffs;
    Mesh                                       mMesh;

public:
    FvmOperator()          = default;
    virtual ~FvmOperator() = default;

    virtual void
    SetBoundaryCondition(int faceIndex, const BoundaryCondition &bc) override
    {
        mBounds[faceIndex] = bc;
    }

    virtual void SetParameter(const OperatorParam &param) override
    {}

    virtual void SetMesh(const Mesh &mesh) override
    {
        mMesh = mesh;
    }

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

class RegisterFactoryFvmOperator;
RegisterFactory(FvmOperator);


}  // namespace OpenOasis::CommImp::Numeric::FVM