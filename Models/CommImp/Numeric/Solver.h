/** ***********************************************************************************
 *    Copyright (C) 2023, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  Solver.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Abstract solver class to provide unified interfaces.
 *    Solver's responsible for parsing the equation expression to be solved, and
 *    discretizing the equation items in the computational domain,
 *    combining them into a matrix, and
 *    solving it.
 *
 *    Solver is also responsible for initializing the relevant field quantities,
 *    and providing specific discrete and stepping scheme.
 *
 ** ***********************************************************************************/
#pragma once
#include "Boundary.h"
#include "Source.h"
#include "Operator.h"
#include "Matrix.h"
#include <optional>


namespace OpenOasis::CommImp::Numeric
{
using Utils::real;


enum class SolverStatus
{
    Created,
    Initialized,
    Parsed,
    Discretized,
    Updated,
    Solved,
    Failed
};

/// @brief Abstract solver class.
class Solver
{
public:
    ///////////////////////////////////////////////////////////////////////////////////
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

    ///////////////////////////////////////////////////////////////////////////////////
    // Equation parsing and discretizing.
    //

    virtual void ParseTimeDerivativeTerm()
    {
        throw std::runtime_error("Not implemented.");
    }

    virtual void ParseConvectionTerm()
    {
        throw std::runtime_error("Not implemented.");
    }

    virtual void ParseDiffusionTerm()
    {
        throw std::runtime_error("Not implemented.");
    }

    virtual void ParseSourceTerm()
    {
        throw std::runtime_error("Not implemented.");
    }

    ///////////////////////////////////////////////////////////////////////////////////
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

    ///////////////////////////////////////////////////////////////////////////////////
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

    ///////////////////////////////////////////////////////////////////////////////////
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