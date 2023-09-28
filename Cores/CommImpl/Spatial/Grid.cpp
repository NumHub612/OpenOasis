/** ***********************************************************************************
 *    @File      :  Grid.cpp
 *    @Brief     :  Grid used for numerical calculation.
 *
 ** ***********************************************************************************/
#include "Grid.h"
#include "GeoCalculator.h"
#include "Cores/Utils/Exception.h"
#include "Cores/Utils/FilePathHelper.h"
#include "Cores/Utils/StringHelper.h"
#include "Cores/Utils/CsvHandler.h"
#include "Cores/Utils/MapHelper.h"
#include <set>


namespace OpenOasis::CommImpl::Spatial
{
using namespace Utils;
using namespace std;


// ------------------------------------------------------------------------------------

Grid::Grid(const string &meshDir)
{
    MeshLoader loader(meshDir);

#pragma omp parallel sections
    {
#pragma omp section
        {
            loader.LoadNodes();
            for (int i = 0; i < loader.mNodes.size(); ++i)
            {
                mMesh.nodes[i] = move(loader.mNodes[i]);
            }
        }
#pragma omp section
        {
            loader.LoadFaces();
            for (int i = 0; i < loader.mFaces.size(); ++i)
            {
                mMesh.faces[i] = move(loader.mFaces[i]);
            }
        }
#pragma omp section
        {
            loader.LoadCells();
            for (int i = 0; i < loader.mCells.size(); ++i)
            {
                mMesh.cells[i] = move(loader.mCells[i]);
            }
        }
    }

    mPatches = loader.LoadPatches();
    mZones   = loader.LoadZones();

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
    CalculateFaceCentroid();
    CalculateFaceNormal();
    CalculateFaceArea();
    CalculateFacePerimeter();

    // Activate mesh cell structures.
    CalculateCellCentroid();
    CalculateCellSurface();
    CalculateCellVolume();

    // Check mesh validation.
    CheckMesh();
}

void Grid::CollectCellsSharedNode()
{
#pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < mRawCellsNum; i++)
    {
        const auto &nodeIdxs = GeoCalculator::GetCellNodeIndexes(i, mMesh);
        for (int nIdx : nodeIdxs) mMesh.nodes[nIdx].cellIndexes.push_back(i);
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

void Grid::CalculateFaceCentroid()
{
#pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < mRawFacesNum; i++)
    {
        mMesh.faces[i].centroid = GeoCalculator::CalculateFaceCentroid(i, mMesh);
    }
}

void Grid::CalculateCellCentroid()
{
#pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < mRawCellsNum; i++)
    {
        mMesh.cells[i].centroid = GeoCalculator::CalculateCellCentroid(i, mMesh);
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

// ------------------------------------------------------------------------------------

Grid::MeshLoader::MeshLoader(const string &meshDir)
{
    if (!FilePathHelper::DirectoryExists(meshDir))
    {
        throw invalid_argument(
            StringHelper::FormatSimple("Mesh directory {} does not exist.", meshDir));
    }

    mMeshDir = meshDir;
}

void Grid::MeshLoader::LoadNodes(const string &nodeFile)
{
    const auto &file = FilePathHelper::Combine(mMeshDir, nodeFile);
    if (!FilePathHelper::FileExists(file)) return;

    CsvLoader loader(file, true, true);
    if (loader.GetColumnCount() < 3)
    {
        throw InvalidDataException("Invalid Node data, to few columns.");
    }

    auto ids = loader.GetRowLabels().value();
    CheckIds(ids, "Node");

    mNodes.resize(ids.size());
    for (int i = 0; i < mNodes.size(); ++i)
    {
        auto coor = loader.GetRow<double>(i).value();

        mNodes[i].coor = {coor[0], coor[1], coor[2]};
    }
}

void Grid::MeshLoader::LoadFaces(const string &faceFile)
{
    const auto &file = FilePathHelper::Combine(mMeshDir, faceFile);
    if (!FilePathHelper::FileExists(file)) return;

    CsvLoader loader(file, true, true);
    if (loader.GetColumnCount() < 2)
    {
        throw InvalidDataException("Invalid Face data, to few columns.");
    }

    auto ids = loader.GetRowLabels().value();
    CheckIds(ids, "Face");

    mFaces.resize(ids.size());
    for (int i = 0; i < mFaces.size(); ++i)
    {
        mFaces[i].nodeIndexes = loader.GetRow<int>(i).value();
    }
}

void Grid::MeshLoader::LoadCells(const string &cellFile)
{
    const auto &file = FilePathHelper::Combine(mMeshDir, cellFile);
    if (!FilePathHelper::FileExists(file)) return;

    CsvLoader loader(file, true, true);
    if (loader.GetColumnCount() < 3)
    {
        throw InvalidDataException("Invalid Cell data, to few columns.");
    }

    auto ids = loader.GetRowLabels().value();
    CheckIds(ids, "Cell");

    mCells.resize(ids.size());
    for (int i = 0; i < mCells.size(); ++i)
    {
        mCells[i].faceIndexes = loader.GetRow<int>(i).value();
    }
}

unordered_map<string, vector<int>>
Grid::MeshLoader::LoadPatches(const string &patchFile)
{
    const auto &file = FilePathHelper::Combine(mMeshDir, patchFile);
    if (!FilePathHelper::FileExists(file)) return {};

    CsvLoader loader(file, false, true);
    if (loader.GetColumnCount() < 1)
    {
        throw InvalidDataException("Invalid Patch data, to few columns.");
    }

    auto ids = loader.GetRowLabels().value();

    unordered_map<string, vector<int>> patches;
    for (const auto &id : ids) patches[id] = loader.GetRow<int>(id).value();

    return patches;
}

unordered_map<string, vector<int>> Grid::MeshLoader::LoadZones(const string &zoneFile)
{
    const auto &file = FilePathHelper::Combine(mMeshDir, zoneFile);
    if (!FilePathHelper::FileExists(file)) return {};

    CsvLoader loader(file, false, true);
    if (loader.GetColumnCount() < 3)
    {
        throw InvalidDataException("Invalid Zone data, to few columns.");
    }

    auto ids = loader.GetRowLabels().value();

    unordered_map<string, vector<int>> zones;
    for (const auto &id : ids) zones[id] = loader.GetRow<int>(id).value();

    return zones;
}

void Grid::MeshLoader::CheckIds(const vector<string> &ids, const string &meta)
{
    vector<int> ids_int(ids.size());
    transform(begin(ids), end(ids), begin(ids_int), [&](const string &id) {
        return stoi(id);
    });

    if (ids_int.front() != 0)
    {
        throw InvalidDataException(StringHelper::FormatSimple(
            "Invalid {} data, ids don't start from 0.", meta));
    }

    if (ids_int.back() != int(ids_int.size()) - 1)
    {
        throw InvalidDataException(
            StringHelper::FormatSimple("Invalid {} data, discontinuous ids.", meta));
    }

    set ids2(ids_int.begin(), ids_int.end());
    if (ids2.size() != ids.size())
    {
        throw InvalidDataException(
            StringHelper::FormatSimple("Invalid {} data, duplicate ids.", meta));
    }
}

}  // namespace OpenOasis::CommImpl::Spatial