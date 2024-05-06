

# File DirichletBoundary.h

[**File List**](files.md) **>** [**CommImp**](dir_6202b98a8704f42b1ea358646461643f.md) **>** [**Numeric**](dir_a0ece07902893bffce0f747cc8ee06c8.md) **>** [**FVM**](dir_ce9212301f8d93e5246dd812df0f37fe.md) **>** [**DirichletBoundary.h**](_dirichlet_boundary_8h.md)

[Go to the documentation of this file](_dirichlet_boundary_8h.md)


```C++

#pragma once
#include "Models/CommImp/Numeric/Boundary.h"


namespace OpenOasis::CommImp::Numeric::FVM
{
using Utils::real;

class DirichletBoundary : public Boundary
{
private:
    BoundaryCondition mData;

public:
    DirichletBoundary();
    DirichletBoundary(real value);
    DirichletBoundary(const DirichletBoundary &other);

    void SetBoundaryValue(real value) override;

    void SetBoundaryFlux(real flux) override;

    std::string GetType() const override;

    BoundaryCondition GetBoundaryCondition() override;
};

}  // namespace OpenOasis::CommImp::Numeric::FVM
```


