/** ***********************************************************************************
 *    @File      :  DirichletBoundary.cpp
 *    @Brief     :  Dirichlet boundary.
 *
 ** ***********************************************************************************/
#include "DirichletBoundary.h"


namespace OpenOasis::CommImpl::Numeric
{
using namespace std;


DirichletBoundary::DirichletBoundary()
{
    mData.type = "DIRICHLET";
}

DirichletBoundary::DirichletBoundary(double value)
{
    mData = {"DIRICHLET", value};
}

DirichletBoundary::DirichletBoundary(const DirichletBoundary &other)
{
    mData = other.mData;
}

void DirichletBoundary::SetBoundaryValue(double value)
{
    mData.value = value;
}

void DirichletBoundary::SetBoundaryFlux(double flux)
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