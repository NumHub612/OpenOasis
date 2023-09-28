#include "OasisFluidsModule.h"
#include "VersionConfig.h"
#include "Cores/SystFluids/HydrologicComps/RainfallModule.h"
#include "Cores/SystFluids/HydrologicComps/RunoffModule.h"
#include "Cores/SystFluids/HydrologicComps/RiverModule.h"


using namespace OpenOasis::SystFluids;
using namespace std;

static vector<shared_ptr<OpenOasis::ILinkableComponent>> componenents;

const char *GetFluidPackageVersion()
{
    return VERSION_STR;
}

void *GetRainfallModule(const char *id, const char *coorFile, const char *dataFile)
{
    auto comp = make_shared<HydrologicComps::RainfallModule>(id, coorFile, dataFile);
    componenents.push_back(comp);

    return comp.get();
}

void *GetRunoffModule(const char *id, const char *taskFile)
{
    auto comp = make_shared<HydrologicComps::RunoffModule>(id, taskFile);
    componenents.push_back(comp);

    return comp.get();
}

void *GetRiverModule(const char *id)
{
    auto comp = make_shared<HydrologicComps::RiverModule>(id);
    componenents.push_back(comp);

    return comp.get();
}