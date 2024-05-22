/** ***********************************************************************************
 *    Copyright (C) 2023, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  Solver.h
 *    @License   :  Apache-2.0
 *
 ** ***********************************************************************************/
#pragma once
#include "Models/CommImp/Spatial/Grid.h"
#include "Equation.h"
#include "Operator.h"
#include "Boundary.h"


namespace OpenOasis::CommImp::Numeric
{
using CommImp::Spatial::Grid;
using Utils::real;


using SolverParam = Configuration;
using TaskOption  = Configuration;


/// @brief Abstract solver class.
/// @details Each solver implementes an algorithm to complete the solution of the
/// equation. The solver is responsible for parsing the equation expression to be
/// solved, and discretizing the equation items in the computational domain,
/// combining them into a matrix, and solving it.
///
/// The solver is also responsible for initializing the relevant field quantities,
/// and providing specific discrete and stepping scheme.
///
/// The solver doesn't responsible for any IO operations, but provides a way to
/// access the solution field quantities.
class Solver
{
public:
    ///////////////////////////////////////////////////////////////////////////////////
    // Parameter setting and Configuration.
    //

    virtual void AddParameter(const SolverParam &param) = 0;

    virtual bool HasParameter(const std::string &id) const = 0;

    virtual const SolverParam &GetParameter(const std::string &id) const = 0;

    virtual void AddOption(const TaskOption &option) = 0;

    virtual bool HasOption(const std::string &id) const = 0;

    virtual const TaskOption &GetOption(const std::string &id) const = 0;

    virtual void SetGrid(const std::shared_ptr<Grid> &grid) = 0;

    virtual const std::shared_ptr<Grid> &GetGrid() const = 0;

    virtual std::string GetName() = 0;

    ///////////////////////////////////////////////////////////////////////////////////
    // Boundary condition and initialization.
    //

    virtual void AddBoundary(int meshIndex, const std::shared_ptr<Boundary> &bound) = 0;

    virtual void SetInitialValue(const DataField &varField) = 0;

    virtual void SetCoefficient(const DataField &coefField) = 0;

    ///////////////////////////////////////////////////////////////////////////////////
    // Equation parsing and step advancing.
    //

    virtual void AddEquation(const std::shared_ptr<Equation> &eq) = 0;

    virtual void Parse() = 0;

    virtual void Initialize() = 0;

    virtual real GetSimulatedTime() const = 0;

    virtual real GetTimeStep() const = 0;

    virtual void Step(real dt) = 0;

    ///////////////////////////////////////////////////////////////////////////////////
    // Solution access.
    //

    virtual std::vector<std::string> GetVariables() const = 0;

    virtual std::optional<LinearEqs> GetLinearEqs() const = 0;

    virtual std::optional<DataField> GetSolutions(const std::string &var) const = 0;
};

}  // namespace OpenOasis::CommImp::Numeric