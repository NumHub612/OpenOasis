#include "Tools/Catch2/catch.hpp"
#include "Cores/SystHeats/HeatConductionModel/HeatConductionModel.h"

using namespace std;
using namespace OpenOasis::SystHeats;


TEST_CASE("Heats dummy test")
{
    SECTION("function test")
    {
        string path =
            "D:\\4_resource\\oasis_examples\\heat_conduction_model\\settings.yaml";

        HeatConductionModel model("heat", path);
        printf("created\n");
        model.Initialize();
        printf("inited\n");
        model.Validate();
        printf("valied\n");
        model.Prepare();
        printf("prepared\n");

        while (model.GetStatus() != OpenOasis::LinkableComponentStatus::Done
               && model.GetStatus() != OpenOasis::LinkableComponentStatus::Failed)
        {
            model.Update({});
            printf("updated\n");
        }

        model.Finish();
        printf("finished\n");
    }
}