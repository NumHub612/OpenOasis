/** ***********************************************************************************
 *    @File      :  Grid.cpp
 *    @Brief     :  Grid used for numerical calculation.
 *
 ** ***********************************************************************************/
#include "Grid.h"
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
}

void Grid::Activate()
{
    // Activate mesh face structures.
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

bool Grid::CheckMeshValid() const
{
    return true;
}

void Grid::CalculateFaceCentroid()
{
    // for (auto &face : mMesh.faces)
    // {
    //     double sumX = 0, sumY = 0, sumZ = 0;

    //     const auto &fNodes = face.nodeIndexes;
    //     for (const auto &node : fNodes)
    //     {
    //         sumX += mMesh.nodes[node].coor.x;
    //         sumY += mMesh.nodes[node].coor.y;
    //         sumZ += mMesh.nodes[node].coor.z;
    //     }

    //     double size   = double(fNodes.size());
    //     face.centroid = {sumX / size, sumY / size, sumZ / size};
    // }
}

void Grid::CalculateFaceNormal()
{}

void Grid::CalculateFaceArea()
{
    // Assume the nodes are in counter-clockwise order.

    // for (auto &face : mMesh.faces)
    // {
    //     if (face.nodeIndexes.size() == 2)
    //     {
    //         face.area = 0;
    //         continue;
    //     }

    //     // something to do.
    // }
}

void Grid::CalculateFacePerimeter()
{
    // Assume the nodes are in counter-clockwise order.

    // auto CalculateLength = [this](int i, int j) {
    //     const auto &node1 = mMesh.nodes[i];
    //     const auto &node2 = mMesh.nodes[j];

    //     double dx = node1.coor.x - node2.coor.x;
    //     double dy = node1.coor.y - node2.coor.y;

    //     double dz = 0;
    //     if (mMeshHasZ)
    //     {
    //         dz = node1.coor.z - node2.coor.z;
    //     }

    //     return sqrt(dx * dx + dy * dy + dz * dz);
    // };

    // for (auto &face : mMesh.faces)
    // {
    //     const auto &fNodes = face.nodeIndexes;
    //     double      size   = fNodes.size();
    //     double      len    = 0;

    //     for (int i = 0; i < size - 1; i++)
    //     {
    //         len += CalculateLength(i, i + 1);
    //     }

    //     if (size > 2)
    //     {
    //         len += CalculateLength(size - 1, 0);
    //     }

    //     face.perimeter = len;
    // }
}

void Grid::CalculateCellCentroid()
{
    // for (auto &cell : mMesh.cells)
    // {
    //     double      sumX = 0, sumY = 0, sumZ = 0;
    //     const auto &cFaces = cell.faceIndexes;
    //     for (const auto &face : cFaces)
    //     {
    //         sumX += mMesh.faces[face].centroid.x;
    //         sumY += mMesh.faces[face].centroid.y;
    //         sumZ += mMesh.faces[face].centroid.z;
    //     }

    //     double size   = double(cFaces.size());
    //     cell.centroid = {sumX / size, sumY / size, sumZ / size};
    // }
}

void Grid::CalculateCellSurface()
{
    // for (auto &cell : mMesh.cells)
    // {
    //     double surface = 0;
    //     for (const auto &face : cell.faceIndexes)
    //     {
    //         surface += mMesh.faces[face].area;
    //     }

    //     cell.surface = surface;
    // }
}

void Grid::CalculateCellVolume()
{}

void Grid::CollectCellsSharedNode()
{}

void Grid::CollectFacesSharedNode()
{}

void Grid::CollectCellNeighbors()
{
    // for (size_t i = 0; i < mMesh.cells.size(); i++)
    // {
    //     mMesh.cells[i].neighbors.clear();
    //     int curIdx = int(i);

    //     for (const auto &face : mMesh.cells[i].faceIndexes)
    //     {
    //         for (int idx : mMesh.faces[face].cellIndexes)
    //         {
    //             if (idx != curIdx)
    //             {
    //                 mMesh.cells[i].neighbors.push_back(idx);
    //             }
    //         }
    //     }
    // }
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