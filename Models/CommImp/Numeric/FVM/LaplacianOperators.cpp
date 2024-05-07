/** ***********************************************************************************
 *    @File      :  LaplacianOperators.cpp
 *    @Brief     :  Laplacian Operators.
 *
 ** ***********************************************************************************/
#include "LaplacianOperators.h"
#include "Models/Utils/Exception.h"


namespace OpenOasis::CommImp::Numeric::FVM
{
using namespace std;
using namespace Utils;


// ------------------------------------------------------------------------------------

static const string LAPLACIAN01 = "FvmLaplacian01";


REGISTER_CLS(FvmOperator, Laplacian01, LAPLACIAN01)


// ------------------------------------------------------------------------------------

string Laplacian01::GetName()
{
    return LAPLACIAN01;
}

LinearEqs Laplacian01::Discretize(
    const ScalarFieldFp &varCellField, const ScalarFieldFp &varFaceField)
{}


}  // namespace OpenOasis::CommImp::Numeric::FVM