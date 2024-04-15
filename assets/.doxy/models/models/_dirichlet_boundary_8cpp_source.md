

# File DirichletBoundary.cpp

[**File List**](files.md) **>** [**CommImp**](dir_6202b98a8704f42b1ea358646461643f.md) **>** [**Numeric**](dir_a0ece07902893bffce0f747cc8ee06c8.md) **>** [**DirichletBoundary.cpp**](_dirichlet_boundary_8cpp.md)

[Go to the documentation of this file](_dirichlet_boundary_8cpp.md)


```C++

#include "DirichletBoundary.h"


namespace OpenOasis::CommImp::Numeric
{
using namespace std;
using namespace Utils;

DirichletBoundary::DirichletBoundary()
{
    mData.type = "DIRICHLET";
}

DirichletBoundary::DirichletBoundary(real value)
{
    mData = {"DIRICHLET", value};
}

DirichletBoundary::DirichletBoundary(const DirichletBoundary &other)
{
    mData = other.mData;
}

void DirichletBoundary::SetBoundaryValue(real value)
{
    mData.value = value;
}

void DirichletBoundary::SetBoundaryFlux(real flux)
{
    mData.flux = flux;
}

string DirichletBoundary::GetType() const
{
    return "Dirichlet";
}

BoundaryCondition DirichletBoundary::GetBoundaryCondition()
{
    return mData;
}

}  // namespace OpenOasis::CommImp::Numeric
```


