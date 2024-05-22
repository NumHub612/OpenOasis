/** ***********************************************************************************
 *    Copyright (C) 2023, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  Operator.h
 *    @License   :  Apache-2.0
 *
 ** ***********************************************************************************/
#pragma once
#include "Models/Utils/CommConstants.h"
#include "Models/Utils/Exception.h"
#include "Configs.h"
#include "Matrix.h"
#include <tuple>


namespace OpenOasis::CommImp::Numeric
{
using Utils::real;
class Solver;


/// @brief Linear equations consisting of coefficient matrix and source term vector.
using LinearEqs = std::tuple<Matrix<real>, std::vector<real>>;

using OperatorParam = Configuration;


/// @brief Abstract operator class.
/// @details Each numerical operator can discretize specific equation terms, or say
/// carry out specific operations on field quantities, and return corresponding
/// coefficient matrix and source term vector.
class Operator
{
public:
    ///////////////////////////////////////////////////////////////////////////////////
    // Methods for operator parameters setting.
    //

    virtual void SetSolver(const std::shared_ptr<Solver> &solver) = 0;

    virtual void SetParameter(const OperatorParam &param) = 0;

    virtual std::string GetName() = 0;

    ///////////////////////////////////////////////////////////////////////////////////
    // Methods for discretizing.
    //

    virtual LinearEqs Discretize() = 0;
};

}  // namespace OpenOasis::CommImp::Numeric
