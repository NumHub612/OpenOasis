/** ***********************************************************************************
 *    Copyright (C) 2024, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  Geom.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Definitions of plane geometry related structures.
 *
 ** ***********************************************************************************/
#pragma once
#include "Coordinate.h"
#include <vector>
#include <array>


namespace OpenOasis::CommImp::Spatial
{
using Point    = Coordinate;
using Line     = std::array<Point, 2>;
using Polyline = std::vector<Point>;
using Polygon  = std::vector<Point>;

}  // namespace OpenOasis::CommImp::Spatial