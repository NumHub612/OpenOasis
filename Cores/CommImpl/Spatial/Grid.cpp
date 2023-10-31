/** ***********************************************************************************
 *    @File      :  Grid.cpp
 *    @Brief     :  Grid used for numerical calculation.
 *
 ** ***********************************************************************************/
#include "Grid.h"
#include "GeoCalculator.h"
#include "Cores/Utils/Exception.h"
#include "Cores/Utils/MapHelper.h"


namespace OpenOasis::CommImpl::Spatial
{
using namespace Utils;
using namespace std;


// ------------------------------------------------------------------------------------

Grid::Grid(
    unordered_map<int, Coordinate>     &nodeCoords,
    unordered_map<int, Coordinate>     &faceCoords,
    unordered_map<int, Coordinate>     &cellCoords,
    unordered_map<int, vector<int>>    &faceNodes,
    unordered_map<int, vector<int>>    &cellFaces,
    unordered_map<string, vector<int>> &patches,
    unordered_map<string, vector<int>> &zones)
{
#pragma omp parallel sections
    {
#pragma omp section
        {
            for (auto &node : nodeCoords)
            {
                mMesh.nodes[node.first]      = {};
                mMesh.nodes[node.first].coor = move(node.second);
            }

            nodeCoords.clear();
        }
#pragma omp section
        {
            for (auto &face : faceCoords)
            {
                int i                      = face.first;
                mMesh.faces[i]             = {};
                mMesh.faces[i].centroid    = move(face.second);
                mMesh.faces[i].nodeIndexes = move(faceNodes[i]);
            }

            faceCoords.clear();
            faceNodes.clear();
        }
#pragma omp section
        {
            for (auto &cell : cellCoords)
            {
                int i                      = cell.first;
                mMesh.cells[i]             = {};
                mMesh.cells[i].centroid    = move(cellCoords[i]);
                mMesh.cells[i].faceIndexes = move(cellFaces[i]);
            }

            cellCoords.clear();
            cellFaces.clear();
        }
    }

    mPatches = move(patches);
    mZones   = move(zones);

    mRawNodesNum = mMesh.nodes.size();
    mRawFacesNum = mMesh.faces.size();
    mRawCellsNum = mMesh.cells.size();
}

Grid::Grid(const shared_ptr<Grid> &grid)
{
    mMesh        = grid->mMesh;
    mRawCellsNum = grid->mRawCellsNum;
    mRawFacesNum = grid->mRawFacesNum;
    mRawNodesNum = grid->mRawNodesNum;
    mPatches     = grid->mPatches;
    mZones       = grid->mZones;
}

void Grid::Activate()
{
    // Complete mesh topological connections.
    CollectCellsSharedNode();
    CollectFacesSharedNode();
    CollectCellsSharedFace();
    CollectCellNeighbors();
    CollectCellsInZone();

    // Sort node counterclockwise.
    SortNodes();

    // Activate mesh face structures in orderly.
    CalculateFaceDirector();
    CalculateFaceNormal();
    CalculateFaceArea();
    CalculateFacePerimeter();

    // Activate mesh cell structures.
    CalculateCellSurface();
    CalculateCellVolume();

    // Check mesh validation.
    CheckMesh();

    // Analysis mesh structures.
    CalculateCellDistances();
    CalculateBoundaryCenterDistances();
}

void Grid::CollectCellsSharedNode()
{
#pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < mRawCellsNum; i++)
    {
        const auto &nodeIdxs = GeoCalculator::GetCellNodeIndexes(i, mMesh);
        for (int nIdx : nodeIdxs)
            mMesh.nodes[nIdx].cellIndexes.push_back(i);
    }
}

void Grid::CollectFacesSharedNode()
{
#pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < mRawFacesNum; i++)
    {
        for (int nIdx : mMesh.faces[i].nodeIndexes)
        {
            mMesh.nodes[nIdx].faceIndexes.push_back(i);
        }
    }
}

void Grid::CollectCellsSharedFace()
{
#pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < mRawCellsNum; i++)
    {
        for (int fIdx : mMesh.cells[i].faceIndexes)
        {
            mMesh.faces[fIdx].cellIndexes.push_back(i);
        }
    }
}

void Grid::CollectCellNeighbors()
{
#pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < mRawFacesNum; i++)
    {
        const auto &cells = mMesh.faces[i].cellIndexes;
        if (cells.size() != 2) continue;

        mMesh.cells[cells[0]].neighbors.push_back(cells[1]);
        mMesh.cells[cells[1]].neighbors.push_back(cells[0]);
    }
}

void Grid::SortNodes()
{
#pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < mRawFacesNum; i++)
    {
        mMesh.faces[i].nodeIndexes = GeoCalculator::SortFaceNodes(i, mMesh);
    }
}

void Grid::CalculateFaceDirector()
{
#pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < mRawFacesNum; i++)
    {
        auto       &face   = mMesh.faces[i];
        const auto &fPoint = face.centroid;
        const auto &cPoint = mMesh.cells[face.cellIndexes[0]].centroid;

        double x = cPoint.x - fPoint.x;
        double y = cPoint.y - fPoint.y;
        double z = (fPoint.HasZ()) ? cPoint.z - fPoint.z : 0;

        auto vec = Vector<double, 3>(x, y, z);
        auto res = vec * face.normal;
        auto dir = (res > 0) ? 1 : -1;

        face.cellDirs.push_back(dir);

        if (face.cellIndexes.size() == 2) face.cellDirs.push_back(-dir);
    }
}

void Grid::CalculateCellDistances()
{
    for (int i = 0; i < mRawCellsNum; i++)
    {
        const auto &cell = mMesh.cells[i];
        const auto &n1   = cell.centroid;

        for (int j : cell.neighbors)
        {
            auto index1 = MultiIndex({i, j});
            if (mCenterDists.count(index1) > 0) continue;

            const auto &n2 = mMesh.cells[j].centroid;

            mCenterDists[index1] = CalculateDistance(n1, n2);

            auto index2 = MultiIndex({j, i});

            mCenterDists[index2] = mCenterDists[index1];
        }
    }
}

void Grid::CalculateBoundaryCenterDistances()
{
    for (int i = 0; i < mRawCellsNum; i++)
    {
        const auto &cell = mMesh.cells[i];
        const auto &n1   = cell.centroid;

        for (int j : cell.faceIndexes)
        {
            auto index1 = MultiIndex({i, j});
            if (mBoundaryCenterDists.count(index1) > 0) continue;

            const auto &n2 = mMesh.faces[j].centroid;

            double dist = CalculateDistance(n1, n2);

            mBoundaryCenterDists[index1] = dist;

            auto index2 = MultiIndex({j, i});

            mBoundaryCenterDists[index2] = dist;
        }
    }
}

void Grid::CheckMesh() const
{}

int Grid::GetRawNumCells() const
{
    return mRawCellsNum;
}

int Grid::GetRawNumFaces() const
{
    return mRawFacesNum;
}

int Grid::GetRawNumNodes() const
{
    return mRawNodesNum;
}

int Grid::GetNumCells() const
{
    return (int)mMesh.cells.size();
}

int Grid::GetNumFaces() const
{
    return (int)mMesh.faces.size();
}

int Grid::GetNumNodes() const
{
    return (int)mMesh.nodes.size();
}

const Cell &Grid::GetCell(int cellIndex) const
{
    return mMesh.cells.at(cellIndex);
}

const Face &Grid::GetFace(int faceIndex) const
{
    return mMesh.faces.at(faceIndex);
}

const Node &Grid::GetNode(int nodeIndex) const
{
    return mMesh.nodes.at(nodeIndex);
}

vector<string> Grid::GetPatchIds() const
{
    return MapHelper::GetKeys(mPatches);
}

vector<string> Grid::GetZoneIds() const
{
    return MapHelper::GetKeys(mZones);
}

vector<int> Grid::GetPatchFaceIndexes(const string &patchId) const
{
    return mPatches.at(patchId);
}

vector<int> Grid::GetZoneCellIndexes(const string &zoneId) const
{
    throw NotImplementedException();
}

const MultiIndexMap<double> &Grid::GetBoundaryCenterDistances() const
{
    return mBoundaryCenterDists;
}

double Grid::GetBoundaryCenterDistance(int cellIdx, int boundaryFaceIdx) const
{
    return mBoundaryCenterDists.at(MultiIndex({cellIdx, boundaryFaceIdx}));
}

const MultiIndexMap<double> &Grid::GetCellCenterDistances() const
{
    return mCenterDists;
}

double Grid::GetCellCenterDistance(int cellIdx, int neighborCellIdx) const
{
    return mCenterDists.at(MultiIndex({cellIdx, neighborCellIdx}));
}

}  // namespace OpenOasis::CommImpl::Spatial