/** ***********************************************************************************
 *    Copyright (C) 2023, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  Grid1D.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Grid in river net used for numerical calculation.
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


class Grid1D : public Grid
{
public:
    virtual ~Grid1D() = default;
    Grid1D(const std::string &meshDir);
    Grid1D(const std::shared_ptr<Grid> &grid);

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

protected:
    class RiverNetConverter
    {
    private:
        std::string mMeshDir;

        std::vector<Coordinate>                 mSectionLoc;
        std::vector<std::array<std::string, 2>> mReaches;

        std::unordered_map<std::string, std::string> mSectionShapeMap;
        std::unordered_map<std::string, std::vector<std::array<double, 2>>> mShapes;

    public:
        RiverNetConverter(const std::string &meshDir);

        friend class Grid1D;

        void LoadSectionLocations(const std::string &file = "sections.csv");
        void LoadShapes(const std::string &file = "shapes.csv");
        void LoadReaches(const std::string &file = "reaches.csv");
        void LoadSectionShapes(const std::string &file = "section_shapes.csv");

        std::vector<Node> GenerateNodes();
        std::vector<Face> GenerateFaces();
        std::vector<Cell> GenerateCells();
    };
};

}  // namespace Spatial
}  // namespace CommImpl
}  // namespace OpenOasis