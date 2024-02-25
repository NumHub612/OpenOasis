/** ***********************************************************************************
 *    Copyright (C) 2023, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  LaplacianOperator.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Laplacian Operator.
 *
 ** ***********************************************************************************/
#pragma once
#include "Models/CommImp/Spatial/Grid.h"
#include "Operator.h"
#include <functional>
#include <memory>


namespace OpenOasis::CommImp::Numeric
{
using Spatial::Grid;
using Utils::real;

/// @brief Laplacian operator for the divergence of the gradient of a scalar field.
/// @details First, calculate the gradient of the scalar field. Then, calculate
/// the divergence of the gradient.
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