#include "Tools/Catch2/catch.hpp"
#include "Cores/Utils/JsonHandler.h"
#include <iostream>

using namespace OpenOasis::Utils;
using namespace std;


TEST_CASE("JsonLoader tests")
{
    const string path = "D:\\4_resource\\oasis_examples\\configs.json";

    /*
    {
    "pi": 3.141,
    "happy": true,
    "name": "Niels",
    "nothing": null,
    "answer": {
        "everything": 42,
        "something": 22
    },
    "list": [
        1,
        0,
        2
    ],
    "object": {
        "currency": "USD",
        "value": 42.99
    }
    }
    */

    JsonLoader loader(path);

    const auto &keys0 = loader.GetKeys({});  // answer,happy,list,name,nothing,object,pi
    REQUIRE(keys0.size() == 7);
    REQUIRE(keys0[0] == "answer");

    const auto &keys1 = loader.GetKeys({keys0[0]});
    REQUIRE(keys1.size() == 2);

    const auto &keys2 = loader.GetKeys({keys0[1]});
    REQUIRE(keys2.size() == 0);

    bool isnull = loader.IsNull({}, "nothing");
    REQUIRE(isnull);

    double pi = loader.GetValue<double>({}, "pi").value();
    REQUIRE(pi == 3.141);

    double value = loader.GetValue<double>({"object"}, "value").value();
    REQUIRE(value == 42.99);

    auto res = loader.GetArray<int>({}, "list");
    REQUIRE(res.has_value() == true);

    auto arr = loader.GetArray<int>({}, "list").value();
    REQUIRE(arr.size() == 3);
    REQUIRE(arr[0] == 1);
}


TEST_CASE("JsonWriter tests")
{
    const string path = "D:\\4_resource\\oasis_examples";

    JsonWriter writer(path);

    writer.SetValue<double>({}, "pi", 3.1415926);
    writer.SetValue<bool>({}, "happy", true);
    writer.SetValue<string>({}, "name", "mike");
    writer.SetValue<int>({}, "nothing", 12);

    writer.SetValue<int>({"answer"}, "everything", 42);
    writer.SetValue<int>({"answer"}, "something", 22);
    writer.SetValue<string>({"answer"}, "desc", "field");

    writer.SetValue<string>({"key0", "key1"}, "key2", "value");

    writer.SetArray<int>({}, "array", {12, 13, 14});
    writer.SetArray<string>({}, "object", {"currency", "USD"});

    writer.SetArray<double>({}, "empty_list2", {});

    writer.Save();
}
