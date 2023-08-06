/** ***********************************************************************************
 *    @File      :  Grid.cpp
 *    @Brief     :  Grid used for numerical calculation.
 *
 ** ***********************************************************************************/
#include "Grid.h"
#include "Cores/Utils/Exception.h"


namespace OpenOasis::CommImpl::Spatial
{
using namespace std;
using namespace Utils;

Grid::Grid(Mesh &&mesh) : mMesh(move(mesh))
{}

Grid::Grid(const Mesh &mesh) : mMesh(mesh)
{}

Grid::Grid(const Grid &grid) : mMesh(grid.mMesh)
{}

void Grid::ActivateMesh()
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
{}

void Grid::CalculateFaceCentroid()
{
    for (auto &face : mMesh.faces)
    {
        double sumX = 0, sumY = 0, sumZ = 0;

        const auto &fNodes = face.nodeIndexes;
        for (const auto &node : fNodes)
        {
            sumX += mMesh.nodes[node].coor.x;
            sumY += mMesh.nodes[node].coor.y;
            sumZ += mMesh.nodes[node].coor.z;
        }

        double size   = double(fNodes.size());
        face.centroid = {sumX / size, sumY / size, sumZ / size};
    }
}

void Grid::CalculateFaceNormal()
{}

void Grid::CalculateFaceArea()
{
    // Assume the nodes are in counter-clockwise order.

    for (auto &face : mMesh.faces)
    {
        if (face.nodeIndexes.size() == 2)
        {
            face.area = 0;
            continue;
        }

        // something to do.
    }
}

void Grid::CalculateFacePerimeter()
{
    // Assume the nodes are in counter-clockwise order.

    auto CalculateLength = [this](int i, int j) {
        const auto &node1 = mMesh.nodes[i];
        const auto &node2 = mMesh.nodes[j];

        double dx = node1.coor.x - node2.coor.x;
        double dy = node1.coor.y - node2.coor.y;

        double dz = 0;
        if (mMeshHasZ)
        {
            dz = node1.coor.z - node2.coor.z;
        }

        return sqrt(dx * dx + dy * dy + dz * dz);
    };

    for (auto &face : mMesh.faces)
    {
        const auto &fNodes = face.nodeIndexes;
        double      size   = fNodes.size();
        double      len    = 0;

        for (int i = 0; i < size - 1; i++)
        {
            len += CalculateLength(i, i + 1);
        }

        if (size > 2)
        {
            len += CalculateLength(size - 1, 0);
        }

        face.perimeter = len;
    }
}

void Grid::CalculateCellCentroid()
{
    for (auto &cell : mMesh.cells)
    {
        double      sumX = 0, sumY = 0, sumZ = 0;
        const auto &cFaces = cell.faceIndexes;
        for (const auto &face : cFaces)
        {
            sumX += mMesh.faces[face].centroid.x;
            sumY += mMesh.faces[face].centroid.y;
            sumZ += mMesh.faces[face].centroid.z;
        }

        double size   = double(cFaces.size());
        cell.centroid = {sumX / size, sumY / size, sumZ / size};
    }
}

void Grid::CalculateCellSurface()
{
    for (auto &cell : mMesh.cells)
    {
        double surface = 0;
        for (const auto &face : cell.faceIndexes)
        {
            surface += mMesh.faces[face].area;
        }

        cell.surface = surface;
    }
}

void Grid::CalculateCellVolume()
{}

void Grid::CollectCellsSharedNode()
{}

void Grid::CollectFacesSharedNode()
{}

void Grid::CollectCellNeighbors()
{
    for (size_t i = 0; i < mMesh.cells.size(); i++)
    {
        mMesh.cells[i].neighbors.clear();
        int curIdx = int(i);

        for (const auto &face : mMesh.cells[i].faceIndexes)
        {
            for (int idx : mMesh.faces[face].cellIndexes)
            {
                if (idx != curIdx)
                {
                    mMesh.cells[i].neighbors.push_back(idx);
                }
            }
        }
    }
}

size_t Grid::GetNumCells() const
{
    return mMesh.cells.size();
}

size_t Grid::GetNumFaces() const
{
    return mMesh.faces.size();
}

size_t Grid::GetNumNodes() const
{
    return mMesh.nodes.size();
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

vector<size_t> Grid::GetBoundaryFaceIdexes() const
{
    vector<size_t> boundFaces;

    for (size_t i = 0; i < mMesh.faces.size(); i++)
    {
        if (mMesh.faces[i].cellIndexes.size() == 1)
        {
            boundFaces.push_back(i);
        }
    }

    return boundFaces;
}

}  // namespace OpenOasis::CommImpl::Spatial