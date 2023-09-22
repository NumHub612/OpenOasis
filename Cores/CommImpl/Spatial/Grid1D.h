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
protected:
    class MeshReconfigurator
    {
    private:
        std::string mMeshDir;

        std::vector<Coordinate>                 mSectionLoc;
        std::vector<std::array<std::string, 2>> mReaches;

        std::unordered_map<std::string, std::string> mSectionShapeMap;
        std::unordered_map<std::string, std::vector<std::array<double, 2>>> mShapes;

    public:
        MeshReconfigurator(const std::string &meshDir);

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