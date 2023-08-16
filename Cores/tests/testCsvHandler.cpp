#include "Tools/Catch2/catch.hpp"
#include "Cores/Utils/CsvHandler.h"

using namespace OpenOasis::Utils;
using namespace std;


TEST_CASE("CsvLoader tests")
{
    const string path =
        "D:\\4_resource\\oasis_examples\\heat_conduction_model\\geom\\test.csv";

    SECTION("test0")
    {
        CsvLoader loader(path);

        REQUIRE(loader.GetColumnCount() == 6);
        REQUIRE(loader.GetRowCount() == 5);

        const auto row2 = loader.GetRow<double>(1).value();
        REQUIRE(row2.size() == 6);
        REQUIRE(row2[2] == 64.190002);

        const auto col3 = loader.GetColumn<double>(2).value();
        REQUIRE(col3.size() == 5);
        REQUIRE(col3[2] == 64.050003);
    }

    SECTION("test1")
    {
        CsvLoader loader(path, true, false);

        const auto dates = loader.GetColumnAsDateTime(0).value();
        REQUIRE(dates.size() == 5);
        REQUIRE(DateTime::ToString(dates[0]) == "2017-02-24 00:00:00.0");
    }
}


TEST_CASE("CsvWriter tests")
{
    const string path = "D:\\4_resource\\oasis_examples\\heat_conduction_model\\geom";

    SECTION("column write")
    {
        CsvWriter writer(path);

        writer.InsertColumn<string>(0, "col0", {"1", "2", "3"});
        writer.InsertColumn<string>(1, "col1", {"1", "2", "3"});
        writer.InsertColumn<int>(2, "col2", {1, 2, 3});
        writer.InsertColumn<double>(3, "col3", {1.1, 2.2, 3.3});

        writer.SetRowLabel(0, "row1");
        writer.SetRowLabel(1, "row2");
        writer.SetRowLabel(2, "row3");

        writer.Save();

        const auto file2 = writer.GetOutputFilePath();
        CsvLoader  loader(file2);
        REQUIRE(loader.GetColumnCount() == 4);

        const auto labels = loader.GetColumnLabels().value();
        REQUIRE(labels[0] == "col0");
    }

    SECTION("row write")
    {
        CsvWriter writer(path);

        writer.InsertRow<string>(0, "row0", {"1", "2", "3"});
        writer.InsertRow<string>(1, "row1", {"1", "2", "3"});
        writer.InsertRow<int>(2, "row2", {1, 2, 3});
        writer.InsertRow<double>(3, "row3", {1.1, 2.2, 3.3});

        writer.SetColumnLabel(0, "col1");
        writer.SetColumnLabel(1, "col2");
        writer.SetColumnLabel(2, "col3");

        writer.Save();

        const auto file2 = writer.GetOutputFilePath();
        CsvLoader  loader(file2);
        REQUIRE(loader.GetColumnCount() == 3);

        const auto labels = loader.GetColumnLabels().value();
        REQUIRE(labels[0] == "col1");
    }
}
