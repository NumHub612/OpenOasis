#include "OasisFlows.h"
#include "Model/SystFluids/Hydrologics/RainfallModule.h"
#include "Model/SystFluids/Hydrologics/RunoffModule.h"
#include "Model/SystFluids/Hydrologics/RiverModule.h"
#include "Model/SystHeats/HeatConductionModel/HeatConductionModel.h"


using namespace OpenOasis::SystFluids::Hydrologics;
using namespace OpenOasis::SystHeats;
using namespace std;

static vector<shared_ptr<OpenOasis::ILinkableComponent>> componenents;


void *GetRainfallModule(const char *id, const char *coorFile, const char *dataFile)
{
    auto comp = make_shared<RainfallModule>(id, coorFile, dataFile);
    componenents.push_back(comp);

    return comp.get();
}

void *GetRunoffModule(const char *id, const char *taskFile)
{
    auto comp = make_shared<RunoffModule>(id, taskFile);
    componenents.push_back(comp);

    return comp.get();
}

void *GetRiverModule(const char *id)
{
    auto comp = make_shared<RiverModule>(id);
    componenents.push_back(comp);

    return comp.get();
}

void *GetHeatConductionModule(const char *id, const char *taskFile)
{
    auto comp = make_shared<HeatConductionModel>(id, taskFile);
    componenents.push_back(comp);

    return comp.get();
}