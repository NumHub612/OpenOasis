#include "ThirdPart/Catch2/catch.hpp"
#include "Models/Utils/FilePathHelper.h"
#include "Models/Utils/CsvHandler.h"
#include "Models/SystHeats/HeatConductionModel/HeatConductionModel.h"

using namespace std;
using namespace OpenOasis::SystHeats;
using namespace OpenOasis::Utils;

#ifndef PROJECT_DIR
#define PROJECT_DIR "."
#endif


TEST_CASE("Heats dummy test")
{
    SECTION("function test")
    {
        string file = FilePathHelper::Combine(
            PROJECT_DIR, "Rsrc/Benchmarks/heat_conduction_model/task.yaml");

        HeatConductionModel model("heat", file);

        // model.Initialize();
        // model.Validate();
        // model.Prepare();

        // while (model.GetStatus() != OpenOasis::LinkableComponentStatus::Done
        //        && model.GetStatus() != OpenOasis::LinkableComponentStatus::Failed)
        // {
        //     model.Update();
        // }

        // model.Finish();

        // string ref_file = FilePathHelper::Combine(
        //     PROJECT_DIR,
        //     "Rsrc/Benchmarks/heat_conduction_model/assets/validation.csv");

        // string simu_file =
        //     FilePathHelper::GetFullPath("./outputs/heat_conduction_result.csv");

        // auto simu_res = CsvLoader(simu_file).GetColumn<double>(0).value();
        // auto ref_res  = CsvLoader(ref_file).GetColumn<double>(0).value();

        // REQUIRE(simu_res.size() == ref_res.size());
        // for (size_t i = 0; i < simu_res.size(); ++i)
        // {
        //     REQUIRE(simu_res[i] == Approx(ref_res[i]).margin(1e-5));
        // }
    }
}