#include "OasisFluidsModule.h"
#include "OasisFluidsVersion.h"
#include "Cores/SystFluids/Hydrologics/RainfallModule.h"
#include "Cores/SystFluids/Hydrologics/RunoffModule.h"
#include "Cores/SystFluids/Hydrologics/RiverModule.h"


using namespace OpenOasis::SystFluids::Hydrologics;
using namespace std;

static vector<shared_ptr<OpenOasis::ILinkableComponent>> componenents;

const char *GetFluidPackageVersion()
{
    return VERSION_STR;
}

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