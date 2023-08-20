/** ***********************************************************************************
 *    @File      :  GeoCalculator.cpp
 *    @Brief     :  A collection of general geometry functions.
 *
 ** ***********************************************************************************/
#include "GeoCalculator.h"
#include "Cores/Utils/Exception.h"
#include <set>


namespace OpenOasis::CommImpl::Spatial
{
using namespace Utils;
using namespace std;

Coordinate GeoCalculator::CalculateFaceCentroid(int faceIdx, const Mesh &mesh)
{
    const auto &nodeIdxs = mesh.faces.at(faceIdx).nodeIndexes;
    if (nodeIdxs.empty())
    {
        return {};
    }

    double sumX = 0., sumY = 0., sumZ = 0.;
    double size = double(nodeIdxs.size());

    const auto &nodes = mesh.nodes;
    for (int idx : nodeIdxs)
    {
        sumX += nodes.at(idx).coor.x;
        sumY += nodes.at(idx).coor.y;
        sumZ += nodes.at(idx).coor.z;
    }

    return {sumX / size, sumY / size, sumZ / size};
}

array<double, 3> GeoCalculator::CalculateFaceNormal(int faceIdx, const Mesh &mesh)
{
    const auto &nodeIdxs = mesh.faces.at(faceIdx).nodeIndexes;
    int         size     = nodeIdxs.size();
    const auto &nodes    = mesh.nodes;

    // 2D mesh, calculate the normal vector projected by an edge onto the xy plane.
    if (size == 2)
    {
        auto vec = ToVector(nodes.at(nodeIdxs[0]), nodes.at(nodeIdxs[1]));
        vec.Normalize();

        return {vec(1), vec(0), 0.};
    }
    // 3D mesh, calculate the normal vector of the face.
    else
    {
        const auto &v1 = ToVector(nodes.at(nodeIdxs[1]), nodes.at(nodeIdxs[0]));
        const auto &v2 = ToVector(nodes.at(nodeIdxs[1]), nodes.at(nodeIdxs[2]));
        auto        n  = v1 & v2;
        n.Normalize();

        return {n(0), n(1), n(2)};
    }
}

double GeoCalculator::CalculateFaceArea(int faceIdx, const Mesh &mesh)
{
    const auto &nodeIdxs = mesh.faces.at(faceIdx).nodeIndexes;
    int         size     = nodeIdxs.size();

    // 2D mesh.
    if (size == 2)
    {
        return 0.;
    }

    // 3D mesh, calculate face area by Shoelace Theorem in 3d.
    // area = 1/2 * {
    //        cos(n, z) * sum(x_i * y_i+1 - x_i+1 * y_i) +
    //        cos(n, x) * sum(y_i * z_i+1 - y_i+1 * z_i) +
    //        cos(n, y) * sum(z_i * x_i+1 - z_i+1 * x_i)
    // }
    Vector<double, 3> x = {1., 0., 0.}, y = {0., 1., 0.}, z = {0., 0., 1.};
    const auto       &n = mesh.faces.at(faceIdx).normal;
    Vector<double, 3> normal{n[0], n[1], n[2]};

    double zCos = normal * z;
    double xCos = normal * x;
    double yCos = normal * y;

    double area = 0.0;
    for (int i = 0; i < size - 1; ++i)
    {
        const auto &node0 = mesh.nodes.at(nodeIdxs[i]).coor;
        const auto &node1 = mesh.nodes.at(nodeIdxs[i + 1]).coor;

        area += zCos * (node0.x * node1.y - node0.y * node1.x);
        area += xCos * (node0.y * node1.z - node0.z * node1.y);
        area += yCos * (node0.z * node1.x - node0.x * node1.z);
    }

    return abs(area) / 2.0;
}

double GeoCalculator::CalculateFacePerimeter(int faceIdx, const Mesh &mesh)
{
    auto CalculateLength = [&mesh](const Node &node1, const Node &node2) {
        double dx = node1.coor.x - node2.coor.x;
        double dy = node1.coor.y - node2.coor.y;
        double dz = node1.coor.z - node2.coor.z;

        return sqrt(dx * dx + dy * dy + dz * dz);
    };

    const auto &fNodes = mesh.faces.at(faceIdx).nodeIndexes;
    int         n      = fNodes.size();
    const auto &nodes  = mesh.nodes;

    double len = 0;
    for (int i = 0; i < n - 1; i++)
    {
        len += CalculateLength(nodes.at(fNodes[i]), nodes.at(fNodes[i + 1]));
    }

    if (n > 2)
    {
        len += CalculateLength(nodes.at(fNodes[n - 1]), nodes.at(fNodes[0]));
    }

    return len;
}

double GeoCalculator::CalculateCellVolume(int cellIdx, const Mesh &mesh)
{
    // Only tetrahedral and prismatic volume calculations are supported.

    const auto &cFaces = mesh.cells.at(cellIdx).faceIndexes;
    int         size   = cFaces.size();

    // tetrahedral cell.
    if (size == 4)
    {
        set<int> nodeSet;
        for (int f : cFaces)
        {
            const auto &fNodes = mesh.faces.at(f).nodeIndexes;
            nodeSet.insert(fNodes.begin(), fNodes.end());
        }

        vector<int> vertices(nodeSet.begin(), nodeSet.end());
        const auto &nodes = mesh.nodes;

        const auto &v1 = ToVector(nodes.at(vertices[0]), nodes.at(vertices[1]));
        const auto &v2 = ToVector(nodes.at(vertices[0]), nodes.at(vertices[2]));
        const auto &v3 = ToVector(nodes.at(vertices[0]), nodes.at(vertices[3]));

        double vol = ((v1 & v2) * v3) / 6.0;
        return vol;
    }
    else
    {
        throw NotImplementedException();
    }
}

Vector<double, 3> GeoCalculator::ToVector(const Node &start, const Node &end)
{
    const auto &node0 = start.coor;
    const auto &node1 = end.coor;

    return {node1.x - node0.x, node1.y - node0.y, node1.z - node0.z};
}

}  // namespace OpenOasis::CommImpl::Spatial