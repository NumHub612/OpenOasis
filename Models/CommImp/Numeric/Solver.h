/** ***********************************************************************************
 *    Copyright (C) 2023, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  Solver.h
 *    @License   :  Apache-2.0
 *
 ** ***********************************************************************************/
#pragma once
#include "Models/CommImp/Spatial/Grid.h"
#include "Boundary.h"
#include "Source.h"
#include "Operator.h"
#include "Matrix.h"
#include <optional>


namespace OpenOasis::CommImp::Numeric
{
using CommImp::Spatial::Grid;
using Utils::real;


/// @brief Solver parameter.
struct SolverParam
{
    std::string name;

    std::variant<std::string, real, int, bool> value;
};


/// @brief Field binding variable.
struct VariableField
{
    std::string var;

    std::optional<ScalarFieldFp> field;
    std::optional<VectorFieldFp> field;
    std::optional<TensorFieldFp> field;
};


/// @brief Abstract solver class.
/// @details Each solver implementes an algorithm to complete the solution of the
/// equation. The solver is responsible for parsing the equation expression to be
/// solved, and discretizing the equation items in the computational domain,
/// combining them into a matrix, and solving it.
///
/// The solver is also responsible for initializing the relevant field quantities,
/// and providing specific discrete and stepping scheme.
class Solver
{
public:
    ///////////////////////////////////////////////////////////////////////////////////
    // Parameter setting and Configuration.
    //

    virtual void SetGrid(const std::shared_ptr<Grid> &grid) = 0;

    virtual void SetParameter(const SolverParam &param) = 0;

    virtual std::string GetName() = 0;

    ///////////////////////////////////////////////////////////////////////////////////
    // Boundary condition and initialization.
    //

    virtual void SetBoundary(int faceIndex, const std::shared_ptr<Boundary> &boundary)
    {
        throw std::runtime_error("Not implemented.");
    }

    virtual void SetInitialValue(const VariableField &varField)
    {
        throw std::runtime_error("Not implemented.");
    }

    virtual void SetCoefficient(const VariableField &coefField)
    {
        throw std::runtime_error("Not implemented.");
    }

    ///////////////////////////////////////////////////////////////////////////////////
    // Equation parsing and discretizing.
    //

    virtual void
    SetOperator(const std::string &eqItem, const std::shared_ptr<Operator> &op)
    {
        throw std::runtime_error("Not implemented.");
    }

    virtual void Discretize()
    {
        throw std::runtime_error("Not implemented.");
    }

    ///////////////////////////////////////////////////////////////////////////////////
    // Step advancing.
    //

    virtual void BeforeScheme()
    {}

    virtual void Scheme()
    {
        throw std::runtime_error("Not implemented.");
    }

    virtual void AfterScheme()
    {}

    ///////////////////////////////////////////////////////////////////////////////////
    // Matrix solving.
    //

    virtual void BeforeSolve()
    {}

    virtual void Solve()
    {
        throw std::runtime_error("Not implemented.");
    }

    virtual void AfterSolve()
    {}

    ///////////////////////////////////////////////////////////////////////////////////
    // Solution access.
    //

    virtual std::optional<LinearEqs> GetLinearEqs() const
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