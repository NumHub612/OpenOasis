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
    return Equals({coorX, coorY, coorZ});
}

bool Coordinate::Equals(const Coordinate &coor) const
{
    if (!IsEqual(x, coor.x) || !IsEqual(y, coor.y) || !IsEqual(z, coor.z)) return false;

    return true;
}

}  // namespace OpenOasis::CommImpl::Spatial
