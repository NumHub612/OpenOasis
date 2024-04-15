

# File Grid1D.h

[**File List**](files.md) **>** [**CommImp**](dir_6202b98a8704f42b1ea358646461643f.md) **>** [**Spatial**](dir_47a0bcc12c466f07097ed8db741700fa.md) **>** [**Grid1D.h**](_grid1_d_8h.md)

[Go to the documentation of this file](_grid1_d_8h.md)


```C++

#pragma once
#include "Grid.h"


namespace OpenOasis
{
namespace CommImp
{
namespace Spatial
{


class Grid1D : public Grid
{
public:
    virtual ~Grid1D() = default;
    Grid1D(const std::shared_ptr<Grid> &grid);
    Grid1D(
        std::unordered_map<int, Coordinate>               &nodeCoords,
        std::unordered_map<int, Coordinate>               &faceCoords,
        std::unordered_map<int, Coordinate>               &cellCoords,
        std::unordered_map<int, std::vector<int>>         &faceNodes,
        std::unordered_map<int, std::vector<int>>         &cellFaces,
        std::unordered_map<std::string, std::vector<int>> &patches,
        std::unordered_map<std::string, std::vector<int>> &zones);

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
```


