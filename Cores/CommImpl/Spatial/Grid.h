/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  Grid.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Grid used for numerical calculation.
 *
 ** ***********************************************************************************/
#pragma once
#include "MeshStructs.h"
#include <string>


namespace OpenOasis
{
namespace CommImpl
{
namespace Spatial
{
/// @brief Grid encapsulate the mesh data for numerical calculation.
class Grid
{
private:
    Mesh mMesh;

    // The number of original objects in the mesh before
    // refining or coarsening.
    int mRawNodesNum;
    int mRawFacesNum;
    int mRawCellsNum;

    // The outer or inner boundary patches, each of them
    // is arranged by Node indexes.
    std::unordered_map<std::string, std::vector<int>> mPatches;

    // The zone arranged byg Face indexes.
    std::unordered_map<std::string, std::vector<int>> mZones;

public:
    virtual ~Grid() = default;
    Grid(const std::string &meshDir);
    Grid(const Grid &grid);

    ///////////////////////////////////////////////////////////////////////////////////
    // Methods used for mesh operations.
    //

    /// @brief Activate the mesh to extract topological information needed for various
    /// numerical calculations.
    void Activate();

    /// @brief Refine the cell at the given index for adaptive grid.
    /// @note  The refining wouldn't change the origin nodes.
    void RefineCell(int cellIndex);

    /// @brief Coarsen the cell at the given index for adaptive grid.
    /// @note  The coarsening wouldn't change the origin nodes.
    void CoarsenCell(int cellIndex);

    ///////////////////////////////////////////////////////////////////////////////////
    // Methods used for mesh query.
    //

    int GetNumCells() const;
    int GetNumFaces() const;
    int GetNumNodes() const;

    const Cell &GetCell(int cellIndex) const;
    const Face &GetFace(int faceIndex) const;
    const Node &GetNode(int nodeIndex) const;

    std::vector<int> GetZoneCellIndexes(const std::string &zoneId) const;
    std::vector<int> GetPatchFaceIndexes(const std::string &patchId) const;

private:
    void CalculateFaceCentroid();
    void CalculateFaceNormal();
    void CalculateFaceArea();
    void CalculateFacePerimeter();

    void CalculateCellCentroid();
    void CalculateCellSurface();
    void CalculateCellVolume();

    void CollectCellsSharedNode();
    void CollectFacesSharedNode();
    void CollectCellNeighbors();

    bool CheckMeshValid() const;

private:
    /// @brief Helper class to load mesh data from csv files.
    class MeshLoader
    {
    private:
        std::string       mMeshDir;
        std::vector<Node> mNodes;
        std::vector<Face> mFaces;
        std::vector<Cell> mCells;

    public:
        MeshLoader(const std::string &meshDir);

        friend class Grid;

        void LoadNodes(const std::string &file = "nodes.csv");
        void LoadFaces(const std::string &file = "faces.csv");
        void LoadCells(const std::string &file = "cells.csv");

        std::unordered_map<std::string, std::vector<int>>
        LoadZones(const std::string &file = "zones.csv");

        std::unordered_map<std::string, std::vector<int>>
        LoadPatches(const std::string &file = "patches.csv");

    private:
        void
        CheckValidIds(const std::vector<std::string> &ids, const std::string &meta);
    };
};

}  // namespace Spatial
}  // namespace CommImpl
}  // namespace OpenOasis