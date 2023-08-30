/** ***********************************************************************************
 *    Copyright (C) 2023, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  Grid2D.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Grid in 2d used for numerical calculation.
 *
 ** ***********************************************************************************/
#pragma once
#include "Grid.h"


namespace OpenOasis
{
namespace CommImpl
{
namespace Spatial
{
class Grid2D : public Grid
{
public:
    virtual ~Grid2D() = default;
    Grid2D(const std::string &meshDir);
    Grid2D(const std::shared_ptr<Grid> &grid);

    void RefineCell(int cellIndex) override;
    void RelaxCell(int cellIndex) override;

private:
    void CollectCellsInZone() override;
    void CalculateFaceNormal() override;
    void CalculateFaceArea() override;
    void CalculateFacePerimeter() override;
    void CalculateCellSurface() override;
    void CalculateCellVolume() override;
    void CheckMesh() const override;
};

}  // namespace Spatial
}  // namespace CommImpl
}  // namespace OpenOasis