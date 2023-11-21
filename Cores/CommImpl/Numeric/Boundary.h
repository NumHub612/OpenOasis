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
#include <string>
#include <cmath>


namespace OpenOasis::CommImpl::Numeric
{
/// @brief Boundary condition struct.
struct BoundaryCondition
{
    std::string type;

    double value = NAN;
    double flux  = NAN;
};

/// @brief Abstract boundary class.
class Boundary
{
public:
    virtual void SetBoundaryValue(double value) = 0;

    virtual void SetBoundaryFlux(double flux) = 0;

    virtual std::string GetType() const = 0;

    virtual BoundaryCondition GetBoundaryCondition() = 0;
};

}  // namespace OpenOasis::CommImpl::Numeric
