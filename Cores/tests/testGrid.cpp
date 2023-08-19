#include "Tools/Catch2/catch.hpp"
#include "Cores/CommImpl/Spatial/Grid.h"

using namespace std;
using namespace OpenOasis::CommImpl::Spatial;


TEST_CASE("Grid tests")
{
    const string meshDir =
        "D:\\4_resource\\oasis_examples\\heat_conduction_model\\geom";

    SECTION("mesh loading test")
    {
        Grid grid(meshDir);
    }
}