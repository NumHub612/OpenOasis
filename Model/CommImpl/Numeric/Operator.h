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
/// @brief Linear equations consisting of coefficient matrix and source term vector.
using LinearEqs = std::tuple<Matrix<double>, std::vector<double>>;

/// @brief Abstract operator class.
/// @details Each numerical operator can discretize specific equation terms, or say
/// carry out specific operations on field quantities, and return corresponding
/// coefficient matrix and source term vector.
/// @todo Each operator can customize the algorithm and register automatically.
class Operator
{
protected:
    std::optional<std::variant<double, Vector<double>, Tensor<double>>> mCoefficient;

    std::optional<ScalarField<double>> mScalarCoeffs;
    std::optional<VectorField<double>> mVectorCoeffs;
    std::optional<TensorField<double>> mTensorCoeffs;

    std::unordered_map<int, BoundaryCondition> mboundaries;

public:
    virtual ~Operator() = default;

    ///////////////////////////////////////////////////////////////////////////////////
    // Methods for setting face coefficients.
    //

    virtual void
    SetCoefficient(const std::variant<double, Vector<double>, Tensor<double>> &coeff)
    {
        mCoefficient = coeff;
    }

    virtual void SetCoefficient(const ScalarField<double> &coefficients)
    {
        mScalarCoeffs = coefficients;
    }

    virtual void SetCoefficient(const VectorField<double> &coefficients)
    {
        mVectorCoeffs = coefficients;
    }

    virtual void SetCoefficient(const TensorField<double> &coefficients)
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
        const ScalarField<double> &phiCellField,
        const ScalarField<double> &phiFaceField)
    {
        throw Utils::NotImplementedException();
    }

    virtual LinearEqs Discretize(
        const VectorField<double> &phiCellField,
        const VectorField<double> &phiFaceField)
    {
        throw Utils::NotImplementedException();
    }

    virtual LinearEqs Discretize(
        const TensorField<double> &phiCellField,
        const TensorField<double> &phiFaceField)
    {
        throw Utils::NotImplementedException();
    }
};

}  // namespace OpenOasis::CommImpl::Numeric
