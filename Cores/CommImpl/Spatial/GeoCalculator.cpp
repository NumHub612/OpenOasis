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

vector<int> GeoCalculator::SortNodes(
    const vector<int> &nodeIdxs, const unordered_map<int, Node> &nodes)
{
    vector<int> sortedIdxs(nodeIdxs);

    auto centroid    = CalculateCentroid(nodeIdxs, nodes);
    int  ignoredAxis = ChooseFoldedAxis(nodeIdxs, nodes);

    for (int i = 0; i < sortedIdxs.size() - 1; i++)
    {
        int curr = sortedIdxs[i];
        for (int j = 0; j < sortedIdxs.size() - i - 1; j++)
        {
            double next = sortedIdxs[j];
            if (CompareNodeOrder(nodes.at(j), nodes.at(j + 1), centroid, ignoredAxis))
            {
                sortedIdxs[j]     = next;
                sortedIdxs[j + 1] = curr;
            }
        }
    }

    return sortedIdxs;
}

vector<int> GeoCalculator::SortFaceNodes(int faceIndex, const Mesh &mesh)
{
    return SortNodes(mesh.faces.at(faceIndex).nodeIndexes, mesh.nodes);
}

int GeoCalculator::ChooseFoldedAxis(
    const vector<int> &nodeIdxs, const unordered_map<int, Node> &nodes)
{
    int num = nodeIdxs.size();

    vector<double> Xs(num), Ys(num), Zs(num);
    for (int idx : nodeIdxs)
    {
        const auto &coor = nodes.at(idx).coor;
        Xs.push_back(coor.x);
        Ys.push_back(coor.y);
        Zs.push_back(coor.z);
    }

    int axisX = 0, axisY = 0, axisZ = 0;
    for (int i = 0; i < num; ++i)
    {
        for (int j = i; j < num; ++j)
        {
            if (abs(Xs[i] - Xs[j]) <= EPSILON)
                axisX += 1;
            if (abs(Ys[i] - Ys[j]) <= EPSILON)
                axisY += 1;
            if (abs(Zs[i] - Zs[j]) <= EPSILON)
                axisZ += 1;
        }
    }

    if (axisX > axisY && axisX > axisZ)
        return 0;
    if (axisY > axisX && axisY > axisZ)
        return 1;
    return 2;
}

bool GeoCalculator::CompareNodeOrder(
    const Node &node0, const Node &node1, const Coordinate &centroid, int ignoredAxis)
{
    Coordinate n0, n1, o;
    if (ignoredAxis == 2)
    {
        n0 = {node0.coor.x, node0.coor.y, 0};
        n1 = {node1.coor.x, node1.coor.y, 0};
        o  = {centroid.x, centroid.y, 0};
    }
    else if (ignoredAxis == 1)
    {
        n0 = {node0.coor.x, node0.coor.z, 0};
        n1 = {node1.coor.x, node1.coor.z, 0};
        o  = {centroid.x, centroid.z, 0};
    }
    else
    {
        n0 = {node0.coor.y, node0.coor.z, 0};
        n1 = {node1.coor.y, node1.coor.z, 0};
        o  = {centroid.y, centroid.z, 0};
    }

    if (n0.x >= 0 && n1.x < 0)
        return true;

    if (n0.x == 0 && n1.x == 0)
        return n0.y > n1.y;

    double dx0 = n0.x - o.x, dx1 = n1.x - o.x;
    double dy1 = n0.y - o.y, dy0 = n1.y - o.y;
    int    det = dx0 * dy1 - dx1 * dy0;
    if (det < 0)
        return true;
    if (det > 0)
        return false;

    int dist0 = dx0 * dx0 + dy0 * dy0;
    int dist1 = dx1 * dx1 + dy1 * dy1;
    return dist0 > dist1;
}

Coordinate GeoCalculator::CalculateCentroid(
    const vector<int> &nodeIdxs, const unordered_map<int, Node> &nodes)
{
    if (nodeIdxs.empty())
        return {};

    double sumX = 0., sumY = 0., sumZ = 0.;
    for (int idx : nodeIdxs)
    {
        sumX += nodes.at(idx).coor.x;
        sumY += nodes.at(idx).coor.y;
        sumZ += nodes.at(idx).coor.z;
    }

    double size = double(nodeIdxs.size());
    return {sumX / size, sumY / size, sumZ / size};
}

Coordinate GeoCalculator::CalculateFaceCentroid(int faceIdx, const Mesh &mesh)
{
    return CalculateCentroid(mesh.faces.at(faceIdx).nodeIndexes, mesh.nodes);
}

Coordinate GeoCalculator::CalculateCellCentroid(int cellIdx, const Mesh &mesh)
{
    return CalculateCentroid(GetCellNodeIndexes(cellIdx, mesh), mesh.nodes);
}

vector<int> GeoCalculator::GetCellNodeIndexes(int cellIdx, const Mesh &mesh)
{
    set<int> nodeIdxs;

    for (int faceIdx : mesh.cells.at(cellIdx).faceIndexes)
    {
        for (int nodeIdx : mesh.faces.at(faceIdx).nodeIndexes)
        {
            nodeIdxs.emplace(nodeIdx);
        }
    }

    vector<int> idxs(nodeIdxs.begin(), nodeIdxs.end());
    return idxs;
}

array<double, 3> GeoCalculator::CalculateNormal(
    const vector<int> &nodeIdxs, const unordered_map<int, Node> &nodes)
{
    int size = nodeIdxs.size();

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

array<double, 3> GeoCalculator::CalculateFaceNormal(int faceIdx, const Mesh &mesh)
{
    return CalculateNormal(mesh.faces.at(faceIdx).nodeIndexes, mesh.nodes);
}

double GeoCalculator::CalculateArea(
    const Vector<double, 3> &normal, const vector<int> &nodeIdxs,
    const unordered_map<int, Node> &nodes)
{
    int size = nodeIdxs.size();

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

    double zCos = normal * z;
    double xCos = normal * x;
    double yCos = normal * y;

    double area = 0.0;
    for (int i = 0; i < size - 1; ++i)
    {
        const auto &node0 = nodes.at(nodeIdxs[i]).coor;
        const auto &node1 = nodes.at(nodeIdxs[i + 1]).coor;

        area += zCos * (node0.x * node1.y - node0.y * node1.x);
        area += xCos * (node0.y * node1.z - node0.z * node1.y);
        area += yCos * (node0.z * node1.x - node0.x * node1.z);
    }

    return abs(area) / 2.0;
}

double GeoCalculator::CalculateFaceArea(int faceIdx, const Mesh &mesh)
{
    const auto &face = mesh.faces.at(faceIdx);
    return CalculateArea(face.normal, face.nodeIndexes, mesh.nodes);
}

double GeoCalculator::CalculateLength(const Node &node0, const Node &node1)
{
    const auto &vec = ToVector(node0, node1);
    return vec.Length();
}

double GeoCalculator::CalculateFacePerimeter(int faceIdx, const Mesh &mesh)
{
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

double GeoCalculator::CalculateVolume(
    const std::vector<int> &nodeIdxs, const std::unordered_map<int, Node> &nodes)
{
    // Only tetrahedral and prismatic volume calculations are supported.

    int size = nodeIdxs.size();

    // tetrahedral cell.
    if (size == 4)
    {
        const auto &v1 = ToVector(nodes.at(nodeIdxs[0]), nodes.at(nodeIdxs[1]));
        const auto &v2 = ToVector(nodes.at(nodeIdxs[0]), nodes.at(nodeIdxs[2]));
        const auto &v3 = ToVector(nodes.at(nodeIdxs[0]), nodes.at(nodeIdxs[3]));

        double vol = ((v1 & v2) * v3) / 6.0;
        return vol;
    }
    else
    {
        throw NotImplementedException();
    }
}

double GeoCalculator::CalculateCellVolume(int cellIdx, const Mesh &mesh)
{
    const auto &nodeIdxs = GetCellNodeIndexes(cellIdx, mesh);
    return CalculateVolume(nodeIdxs, mesh.nodes);
}

Vector<double, 3> GeoCalculator::ToVector(const Node &start, const Node &end)
{
    const auto &node0 = start.coor;
    const auto &node1 = end.coor;

    return {node1.x - node0.x, node1.y - node0.y, node1.z - node0.z};
}

}  // namespace OpenOasis::CommImpl::Spatial