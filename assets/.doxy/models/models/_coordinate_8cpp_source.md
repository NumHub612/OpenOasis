

# File Coordinate.cpp

[**File List**](files.md) **>** [**CommImp**](dir_6202b98a8704f42b1ea358646461643f.md) **>** [**Spatial**](dir_47a0bcc12c466f07097ed8db741700fa.md) **>** [**Coordinate.cpp**](_coordinate_8cpp.md)

[Go to the documentation of this file](_coordinate_8cpp.md)


```C++

#include "Coordinate.h"


namespace OpenOasis::CommImp::Spatial
{
using namespace Utils;
using namespace std;

bool Coordinate::Equals(real coorX, real coorY, real coorZ) const
{
    return Equals({coorX, coorY, coorZ});
}

bool Coordinate::Equals(const Coordinate &coor) const
{
    if (!IsEql(x, coor.x) || !IsEql(y, coor.y) || !IsEql(z, coor.z))
        return false;

    return true;
}

}  // namespace OpenOasis::CommImp::Spatial
```


