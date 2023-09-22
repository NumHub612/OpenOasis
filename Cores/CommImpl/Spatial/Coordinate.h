/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  Coordinate.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  The Coordinate struct contains a (x,y,z,m) coordinate.
 *
 ** ***********************************************************************************/
#pragma once
#include <cmath>


namespace OpenOasis
{
namespace CommImpl
{
namespace Spatial
{
/// @brief The Coordinate struct contains a (x,y,z,m) coordinate.
///
/// The default coordinate is filled with NAN.
struct Coordinate
{
    double x = NAN;
    double y = NAN;
    double z = NAN;
    double m = NAN;

    bool Equals(double coorX, double coorY, double coorZ) const;
    bool Equals(const Coordinate &coor) const;
    bool HasZ() const;
    bool HasM() const;
};

}  // namespace Spatial
}  // namespace CommImpl
}  // namespace OpenOasis