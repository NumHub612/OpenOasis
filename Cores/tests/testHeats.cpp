#include "Tools/Catch2/catch.hpp"
#include "Cores/SystHeats/demo/heats.h"


TEST_CASE("Heats dummy test")
{
    REQUIRE(2 == oasis_plus(1, 2));
}