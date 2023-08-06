/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  MeshStructs.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Definitions of mesh related structures.
 *
 ** ***********************************************************************************/
#pragma once
#include "Coordinate.h"
#include <vector>
#include <array>
#include <unordered_map>


namespace OpenOasis
{
namespace CommImpl
{
namespace Spatial
{
/// @brief Mesh point data structure.
/// (Point type).
struct Node
{
    Coordinate coor;  // unit (m).

    // Indexes of mesh faces shared the node.
    std::vector<int> faceIndexes;

    // Indexes of mesh cells shared the node.
    std::vector<int> cellIndexes;
};


/// @brief Mesh face data structure.
/// Polyline type for 1D or 2D mesh,
/// Polygon type for 3D mesh.
struct Face
{
    Coordinate centroid;

    // Perimeter of the face in (m).
    double perimeter = NAN;

    // Area of the face in (m^2).
    double area = NAN;

    // Unit normal vector of the face.
    std::array<double, 3> normal;

    // Indexes of mesh nodes on the face sorted counterclockwise.
    std::vector<int> nodeIndexes;

    /// Indexes of mesh cells shared the face.
    std::vector<int> cellIndexes;
};


/// @brief Mesh cell data structure.
/// Polygon type for 1D and 2D mesh,
/// Polyhedron type for 3D mesh.
struct Cell
{
    Coordinate centroid;

    // Volume of the cell in (m^3).
    double volume = NAN;

    // Surface area in (m^2).
    double surface = NAN;

    // Indexes of mesh faces on the cell.
    std::vector<int> faceIndexes;

    /// Indexes of neighboring cells.
    std::vector<int> neighbors;
};


/// @brief Mesh data structure.
struct Mesh
{
    std::vector<Node> nodes;  // Mesh nodes set.
    std::vector<Face> faces;  // Mesh faces set.
    std::vector<Cell> cells;  // Mesh cells set.
};

}  // namespace Spatial
}  // namespace CommImpl
}  // namespace OpenOasis
