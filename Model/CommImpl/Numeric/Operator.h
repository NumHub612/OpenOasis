/** ***********************************************************************************
 *    Copyright (C) 2023, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  Operator.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Abstract operator class.
 *
 ** ***********************************************************************************/
#pragma once
#include "Model/Utils/CommConstants.h"
#include "Model/Utils/Exception.h"
#include "ScalarField.h"
#include "VectorField.h"
#include "TensorField.h"
#include "Boundary.h"
#include "Matrix.h"
#include <variant>
#include <tuple>
#include <optional>


namespace OpenOasis::CommImpl::Numeric
{
using Utils::real;

/// @brief Linear equations consisting of coefficient matrix and source term vector.
using LinearEqs = std::tuple<Matrix<real>, std::vector<real>>;

/// @brief Abstract operator class.
/// @details Each numerical operator can discretize specific equation terms, or say
/// carry out specific operations on field quantities, and return corresponding
/// coefficient matrix and source term vector.
/// @todo Each operator can customize the algorithm and register automatically.
class Operator
{
protected:
    std::optional<std::variant<real, Vector<real>, Tensor<real>>> mCoefficient;

    std::optional<ScalarField<real>> mScalarCoeffs;
    std::optional<VectorField<real>> mVectorCoeffs;
    std::optional<TensorField<real>> mTensorCoeffs;

    std::unordered_map<int, BoundaryCondition> mboundaries;

public:
    virtual ~Operator() = default;

    ///////////////////////////////////////////////////////////////////////////////////
    // Methods for setting face coefficients.
    //

    virtual void
    SetCoefficient(const std::variant<real, Vector<real>, Tensor<real>> &coeff)
    {
        mCoefficient = coeff;
    }

    virtual void SetCoefficient(const ScalarField<real> &coefficients)
    {
        mScalarCoeffs = coefficients;
    }

    virtual void SetCoefficient(const VectorField<real> &coefficients)
    {
        mVectorCoeffs = coefficients;
    }

    virtual void SetCoefficient(const TensorField<real> &coefficients)
    {
        mTensorCoeffs = coefficients;
    }

    ///////////////////////////////////////////////////////////////////////////////////
    // Methods for setting boundary conditions.
    //

    virtual void SetBoundaryCondition(int faceIndex, const BoundaryCondition &boundary)
    {
        mboundaries[faceIndex] = boundary;
    }

    ///////////////////////////////////////////////////////////////////////////////////
    // Methods for discretizing field.
    //

    virtual LinearEqs Discretize(
        const ScalarField<real> &phiCellField, const ScalarField<real> &phiFaceField)
    {
        throw Utils::NotImplementedException();
    }

    virtual LinearEqs Discretize(
        const VectorField<real> &phiCellField, const VectorField<real> &phiFaceField)
    {
        throw Utils::NotImplementedException();
    }

    virtual LinearEqs Discretize(
        const TensorField<real> &phiCellField, const TensorField<real> &phiFaceField)
    {
        throw Utils::NotImplementedException();
    }
};

}  // namespace OpenOasis::CommImpl::Numeric
