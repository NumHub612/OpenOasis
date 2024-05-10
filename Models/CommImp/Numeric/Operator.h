/** ***********************************************************************************
 *    Copyright (C) 2023, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  Operator.h
 *    @License   :  Apache-2.0
 *
 ** ***********************************************************************************/
#pragma once
#include "Models/CommImp/Spatial/Grid.h"
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
using CommImp::Spatial::Grid;
using Utils::real;


/// @brief Linear equations consisting of coefficient matrix and source term vector.
using LinearEqs = std::tuple<Matrix<real>, std::vector<real>>;


/// @brief Operator Parameter.
struct OperatorParam
{
    std::string name;

    std::variant<std::string, real, int, bool> value;
};


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

    virtual void SetGrid(const std::shared_ptr<Grid> &grid) = 0;

    virtual void SetParameter(const OperatorParam &param) = 0;

    virtual std::string GetName() = 0;

    ///////////////////////////////////////////////////////////////////////////////////
    // Setting diffusion coefficients and boundary conditions.
    //

    virtual void SetBoundaryCondition(int meshIndex, const BoundaryCondition &bc) = 0;

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
    Discretize(const ScalarFieldFp &varCellField, const ScalarFieldFp &varFaceField)
    {
        throw std::runtime_error("Not implemented.");
    }

    virtual LinearEqs
    Discretize(const VectorFieldFp &varCellField, const VectorFieldFp &varFaceField)
    {
        throw std::runtime_error("Not implemented.");
    }

    virtual LinearEqs
    Discretize(const TensorFieldFp &varCellField, const TensorFieldFp &varFaceField)
    {
        throw std::runtime_error("Not implemented.");
    }
};

}  // namespace OpenOasis::CommImp::Numeric
