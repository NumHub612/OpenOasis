/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  GeoCalculator.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  A collection of general geometry functions.
 *
 ** ***********************************************************************************/
#pragma once
#include "MeshStructs.h"
#include "Cores/CommImpl/Numeric/Vector.h"


namespace OpenOasis
{
namespace CommImpl
{
namespace Spatial
{
using namespace Numeric;

/// @brief The GeoCalculator is a collection of general geometry functions.
class GeoCalculator final
{
public:
    static constexpr double EPSILON = 1.0e-5;

    static std::vector<int> GetCellNodeIndexes(int cellIdx, const Mesh &mesh);

    /// @brief Sortes the specified Nodes counterclockwise.
    /// @param nodeIdxs The Node indexes.
    /// @param nodes The Nodes map.
    /// @return The sorted Node indexes.
    static std::vector<int> SortNodes(
        const std::vector<int> &nodeIdxs, const std::unordered_map<int, Node> &nodes);

    static std::vector<int> SortFaceNodes(int faceIndex, const Mesh &mesh);

    /// @brief Calculates the centroid.
    /// @param nodeIdxs Node indexes.
    /// @param nodes The Nodes map.
    /// @return Centroid.
    static Coordinate CalculateCentroid(
        const std::vector<int> &nodeIdxs, const std::unordered_map<int, Node> &nodes);

    static Coordinate CalculateFaceCentroid(int faceIdx, const Mesh &mesh);

    static Coordinate CalculateCellCentroid(int cellIdx, const Mesh &mesh);

    /// @brief Calculates the plane(2d or 3d) unit normal vector.
    /// @param nodeIdxs The clock- or counter- clockwise ordered Node indexes.
    /// @param nodes The Nodes map.
    /// @return Unit normal vector.
    static std::array<double, 3> CalculateNormal(
        const std::vector<int> &nodeIdxs, const std::unordered_map<int, Node> &nodes);

    static std::array<double, 3> CalculateFaceNormal(int faceIdx, const Mesh &mesh);

    /// @brief Calculates the plane(2d or 3d) area.
    /// @param normal The unit normal vector of the plane.
    /// @param nodeIdxs The clock- or counter- clockwise ordered Node indexes.
    /// @param nodes The Node map.
    /// @return Area of the plane.
    static double CalculateArea(
        const Vector<double, 3> &normal, const std::vector<int> &nodeIdxs,
        const std::unordered_map<int, Node> &nodes);

    static double CalculateFaceArea(int faceIdx, const Mesh &mesh);

    /// @brief Calculates the distance between two Nodes.
    /// @param node0 The endpoint.
    /// @param node1 The endpoint.
    /// @return The length.
    static double CalculateLength(const Node &node0, const Node &node1);

    static double CalculateFacePerimeter(int faceIdx, const Mesh &mesh);

    /// @brief Calculates the volume of a polygon pyramid.
    /// @param nodeIdxs The Node indexes.
    /// @param nodes The Node map.
    /// @return Volume.
    static double CalculateVolume(
        const std::vector<int> &nodeIdxs, const std::unordered_map<int, Node> &nodes);

    static double CalculateCellVolume(int cellIdx, const Mesh &mesh);

private:
    static Vector<double, 3> ToVector(const Node &start, const Node &stop);

    static int ChooseFoldedAxis(
        const std::vector<int> &nodeIdxs, const std::unordered_map<int, Node> &nodes);

    static bool CompareNodeOrder(
        const Node &node0, const Node &node1, const Coordinate &centroid,
        int ignoredAxis);
};

}  // namespace Spatial
}  // namespace CommImpl
}  // namespace OpenOasis