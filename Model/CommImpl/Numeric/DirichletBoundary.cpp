/** ***********************************************************************************
 *    @File      :  DirichletBoundary.cpp
 *    @Brief     :  Dirichlet boundary.
 *
 ** ***********************************************************************************/
#include "DirichletBoundary.h"


namespace OpenOasis::CommImpl::Numeric
{
using namespace std;
using namespace Utils;

DirichletBoundary::DirichletBoundary()
{
    mData.type = "DIRICHLET";
}

DirichletBoundary::DirichletBoundary(real value)
{
    mData = {"DIRICHLET", value};
}

DirichletBoundary::DirichletBoundary(const DirichletBoundary &other)
{
    mData = other.mData;
}

void DirichletBoundary::SetBoundaryValue(real value)
{
    mData.value = value;
}

void DirichletBoundary::SetBoundaryFlux(real flux)
{
    mData.flux = flux;
}

string DirichletBoundary::GetType() const
{
    return "Dirichlet";
}

BoundaryCondition DirichletBoundary::GetBoundaryCondition()
{
    return mData;
}

}  // namespace OpenOasis::CommImpl::Numeric