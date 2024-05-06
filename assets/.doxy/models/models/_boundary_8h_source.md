

# File Boundary.h

[**File List**](files.md) **>** [**CommImp**](dir_6202b98a8704f42b1ea358646461643f.md) **>** [**Numeric**](dir_a0ece07902893bffce0f747cc8ee06c8.md) **>** [**Boundary.h**](_boundary_8h.md)

[Go to the documentation of this file](_boundary_8h.md)


```C++

#pragma once
#include "Models/Utils/CommConstants.h"
#include <string>
#include <cmath>
#include <optional>


namespace OpenOasis::CommImp::Numeric
{
using Utils::real;


enum class BoundaryType
{
    ValueBound,  // Dirichlet or first boundary condition.
    FluxBound,   // Neumann or second boundary condition.
    MixedBound,  // Robin boundary condition.
};

struct BoundaryCondition
{
    BoundaryType type;

    std::optional<real> value;
    std::optional<real> flux;
};

class Boundary
{
public:
    virtual void AddBoundaryCondition(double time, const BoundaryCondition &bc) = 0;

    virtual BoundaryCondition GetBoundaryCondition(double time) = 0;
};


// Commonly used boundaries.

using DirichletBoundary = Boundary;
using NeumannBoundary   = Boundary;
using RobinBoundary     = Boundary;


}  // namespace OpenOasis::CommImp::Numeric
```


