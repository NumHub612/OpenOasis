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
#include "FvmSolver.h"
#include <algorithm>


namespace OpenOasis::CommImp::Numeric::FVM
{
using namespace OpenOasis::Utils;


/// @brief FVM operator base class.
class FvmOperator : public Operator
{
protected:
    std::vector<OperatorParam> mParams;
    std::shared_ptr<FvmSolver> mSolver;

public:
    FvmOperator()          = default;
    virtual ~FvmOperator() = default;

    virtual void SetSolver(const std::shared_ptr<Solver> &solver) override
    {
        mSolver = std::dynamic_pointer_cast<FvmSolver>(solver);
        if (!mSolver)
        {
            throw std::runtime_error("FvmOperator::SetSolver: Invalid solver type.");
        }
    }

    virtual void SetParameter(const OperatorParam &param) override
    {
        if (std::find_if(
                mParams.begin(),
                mParams.end(),
                [&param](const OperatorParam &p) { return p.key == param.key; })
            == mParams.end())
            mParams.push_back(param);
    }
};


// Commomly used operators.

using CurlOperator      = FvmOperator;
using DivOperator       = FvmOperator;
using GradOperator      = FvmOperator;
using LaplacianOperator = FvmOperator;
using DdtOperator       = FvmOperator;
using D2dt2Operator     = FvmOperator;
using SuOperator        = FvmOperator;
using SpOperator        = FvmOperator;


// Register FVM operator factory.

class FvmOperatorRegister;
RegisterFactory(FvmOperator);


}  // namespace OpenOasis::CommImp::Numeric::FVM