/** ***********************************************************************************
 *    Copyright (C) 2023, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  Solver.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Abstract solver class to provide unified interfaces.
 *    A solver is responsible for parsing the equation expression to be solved, and
 *    discretizing the equation items in the computational domain,
 *    combining them into a matrix, and
 *    solving it.
 *
 *    The solver is also responsible for initializing the relevant field quantities,
 *    and providing specific discrete and stepping scheme.
 *
 ** ***********************************************************************************/
#pragma once
#include "Boundary.h"
#include "Source.h"
#include "Operator.h"


namespace OpenOasis::CommImpl::Numeric
{
/// @brief Abstract solver class.
/// @todo Each solver can customize the algorithm and register automatically.
/// @todo Each step of the solver calculation can be debugged.
class Solver
{
public:
    ///////////////////////////////////////////////////////////////////////////////////
    // Configuration setting.
    //

    virtual void SetBoundary(int faceIndex, const std::shared_ptr<Boundary> &bound) = 0;

    virtual void SetInitialValue(
        const std::string                                          &var,
        const std::variant<double, Vector<double>, Tensor<double>> &value) = 0;

    // virtual void
    // SetInitialValue(const std::string &var, const ScalarField<double> &values);

    // virtual void
    // SetInitialValue(const std::string &var, const VectorField<double> &values);

    // virtual void
    // SetInitialValue(const std::string &var, const TensorField<double> &values);

    virtual void SetCoefficient(
        const std::string                                          &var,
        const std::variant<double, Vector<double>, Tensor<double>> &coeff) = 0;

    // virtual void
    // SetCoefficient(const std::string &var, const ScalarField<double> &coefficients);

    // virtual void
    // SetCoefficient(const std::string &var, const VectorField<double> &coefficients);

    // virtual void
    // SetCoefficient(const std::string &var, const TensorField<double> &coefficients);

    // virtual void Reset();

    ///////////////////////////////////////////////////////////////////////////////////
    // Equation discretizing.
    //

    virtual void ParseTimeDerivativeTerm() = 0;
    virtual void ParseConvectiveTerm()     = 0;
    virtual void ParseDiffusionTerm()      = 0;
    virtual void ParseSourceTerm()         = 0;

    ///////////////////////////////////////////////////////////////////////////////////
    // Step advancing.
    //

    virtual void BeforeScheme() = 0;
    virtual void Scheme()       = 0;
    virtual void AfterScheme()  = 0;

    ///////////////////////////////////////////////////////////////////////////////////
    // Matrix solving.
    //

    virtual void BeforeSolve() = 0;
    virtual void Solve()       = 0;
    virtual void AfterSolve()  = 0;

    virtual ScalarField<double> GetScalarSolutions() const = 0;
};

}  // namespace OpenOasis::CommImpl::Numeric