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
#include "Cores/CommImpl/Numeric/ScalarField.h"
#include "Cores/Utils/MultiIndexMapper.h"
#include <string>
#include <memory>


namespace OpenOasis::CommImpl::Spatial
{
using Numeric::ScalarFieldDbl;
using Utils::MultiIndexMap;


/// @brief Grid encapsulate the mesh data for numerical calculation.
class Grid
{
protected:
    Mesh mMesh;

    // The number of original objects in the mesh before
    // refining or coarsening.
    int mRawNodesNum, mRawCellsNum, mRawFacesNum;

    // The outer or inner boundary patches, each of them
    // is composed of Face indexes.
    std::unordered_map<std::string, std::vector<int>> mPatches;

    // The zone enclosed by Face indexes.
    std::unordered_map<std::string, std::vector<int>> mZones;

    // The zone composed of Cell indexes.
    std::unordered_map<std::string, std::vector<int>> mZoneCells;

    // The distances between cell centroids.
    MultiIndexMap<double> mCenterDists;

    // The distances between cell centroid and boundary face.
    MultiIndexMap<double> mBoundaryCenterDists;

public:
    virtual ~Grid() = default;
    Grid(const std::shared_ptr<Grid> &grid);
    Grid(
        std::unordered_map<int, Coordinate>               &nodeCoords,
        std::unordered_map<int, Coordinate>               &faceCoords,
        std::unordered_map<int, Coordinate>               &cellCoords,
        std::unordered_map<int, std::vector<int>>         &faceNodes,
        std::unordered_map<int, std::vector<int>>         &cellFaces,
        std::unordered_map<std::string, std::vector<int>> &patches,
        std::unordered_map<std::string, std::vector<int>> &zones);


    ///////////////////////////////////////////////////////////////////////////////////
    // Methods used for mesh operations.
    //

    /// @brief Get the grid type.
    /// @return Return 1, for 1d grid; 2, for 2d; 3, for 3d; others, for invalid type.
    virtual int Type() const = 0;

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

    ///////////////////////////////////////////////////////////////////////////////////
    // Methods used for mesh analysis.
    //

    const MultiIndexMap<double> &GetBoundaryCenterDistances() const;

    double GetBoundaryCenterDistance(int cellIdx, int boundaryFaceIdx) const;

    const MultiIndexMap<double> &GetCellCenterDistances() const;

    double GetCellCenterDistance(int cellIdx, int neighborCellIdx) const;

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

    virtual void CalculateFaceDirector();
    virtual void CalculateFaceNormal(){};
    virtual void CalculateFaceArea(){};
    virtual void CalculateFacePerimeter(){};

    virtual void CalculateCellSurface(){};
    virtual void CalculateCellVolume(){};

    virtual void CheckMesh() const;

    ///////////////////////////////////////////////////////////////////////////////////
    // Methods used for analysing mesh data.
    //

    virtual void CalculateCellDistances();
    virtual void CalculateBoundaryCenterDistances();

    inline double CalculateDistance(const Coordinate &n1, const Coordinate &n2) const
    {
        return sqrt(pow(n1.x - n2.x, 2) + pow(n1.y - n2.y, 2) + pow(n1.z - n2.z, 2));
    }
};

}  // namespace OpenOasis::CommImpl::Spatial