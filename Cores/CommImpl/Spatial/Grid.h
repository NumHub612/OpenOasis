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
#include <memory>


namespace OpenOasis
{
namespace CommImpl
{
namespace Spatial
{
/// @brief Grid encapsulate the mesh data for numerical calculation.
class Grid
{
protected:
    Mesh mMesh;

    // The number of original objects in the mesh before
    // refining or coarsening.
    int mRawNodesNum;
    int mRawFacesNum;
    int mRawCellsNum;

    // The outer or inner boundary patches, each of them
    // is composed of Face indexes.
    std::unordered_map<std::string, std::vector<int>> mPatches;

    // The zone enclosed by Face indexes.
    std::unordered_map<std::string, std::vector<int>> mZones;

    // The zone composed of Cell indexes.
    std::unordered_map<std::string, std::vector<int>> mZoneCells;

public:
    virtual ~Grid() = default;
    Grid(const std::string &meshDir);
    Grid(const std::shared_ptr<Grid> &grid);

    ///////////////////////////////////////////////////////////////////////////////////
    // Methods used for mesh operations.
    //

    /// @brief Get the grid type.
    /// @return Return 1, for 1d grid; 2, for 2d; 3, for 3d; others, for invalid type.
    virtual int GridType() const = 0;

    /// @brief Activate the mesh to extract topological information needed for various
    /// numerical calculations.
    virtual void Activate();

    /// @brief Refine the cell at the given index for adaptive grid.
    /// @note  The refining wouldn't change the origin nodes.
    virtual void RefineCell(int cellIndex) = 0;

    /// @brief Relax the cell at the given index for adaptive grid.
    /// @note  The coarsening wouldn't change the origin nodes.
    virtual void RelaxCell(int cellIndex) = 0;

    ///////////////////////////////////////////////////////////////////////////////////
    // Methods used for mesh query.
    //

    int GetRawNumCells() const;
    int GetRawNumFaces() const;
    int GetRawNumNodes() const;

    int GetNumCells() const;
    int GetNumFaces() const;
    int GetNumNodes() const;

    const Cell &GetCell(int cellIndex) const;
    const Face &GetFace(int faceIndex) const;
    const Node &GetNode(int nodeIndex) const;

    std::vector<std::string> GetPatchIds() const;
    std::vector<std::string> GetZoneIds() const;

    std::vector<int> GetPatchFaceIndexes(const std::string &patchId) const;
    std::vector<int> GetZoneCellIndexes(const std::string &zoneId) const;

protected:
    ///////////////////////////////////////////////////////////////////////////////////
    // Methods used for activating mesh data.
    //

    virtual void CollectCellsSharedNode();
    virtual void CollectFacesSharedNode();
    virtual void CollectCellsSharedFace();
    virtual void CollectCellNeighbors();
    virtual void CollectCellsInZone(){};

    virtual void SortNodes();

    virtual void CalculateFaceCentroid();
    virtual void CalculateFaceNormal(){};
    virtual void CalculateFaceArea(){};
    virtual void CalculateFacePerimeter(){};

    virtual void CalculateCellCentroid();
    virtual void CalculateCellSurface(){};
    virtual void CalculateCellVolume(){};

    virtual void CheckMesh() const;

protected:
    ///////////////////////////////////////////////////////////////////////////////////
    // Helper class to load mesh data from csv files.
    //

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
        void CheckIds(const std::vector<std::string> &ids, const std::string &type);
    };
};

}  // namespace Spatial
}  // namespace CommImpl
}  // namespace OpenOasis