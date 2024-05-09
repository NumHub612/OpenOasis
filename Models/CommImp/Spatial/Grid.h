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
#include "MeshProcessor.h"
#include "Models/CommImp/Numeric/Vector.h"
#include "Models/Utils/MultiIndexMapper.h"
#include <string>
#include <memory>


namespace OpenOasis::CommImp::Spatial
{
using Utils::MultiIndexMap;
using Numeric::Vector;


/// @brief Grid encapsulate the mesh data for numerical calculation.
class Grid
{
protected:
    Mesh mMesh;

    // The number of original objects in the mesh before
    // refining or coarsening.
    int mRawNodesNum, mRawCellsNum, mRawFacesNum;

    // The boundary cells and faces.
    std::vector<int> mBoundCells, mBoundFaces;

    // The outer or inner boundary patches, each of them
    // is composed of face indexes.
    std::unordered_map<std::string, std::vector<int>> mPatches;

    // The zone enclosed by face indexes.
    std::unordered_map<std::string, std::vector<int>> mZones;

    // The zone composed of cell indexes.
    std::unordered_map<std::string, std::vector<int>> mZoneCells;

    // The distances between cell centroids.
    MultiIndexMap<double> mCellCenterDists;

    // The distances between cell centroid and boundary face.
    MultiIndexMap<double> mBoundaryCenterDists;

    // The interior intersection point with line of cell centers.
    std::unordered_map<int, Coordinate> mFaceIntersections;

    // The weight of each cell at face.
    MultiIndexMap<double> mCellWeights;

    // The distance between face centroid and intersection.
    std::unordered_map<int, Vector<double>> mFaceCorrVecs;

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
    // Methods used for mesh activation and manipulations.
    //

    /// @brief Activate to have topology and geometry data used for numerical methods.
    virtual void Activate();

    /// @brief Get grid version.
    virtual int Version() const;

    /// @brief Refine the origin cell of a given index @p cellIndex for adaptive grid.
    /// @return The newly added cells' indexes.
    /// @note This method would not change the raw nodes, but add new nodes and cells.
    virtual std::vector<int> RefineCell(int cellIndex) = 0;

    /// @brief Relax the origin cell of a given index @p cellIndex .
    /// @note This method would not change the raw nodes.
    virtual void RelaxCell(int cellIndex) = 0;

    ///////////////////////////////////////////////////////////////////////////////////
    // Methods used for mesh query.
    //

    const Mesh &GetMesh() const;
    const Cell &GetCell(int cellIndex) const;
    const Face &GetFace(int faceIndex) const;
    const Node &GetNode(int nodeIndex) const;

    int GetRawNumCells() const;
    int GetRawNumFaces() const;
    int GetRawNumNodes() const;
    int GetNumCells() const;
    int GetNumFaces() const;
    int GetNumNodes() const;

    const std::vector<int> &GetBoundaryFaceIndexes() const;

    const std::vector<int> &GetBoundaryCellIndexes() const;

    ///////////////////////////////////////////////////////////////////////////////////
    // Methods used for mesh analysis.
    //

    const MultiIndexMap<double> &GetBoundaryCenterDistances() const;

    double GetBoundaryCenterDistance(int cellIdx, int boundaryFaceIdx) const;

    const MultiIndexMap<double> &GetCellCenterDistances() const;

    double GetCellCenterDistance(int cellIdx, int neighborCellIdx) const;

    const MultiIndexMap<double> &GetCellWeightAtFace() const;

    double GetCellWeightAtFace(int cellIdx, int faceIdx) const;

    const std::unordered_map<int, Vector<double>> &GetFaceCorrectionVector() const;

    const Vector<double> &GetFaceCorrectionVector(int faceIdx) const;

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

    virtual void CollectBoundaryFacesAndCells();

    virtual void CalculateFaceIntersections();
    virtual void CalculateFaceWeights();
    virtual void CalculateFaceCorrectionVector();

    inline double CalculateDistance(const Coordinate &n1, const Coordinate &n2) const
    {
        return sqrt(pow(n1.x - n2.x, 2) + pow(n1.y - n2.y, 2) + pow(n1.z - n2.z, 2));
    }
};

}  // namespace OpenOasis::CommImp::Spatial