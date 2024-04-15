

# File MeshStructs.h

[**File List**](files.md) **>** [**CommImp**](dir_6202b98a8704f42b1ea358646461643f.md) **>** [**Spatial**](dir_47a0bcc12c466f07097ed8db741700fa.md) **>** [**MeshStructs.h**](_mesh_structs_8h.md)

[Go to the documentation of this file](_mesh_structs_8h.md)


```C++

#pragma once
#include "Coordinate.h"
#include <vector>
#include <array>
#include <unordered_map>
#include <cmath>


namespace OpenOasis
{
namespace CommImp
{
namespace Spatial
{
struct Node
{
    Coordinate coor;  // unit(m).

    // Indexes of mesh faces shared the node.
    std::vector<int> faceIndexes;

    // Indexes of mesh cells shared the node.
    std::vector<int> cellIndexes;
};


struct Face
{
    Coordinate centroid;

    // Perimeter of the face in (m).
    real perimeter = NAN;

    // Area of the face in (m^2).
    real area = NAN;

    // Unit normal vector.
    std::array<real, 3> normal;

    // Indexes of mesh nodes on the
    // face sorted counterclockwise.
    std::vector<int> nodeIndexes;

    // Indexes of mesh cells shared
    // the face.
    std::vector<int> cellIndexes;

    // Orientation of cells to face
    // (Same or opposite to normal)
    // (Corresponds to cellIndexes)
    std::vector<int> cellSides;
};


struct Cell
{
    Coordinate centroid;

    // Volume of the cell in (m^3).
    real volume = NAN;

    // Surface area in (m^2).
    real surface = NAN;

    // Indexes of faces on the cell.
    std::vector<int> faceIndexes;

    // Indexes of neighboring cells.
    std::vector<int> neighbors;

    // Indexes of sub-cells
    // after current cell's refined.
    std::vector<int> subCells;
};


struct Mesh
{
    // Mesh nodes set.
    std::unordered_map<int, Node> nodes;

    // Mesh faces set.
    std::unordered_map<int, Face> faces;

    // Mesh cells set.
    std::unordered_map<int, Cell> cells;
};

}  // namespace Spatial
}  // namespace CommImp
}  // namespace OpenOasis
```


