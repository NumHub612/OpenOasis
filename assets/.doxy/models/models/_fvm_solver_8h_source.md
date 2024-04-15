

# File FvmSolver.h

[**File List**](files.md) **>** [**CommImp**](dir_6202b98a8704f42b1ea358646461643f.md) **>** [**Numeric**](dir_a0ece07902893bffce0f747cc8ee06c8.md) **>** [**FVM**](dir_ce9212301f8d93e5246dd812df0f37fe.md) **>** [**FvmSolver.h**](_fvm_solver_8h.md)

[Go to the documentation of this file](_fvm_solver_8h.md)


```C++

#pragma once
#include "Models/CommImp/Numeric/Solver.h"
#include "Models/CommImp/Numeric/Matrix.h"
#include "Models/CommImp/Spatial/Grid.h"


namespace OpenOasis::CommImp::Numeric::FVM
{
using Spatial::Grid;
using Utils::real;

class FvmSolver : public Solver
{
private:
    std::shared_ptr<Grid> mGrid;
    Matrix<real>          mCoeffMat;
    std::vector<real>     mRhs;

    std::unordered_map<int, std::shared_ptr<Boundary>> mBoundaries;

    real mCoeffHeat;
    real mInitValue;

    ScalarFieldFp mTemps;

public:
    ~FvmSolver() = default;
    FvmSolver(const std::shared_ptr<Grid> &grid);

    void SetBoundary(int faceIndex, const std::shared_ptr<Boundary> &bound) override;
    void SetInitialValue(
        const std::string                                    &var,
        const std::variant<real, Vector<real>, Tensor<real>> &value) override;
    void SetCoefficient(
        const std::string                                    &var,
        const std::variant<real, Vector<real>, Tensor<real>> &coeff) override;

    void ParseDiffusionTerm() override;

    void Solve() override;

    std::optional<ScalarFieldFp>
    GetScalarSolutions(const std::string &var) const override;
};

}  // namespace OpenOasis::CommImp::Numeric::FVM
```


