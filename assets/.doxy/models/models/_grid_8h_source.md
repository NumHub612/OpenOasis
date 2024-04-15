

# File Grid.h

[**File List**](files.md) **>** [**CommImp**](dir_6202b98a8704f42b1ea358646461643f.md) **>** [**Spatial**](dir_47a0bcc12c466f07097ed8db741700fa.md) **>** [**Grid.h**](_grid_8h.md)

[Go to the documentation of this file](_grid_8h.md)


```C++

#pragma once
#include "MeshStructs.h"
#include "Models/CommImp/Numeric/Vector.h"
#include "Models/Utils/MultiIndexMapper.h"
#include <string>
#include <memory>


namespace OpenOasis::CommImp::Spatial
{
using Numeric::Vector;
using Utils::MultiIndexMap;


class Grid
{
protected:
    Mesh mMesh;

    // The number of original objects in the mesh before
    // refining or coarsening.
    int mRawNodesNum, mRawCellsNum, mRawFacesNum;

    // The boundary cells and faces.
    std::vector<int> mBoundaryCells;
    std::vector<int> mBoundaryFaces;

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

    // The interfacial intersection point with line of cell centers.
    std::unordered_map<int, Coordinate> mFaceIntersection;

    // The weight of each cell at face.
    MultiIndexMap<double> mCellFaceWeight;

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


    // Methods used for mesh operations.
    //

    virtual int Type() const = 0;

    virtual void Activate();

    virtual void RefineCell(int cellIndex) = 0;

    virtual void RelaxCell(int cellIndex) = 0;

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

    const std::vector<int> &GetBoundaryFaceIndexes() const;

    const std::vector<int> &GetBoundaryCellIndexes() const;

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
```


