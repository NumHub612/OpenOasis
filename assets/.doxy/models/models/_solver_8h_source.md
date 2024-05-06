

# File Solver.h

[**File List**](files.md) **>** [**CommImp**](dir_6202b98a8704f42b1ea358646461643f.md) **>** [**Numeric**](dir_a0ece07902893bffce0f747cc8ee06c8.md) **>** [**Solver.h**](_solver_8h.md)

[Go to the documentation of this file](_solver_8h.md)


```C++

#pragma once
#include "Boundary.h"
#include "Source.h"
#include "Operator.h"
#include "Matrix.h"
#include <optional>


namespace OpenOasis::CommImp::Numeric
{
using Utils::real;


class Solver
{
public:
    // Configuration and initialization.
    //

    virtual void SetBoundary(int faceIndex, const std::shared_ptr<Boundary> &bound)
    {
        throw std::runtime_error("Not implemented.");
    }

    virtual void SetInitialValue(
        const std::string                                    &var,
        const std::variant<real, Vector<real>, Tensor<real>> &value)
    {
        throw std::runtime_error("Not implemented.");
    }

    virtual void SetInitialValue(const std::string &var, const ScalarFieldFp &values)
    {
        throw std::runtime_error("Not implemented.");
    }

    virtual void SetInitialValue(const std::string &var, const VectorFieldFp &values)
    {
        throw std::runtime_error("Not implemented.");
    }

    virtual void SetInitialValue(const std::string &var, const TensorFieldFp &values)
    {
        throw std::runtime_error("Not implemented.");
    }

    virtual void SetCoefficient(
        const std::string                                    &var,
        const std::variant<real, Vector<real>, Tensor<real>> &coeff)
    {
        throw std::runtime_error("Not implemented.");
    }

    virtual void SetCoefficient(const std::string &var, const ScalarFieldFp &coeffs)
    {
        throw std::runtime_error("Not implemented.");
    }

    virtual void SetCoefficient(const std::string &var, const VectorFieldFp &coeffs)
    {
        throw std::runtime_error("Not implemented.");
    }

    virtual void SetCoefficient(const std::string &var, const TensorFieldFp &coeffs)
    {
        throw std::runtime_error("Not implemented.");
    }

    // Equation parsing and discretizing.
    //

    virtual void DiscretizeEquation()
    {
        throw std::runtime_error("Not implemented.");
    }

    // Step advancing.
    //

    virtual void BeforeScheme()
    {
        throw std::runtime_error("Not implemented.");
    }

    virtual void Scheme()
    {
        throw std::runtime_error("Not implemented.");
    }

    virtual void AfterScheme()
    {
        throw std::runtime_error("Not implemented.");
    }

    // Matrix solving.
    //

    virtual void BeforeSolve()
    {
        throw std::runtime_error("Not implemented.");
    }

    virtual void Solve()

    {
        throw std::runtime_error("Not implemented.");
    }

    virtual void AfterSolve()
    {
        throw std::runtime_error("Not implemented.");
    }

    // Solution access.
    //

    std::optional<LinearEqs> GetLinearEqs() const
    {
        throw std::runtime_error("Not implemented.");
    }

    virtual std::optional<ScalarFieldFp>
    GetScalarSolutions(const std::string &var) const
    {
        throw std::runtime_error("Not implemented.");
    }

    virtual std::optional<VectorFieldFp>
    GetVectorSolutions(const std::string &var) const
    {
        throw std::runtime_error("Not implemented.");
    }

    virtual std::optional<TensorFieldFp>
    GetTensorSolutions(const std::string &var) const
    {
        throw std::runtime_error("Not implemented.");
    }
};

}  // namespace OpenOasis::CommImp::Numeric
```


