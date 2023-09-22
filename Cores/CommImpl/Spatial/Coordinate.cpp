/** ***********************************************************************************
 *    @File      :  Coordinate.cpp
 *    @Brief     :  None.
 *
 ** ***********************************************************************************/
#include "Coordinate.h"
#include "Cores/Utils/CommConstants.h"


namespace OpenOasis::CommImpl::Spatial
{
using namespace std;

bool Coordinate::Equals(double coorX, double coorY, double coorZ) const
{
    return (IsEqual(x, coorX) && IsEqual(y, coorY) && IsEqual(z, coorZ));
}

bool Coordinate::Equals(const Coordinate &coor) const
{
    if (!IsEqual(x, coor.x) || !IsEqual(y, coor.y))
        return false;

    if ((HasZ() && !coor.HasZ()) || (!HasZ() && coor.HasZ()))
        return false;

    if ((HasM() && !coor.HasM()) || (!HasM() && coor.HasM()))
        return false;

    return true;
}

bool Coordinate::HasZ() const
{
    return IsNan(z);
}

bool Coordinate::HasM() const
{
    return IsNan(m);
}


}  // namespace OpenOasis::CommImpl::Spatial
