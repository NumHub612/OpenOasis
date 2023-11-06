#include "Tools/Catch2/catch.hpp"
#include "Cores/CommImpl/Numeric/Matrix.h"

using namespace OpenOasis::CommImpl::Numeric;
using namespace std;


TEST_CASE("Matrix template test")
{
    SECTION("constructor test")
    {
        Matrix<double> mat(3, 3);
    }
}