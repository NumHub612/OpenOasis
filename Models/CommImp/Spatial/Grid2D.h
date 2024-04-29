/** ***********************************************************************************
 *    Copyright (C) 2023, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  Grid2D.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Grid formed by flat cells in 2d used for numerical calculation.
 *
 ** ***********************************************************************************/
#pragma once
#include "Grid.h"


namespace OpenOasis
{
namespace CommImp
{
namespace Spatial
{
/// @brief Grid formed by flat cells in 2d.
class Grid2D : public Grid
{
public:
    virtual ~Grid2D() = default;
    Grid2D(const std::shared_ptr<Grid> &grid);
    Grid2D(
        std::unordered_map<int, Coordinate>               &nodeCoords,
        std::unordered_map<int, Coordinate>               &faceCoords,
        std::unordered_map<int, Coordinate>               &cellCoords,
        std::unordered_map<int, std::vector<int>>         &faceNodes,
        std::unordered_map<int, std::vector<int>>         &cellFaces,
        std::unordered_map<std::string, std::vector<int>> &patches,
        std::unordered_map<std::string, std::vector<int>> &zones);

    int  Version() const override;
    int  Type() const override;
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
}  // namespace CommImp
}  // namespace OpenOasis