

# File Coordinate.h

[**File List**](files.md) **>** [**CommImp**](dir_6202b98a8704f42b1ea358646461643f.md) **>** [**Spatial**](dir_47a0bcc12c466f07097ed8db741700fa.md) **>** [**Coordinate.h**](_coordinate_8h.md)

[Go to the documentation of this file](_coordinate_8h.md)


```C++

#pragma once
#include "Models/Utils/CommConstants.h"


namespace OpenOasis::CommImp::Spatial
{
using Utils::real;

struct Coordinate
{
    real x = 0.;
    real y = 0.;
    real z = 0.;

    bool Equals(real coorX, real coorY, real coorZ) const;
    bool Equals(const Coordinate &coor) const;
};

}  // namespace OpenOasis::CommImp::Spatial
```


