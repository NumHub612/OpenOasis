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
#include "Field.h"
#include "Boundary.h"
#include "Matrix.h"
#include <variant>
#include <tuple>
#include <optional>


namespace OpenOasis::CommImp::Numeric
{
using Utils::real;

/// @brief Linear equations consisting of coefficient matrix and source term vector.
using LinearEqs = std::tuple<Matrix<real>, std::vector<real>>;


/// @brief Abstract operator class.
/// @details Each numerical operator can discretize specific equation terms, or say
/// carry out specific operations on field quantities, and return corresponding
/// coefficient matrix and source term vector.
class Operator
{
public:
    ///////////////////////////////////////////////////////////////////////////////////
    // Methods for setting diffusion coefficients and boundary conditions.
    //

    virtual void SetBoundaryCondition(int faceIndex, const BoundaryCondition &bound)
    {
        throw std::runtime_error("Not implemented.");
    }

    virtual void SetCoefficient(const ScalarFieldFp &coefficients)
    {
        throw std::runtime_error("Not implemented.");
    }

    virtual void SetCoefficient(const VectorFieldFp &coefficients)
    {
        throw std::runtime_error("Not implemented.");
    }

    virtual void SetCoefficient(const TensorFieldFp &coefficients)
    {
        throw std::runtime_error("Not implemented.");
    }

    ///////////////////////////////////////////////////////////////////////////////////
    // Methods for discretizing.
    //

    virtual LinearEqs
    Discretize(const ScalarFieldFp &phiCellField, const ScalarFieldFp &phiFaceField)
    {
        throw std::runtime_error("Not implemented.");
    }

    virtual LinearEqs
    Discretize(const VectorFieldFp &phiCellField, const VectorFieldFp &phiFaceField)
    {
        throw std::runtime_error("Not implemented.");
    }

    virtual LinearEqs
    Discretize(const TensorFieldFp &phiCellField, const TensorFieldFp &phiFaceField)
    {
        throw std::runtime_error("Not implemented.");
    }
};


/// Commomly used operators.

using CurlOperator      = Operator;
using DivOperator       = Operator;
using GradOperator      = Operator;
using LaplacianOperator = Operator;
using DdtOperator       = Operator;

}  // namespace OpenOasis::CommImp::Numeric
