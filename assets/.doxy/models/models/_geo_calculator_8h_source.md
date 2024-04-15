

# File GeoCalculator.h

[**File List**](files.md) **>** [**CommImp**](dir_6202b98a8704f42b1ea358646461643f.md) **>** [**Spatial**](dir_47a0bcc12c466f07097ed8db741700fa.md) **>** [**GeoCalculator.h**](_geo_calculator_8h.md)

[Go to the documentation of this file](_geo_calculator_8h.md)


```C++

#pragma once
#include "MeshStructs.h"
#include "Models/CommImp/Numeric/Vector.h"


namespace OpenOasis
{
namespace CommImp
{
namespace Spatial
{
using namespace Numeric;
using Utils::real;

class GeoCalculator final
{
public:
    static constexpr real EPSILON = 1.0e-5;

    static std::vector<int> GetCellNodeIndexes(int cellIdx, const Mesh &mesh);

    static std::vector<int> SortNodes(
        const std::vector<int> &nodeIdxs, const std::unordered_map<int, Node> &nodes);

    static std::vector<int> SortFaceNodes(int faceIndex, const Mesh &mesh);

    static Coordinate CalculateCentroid(
        const std::vector<int> &nodeIdxs, const std::unordered_map<int, Node> &nodes);

    static Coordinate CalculateFaceCentroid(int faceIdx, const Mesh &mesh);

    static Coordinate CalculateCellCentroid(int cellIdx, const Mesh &mesh);

    static std::array<real, 3> CalculateNormal(
        const std::vector<int> &nodeIdxs, const std::unordered_map<int, Node> &nodes);

    static std::array<real, 3> CalculateFaceNormal(int faceIdx, const Mesh &mesh);

    static real CalculateArea(
        const Vector<real, 3> &normal, const std::vector<int> &nodeIdxs,
        const std::unordered_map<int, Node> &nodes);

    static real CalculateFaceArea(int faceIdx, const Mesh &mesh);

    static real CalculateLength(const Node &node0, const Node &node1);

    static real CalculateFacePerimeter(int faceIdx, const Mesh &mesh);

    static real CalculateVolume(
        const std::vector<int> &nodeIdxs, const std::unordered_map<int, Node> &nodes);

    static real CalculateCellVolume(int cellIdx, const Mesh &mesh);

private:
    static Vector<real, 3> ToVector(const Node &start, const Node &stop);

    static int ChooseFoldedAxis(
        const std::vector<int> &nodeIdxs, const std::unordered_map<int, Node> &nodes);

    static bool CompareNodeOrder(
        const Node &node0, const Node &node1, const Coordinate &centroid,
        int ignoredAxis);
};

}  // namespace Spatial
}  // namespace CommImp
}  // namespace OpenOasis
```


