

# File Boundary.h

[**File List**](files.md) **>** [**CommImp**](dir_6202b98a8704f42b1ea358646461643f.md) **>** [**Numeric**](dir_a0ece07902893bffce0f747cc8ee06c8.md) **>** [**Boundary.h**](_boundary_8h.md)

[Go to the documentation of this file](_boundary_8h.md)


```C++

#pragma once
#include "Models/Utils/CommConstants.h"
#include <string>
#include <cmath>


namespace OpenOasis::CommImp::Numeric
{
using Utils::real;

struct BoundaryCondition
{
    std::string type;

    real value = NAN;
    real flux  = NAN;
};

class Boundary
{
public:
    virtual void SetBoundaryValue(real value) = 0;

    virtual void SetBoundaryFlux(real flux) = 0;

    virtual std::string GetType() const = 0;

    virtual BoundaryCondition GetBoundaryCondition() = 0;
};

}  // namespace OpenOasis::CommImp::Numeric
```


