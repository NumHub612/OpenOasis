/** ***********************************************************************************
 *    Copyright (C) 2023, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  Grid3D.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Grid in 3d used for numerical calculation.
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
class Grid3D : public Grid
{
public:
    virtual ~Grid3D() = default;
    Grid3D(const std::string &meshDir);
    Grid3D(const std::shared_ptr<Grid> &grid);

    int  GridType() const override;
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