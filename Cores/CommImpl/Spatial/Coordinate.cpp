/** ***********************************************************************************
 *    @File      :  Coordinate.cpp
 *    @Brief     :  None.
 *
 ** ***********************************************************************************/
#include "Coordinate.h"


namespace OpenOasis::CommImpl::Spatial
{
bool Coordinate::Equals(const Coordinate &coor) const
{
    return (x == coor.x && y == coor.y && z == coor.z);
}

bool Coordinate::Equals(double coorX, double coorY, double coorZ) const
{
    return (x == coorX && y == coorY && z == coorZ);
}

}  // namespace OpenOasis::CommImpl::Spatial
