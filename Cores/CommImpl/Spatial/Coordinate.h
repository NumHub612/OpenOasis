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


namespace OpenOasis::CommImpl::Spatial
{
/// @brief The Coordinate struct contains a (x, y, z) coordinate.
struct Coordinate
{
    double x = 0.;
    double y = 0.;
    double z = 0.;

    bool Equals(double coorX, double coorY, double coorZ) const;
    bool Equals(const Coordinate &coor) const;
};

}  // namespace OpenOasis::CommImpl::Spatial