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
#include <set>


namespace OpenOasis::CommImpl::Spatial
{
using namespace Utils;
using namespace std;


// ------------------------------------------------------------------------------------

Grid::Grid(const string &meshDir)
{
    MeshLoader loader(meshDir);

    loader.LoadNodes();
    for (int i = 0; i < loader.mNodes.size(); ++i)
    {
        mMesh.nodes[i] = move(loader.mNodes[i]);
    }

    loader.LoadFaces();
    for (int i = 0; i < loader.mFaces.size(); ++i)
    {
        mMesh.faces[i] = move(loader.mFaces[i]);
    }

    loader.LoadCells();
    for (int i = 0; i < loader.mCells.size(); ++i)
    {
        mMesh.cells[i] = move(loader.mCells[i]);
    }

    mPatches = loader.LoadPatches();
    mZones   = loader.LoadZones();

    mRawNodesNum = mMesh.nodes.size();
    mRawFacesNum = mMesh.faces.size();
    mRawCellsNum = mMesh.cells.size();
}

Grid::Grid(const Grid &grid)
{
    mMesh        = grid.mMesh;
    mRawCellsNum = grid.mRawCellsNum;
    mRawFacesNum = grid.mRawFacesNum;
    mRawNodesNum = grid.mRawNodesNum;
    mPatches     = grid.mPatches;
    mZones       = grid.mZones;
}

void Grid::Activate()
{
    // Activate mesh face structures in orderly.
    CalculateFaceCentroid();
    CalculateFaceNormal();
    CalculateFaceArea();
    CalculateFacePerimeter();

    // Activate mesh cell structures.
    CalculateCellCentroid();
    CalculateCellSurface();
    CalculateCellVolume();

    // Complete mesh topological information.
    CollectCellsSharedNode();
    CollectFacesSharedNode();
    CollectCellNeighbors();
}

void Grid::RefineCell(int cellIndex)
{
    throw NotImplementedException("Not implemented");
}

void Grid::CoarsenCell(int cellIndex)
{
    throw NotImplementedException("Not implemented");
}

void Grid::CalculateFaceCentroid()
{
    for (auto &face : mMesh.faces)
    {
        face.second.centroid = GeoCalculator::CalculateFaceCentroid(face.first, mMesh);
    }
}

void Grid::CalculateFaceNormal()
{
    for (auto &face : mMesh.faces)
    {
        face.second.normal = GeoCalculator::CalculateFaceNormal(face.first, mMesh);
    }
}

void Grid::CalculateFaceArea()
{
    for (auto &face : mMesh.faces)
    {
        face.second.area = GeoCalculator::CalculateFaceArea(face.first, mMesh);
    }
}

void Grid::CalculateFacePerimeter()
{
    for (auto &face : mMesh.faces)
    {
        face.second.perimeter =
            GeoCalculator::CalculateFacePerimeter(face.first, mMesh);
    }
}

void Grid::CalculateCellCentroid()
{
    for (auto &cell : mMesh.cells)
    {
        const auto &cFaces = cell.second.faceIndexes;

        double sumX = 0, sumY = 0, sumZ = 0;
        for (const auto &face : cFaces)
        {
            sumX += mMesh.faces[face].centroid.x;
            sumY += mMesh.faces[face].centroid.y;
            sumZ += mMesh.faces[face].centroid.z;
        }

        double size = double(cFaces.size());
        double x    = sumX / size;
        double y    = sumY / size;
        double z    = sumZ / size;

        cell.second.centroid = {x, y, z};
    }
}

void Grid::CalculateCellSurface()
{
    for (auto &cell : mMesh.cells)
    {
        double surface = 0;
        for (const auto &face : cell.second.faceIndexes)
        {
            surface += mMesh.faces[face].area;
        }

        cell.second.surface = surface;
    }
}

void Grid::CalculateCellVolume()
{
    if (mMesh.faces[0].nodeIndexes.size() == 2)
    {
        for_each(begin(mMesh.cells), end(mMesh.cells), [](auto &cell) {
            cell.second.volume = 0.0;
        });
        return;
    }
    for (auto &cell : mMesh.cells)
    {
        cell.second.volume = GeoCalculator::CalculateCellVolume(cell.first, mMesh);
    }
}

void Grid::CollectCellsSharedNode()
{}

void Grid::CollectFacesSharedNode()
{}

void Grid::CollectCellNeighbors()
{}

bool Grid::CheckMeshValid() const
{
    return true;
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
    CsvLoader loader(FilePathHelper::Combine(mMeshDir, nodeFile));
    if (loader.GetColumnCount() < 3)
    {
        throw InvalidDataException("Invalid Node data, to few columns.");
    }

    auto ids = loader.GetRowLabels().value();
    CheckValidIds(ids, "Node");

    mNodes.resize(ids.size());
    for (int i = 0; i < mNodes.size(); ++i)
    {
        auto coor = loader.GetRow<double>(i).value();

        mNodes[i].coor = {coor[0], coor[1], coor[2]};
    }
}

void Grid::MeshLoader::LoadFaces(const string &faceFile)
{
    CsvLoader loader(FilePathHelper::Combine(mMeshDir, faceFile));
    if (loader.GetColumnCount() < 2)
    {
        throw InvalidDataException("Invalid Face data, to few columns.");
    }

    auto ids = loader.GetRowLabels().value();
    CheckValidIds(ids, "Face");

    mFaces.resize(ids.size());
    for (int i = 0; i < mFaces.size(); ++i)
    {
        mFaces[i].nodeIndexes = loader.GetRow<int>(i).value();
    }
}

void Grid::MeshLoader::LoadCells(const string &cellFile)
{
    CsvLoader loader(FilePathHelper::Combine(mMeshDir, cellFile));
    if (loader.GetColumnCount() < 3)
    {
        throw InvalidDataException("Invalid Cell data, to few columns.");
    }

    auto ids = loader.GetRowLabels().value();
    CheckValidIds(ids, "Cell");

    mCells.resize(ids.size());
    for (int i = 0; i < mCells.size(); ++i)
    {
        mCells[i].faceIndexes = loader.GetRow<int>(i).value();
    }
}

unordered_map<string, vector<int>>
Grid::MeshLoader::LoadPatches(const string &patchFile)
{
    CsvLoader loader(FilePathHelper::Combine(mMeshDir, patchFile), false, true);
    if (loader.GetColumnCount() < 2)
    {
        throw InvalidDataException("Invalid Patch data, to few columns.");
    }

    auto ids = loader.GetRowLabels().value();

    unordered_map<string, vector<int>> patches;
    for (const auto &id : ids)
    {
        patches[id] = loader.GetRow<int>(id).value();
    }

    return patches;
}

unordered_map<string, vector<int>> Grid::MeshLoader::LoadZones(const string &zoneFile)
{
    const auto &file = FilePathHelper::Combine(mMeshDir, zoneFile);
    if (!FilePathHelper::FileExists(file))
    {
        return {};
    }

    CsvLoader loader(FilePathHelper::Combine(mMeshDir, zoneFile), false, true);
    if (loader.GetColumnCount() < 3)
    {
        throw InvalidDataException("Invalid Zone data, to few columns.");
    }

    auto ids = loader.GetRowLabels().value();

    unordered_map<string, vector<int>> zones;
    for (const auto &id : ids)
    {
        zones[id] = loader.GetRow<int>(id).value();
    }

    return zones;
}

void Grid::MeshLoader::CheckValidIds(const vector<string> &ids, const string &meta)
{
    vector<int> ids_int(ids.size());
    transform(begin(ids), end(ids), begin(ids_int), [](const string &id) {
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