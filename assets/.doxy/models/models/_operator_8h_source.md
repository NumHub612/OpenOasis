

# File Operator.h

[**File List**](files.md) **>** [**CommImp**](dir_6202b98a8704f42b1ea358646461643f.md) **>** [**Numeric**](dir_a0ece07902893bffce0f747cc8ee06c8.md) **>** [**Operator.h**](_operator_8h.md)

[Go to the documentation of this file](_operator_8h.md)


```C++

#pragma once
#include "Models/Utils/CommConstants.h"
#include "Models/Utils/Exception.h"
#include "ScalarField.h"
#include "VectorField.h"
#include "TensorField.h"
#include "Boundary.h"
#include "Matrix.h"
#include <variant>
#include <tuple>
#include <optional>


namespace OpenOasis::CommImp::Numeric
{
using Utils::real;

using LinearEqs = std::tuple<Matrix<real>, std::vector<real>>;

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

    // Methods for setting boundary conditions.
    //

    virtual void SetBoundaryCondition(int faceIndex, const BoundaryCondition &boundary)
    {
        mboundaries[faceIndex] = boundary;
    }

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

}  // namespace OpenOasis::CommImp::Numeric
```


