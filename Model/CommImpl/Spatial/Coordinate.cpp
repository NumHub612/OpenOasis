/** ***********************************************************************************
 *    @File      :  Coordinate.cpp
 *    @Brief     :  None.
 *
 ** ***********************************************************************************/
#include "Coordinate.h"
#include "Model/Utils/CommConstants.h"


namespace OpenOasis::CommImpl::Spatial
{
using namespace std;

bool Coordinate::Equals(double coorX, double coorY, double coorZ) const
{
    return Equals({coorX, coorY, coorZ});
}

bool Coordinate::Equals(const Coordinate &coor) const
{
    if (!IsEql(x, coor.x) || !IsEql(y, coor.y) || !IsEql(z, coor.z))
        return false;

    return true;
}

}  // namespace OpenOasis::CommImpl::Spatial
