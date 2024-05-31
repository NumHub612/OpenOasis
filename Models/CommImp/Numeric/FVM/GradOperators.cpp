/** ***********************************************************************************
 *    @File      :  GradOperators.cpp
 *    @Brief     :  Gradient operators for FVM.
 *
 ** ***********************************************************************************/
#include "GradOperators.h"
#include "Models/Utils/Exception.h"


namespace OpenOasis::CommImp::Numeric::FVM
{
using namespace std;
using namespace Utils;


// ------------------------------------------------------------------------------------

static const string GRAD01 = "FvmGrad01";


REGISTER_CLS(FvmOperator, Grad01, GRAD01)


// ------------------------------------------------------------------------------------

string Grad01::GetName()
{
    return GRAD01;
}

void Grad01::Prepare()
{}

LinearEqs Grad01::Discretize()
{
    Matrix<real> A(1);
    vector<real> b(1);

    return LinearEqs(A, b);
}


}  // namespace OpenOasis::CommImp::Numeric::FVM