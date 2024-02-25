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


namespace OpenOasis::CommImp::Numeric
{
using Utils::real;

/// @brief Boundary condition struct.
struct BoundaryCondition
{
    std::string type;

    real value = NAN;
    real flux  = NAN;
};

/// @brief Abstract boundary class.
class Boundary
{
public:
    virtual void SetBoundaryValue(real value) = 0;

    virtual void SetBoundaryFlux(real flux) = 0;

    virtual std::string GetType() const = 0;

    virtual BoundaryCondition GetBoundaryCondition() = 0;
};

}  // namespace OpenOasis::CommImp::Numeric
