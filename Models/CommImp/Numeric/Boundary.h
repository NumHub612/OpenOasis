/** ***********************************************************************************
 *    Copyright (C) 2023, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  Boundary.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Abstract boundary class.
 *
 ** ***********************************************************************************/
#pragma once
#include "Models/Utils/CommConstants.h"
#include <string>
#include <cmath>
#include <optional>


namespace OpenOasis::CommImp::Numeric
{
using Utils::real;


/// @brief Boundary type enum.
enum class BoundaryType
{
    ValueBound,  // Dirichlet or first boundary condition.
    FluxBound,   // Neumann or second boundary condition.
    MixedBound,  // Robin boundary condition.
};

/// @brief Boundary condition struct.
struct BoundaryCondition
{
    BoundaryType type;

    std::optional<real> value;
    std::optional<real> flux;
};

/// @brief Abstract boundary class.
class Boundary
{
public:
    virtual void SetBoundaryCondition(const BoundaryCondition &bc) = 0;

    virtual BoundaryCondition GetBoundaryCondition() = 0;
};


// Commonly used boundaries.

using DirichletBoundary = Boundary;
using NeumannBoundary   = Boundary;
using RobinBoundary     = Boundary;


}  // namespace OpenOasis::CommImp::Numeric
