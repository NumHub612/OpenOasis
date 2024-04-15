

# File LaplacianOperator.h

[**File List**](files.md) **>** [**CommImp**](dir_6202b98a8704f42b1ea358646461643f.md) **>** [**Numeric**](dir_a0ece07902893bffce0f747cc8ee06c8.md) **>** [**LaplacianOperator.h**](_laplacian_operator_8h.md)

[Go to the documentation of this file](_laplacian_operator_8h.md)


```C++

#pragma once
#include "Models/CommImp/Spatial/Grid.h"
#include "Operator.h"
#include <functional>
#include <memory>


namespace OpenOasis::CommImp::Numeric
{
using Spatial::Grid;
using Utils::real;

class Laplacian : public Operator
{
private:
    std::shared_ptr<Grid> mGrid;

public:
    virtual ~Laplacian() = default;

    Laplacian(const std::shared_ptr<Grid> &grid) : mGrid(grid)
    {}

    // Laplacian(
    //     const std::shared_ptr<Grid>     &grid,
    //     const std::function<void(void)> &innerFluxFunc,
    //     const std::function<void(void)> &boundFluxFunc);

    LinearEqs Discretize(
        const ScalarField<real> &phiCellField,
        const ScalarField<real> &phiFaceField) override;
};


}  // namespace OpenOasis::CommImp::Numeric
```


