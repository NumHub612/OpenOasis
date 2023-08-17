#include "Tools/Catch2/catch.hpp"
#include "Cores/Utils/YamlHandler.h"
#include <iostream>

using namespace OpenOasis::Utils;
using namespace std;


TEST_CASE("YamlLoader tests")
{
    const string path =
        "D:\\4_resource\\oasis_examples\\heat_conduction_model\\settings.yaml";

    /*
    scalar: hello world
    list:
      item: "foo bar"
      boolean: true
      integer: 123
      floating point: 2.75
    arr: [1, 2, 3]
    */

    YamlLoader loader(path);

    vector<string> keys = loader.GetKeys({});
    REQUIRE(keys.size() == 3);

    vector<string> keys2 = loader.GetKeys({"list"});
    REQUIRE(keys2.size() == 4);

    string value1 = loader.GetValue<string>({}, "scalar").value();
    REQUIRE(value1 == "hello world");

    auto res0 = loader.GetValue<bool>({"list"}, "boolean");
    REQUIRE(res0.has_value());

    bool state = loader.GetValue<bool>({"list"}, "boolean").value();
    REQUIRE(state == true);

    int value2 = loader.GetValue<int>({"list"}, "integer").value();
    REQUIRE(value2 == 123);

    auto &res = loader.GetArray<int>({}, "arr");
    REQUIRE(res.has_value());

    vector<int> arr = loader.GetArray<int>({}, "arr").value();
    REQUIRE(arr.size() == 3);
    REQUIRE(arr[0] == 1);
}
