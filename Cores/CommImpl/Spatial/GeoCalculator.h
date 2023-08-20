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

    static Coordinate CalculateFaceCentroid(int faceIdx, const Mesh &mesh);

    static std::array<double, 3> CalculateFaceNormal(int faceIdx, const Mesh &mesh);

    static double CalculateFaceArea(int faceIdx, const Mesh &mesh);

    static double CalculateFacePerimeter(int faceIdx, const Mesh &mesh);

    static double CalculateCellVolume(int cellIdx, const Mesh &mesh);

    static Vector<double, 3> ToVector(const Node &start, const Node &stop);
};

}  // namespace Spatial
}  // namespace CommImpl
}  // namespace OpenOasis