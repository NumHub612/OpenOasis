#include "Tools/Catch2/catch.hpp"


TEST_CASE("Heats dummy test")
{
    SECTION("function test")
    {
        REQUIRE(3 == 3);
    }
}