#include "OasisFlows.h"
// #include "Model/SystFluids/Hydrologics/RainfallModule.h"
#include "Model/SystFluids/Hydrologics/RunoffModule.h"
#include "Model/SystFluids/Hydrologics/RiverModule.h"
#include "Model/SystHeats/HeatConductionModel/HeatConductionModel.h"


using namespace OpenOasis::SystFluids::Hydrologics;
using namespace OpenOasis::SystHeats;
using namespace std;

static vector<shared_ptr<OpenOasis::ILinkableComponent>> componenents;


void *GetRunoffComp(const char *id, const char *taskFile);
void *GetRiverComp(const char *id, const char *taskFile);
void *GetHeatConductionComp(const char *id, const char *taskFile);


static unordered_map<string, function<void *(const char *, const char *)>>
    componentFactory = {
        {"RunoffComp", GetRunoffComp},
        {"RiverComp", GetRiverComp},
        {"HeatConductionComp", GetHeatConductionComp}};


void *GetComponent(const char *id, const char *type, const char *task)
{
    if (componentFactory.count(type) == 1)
    {
        return componentFactory[type](id, task);
    }

    return nullptr;
}

void *GetRunoffComp(const char *id, const char *taskFile)
{
    auto comp = make_shared<RunoffModule>(id, taskFile);
    componenents.push_back(comp);

    return comp.get();
}

void *GetRiverComp(const char *id, const char *taskFile)
{
    auto comp = make_shared<RiverModule>(id);
    componenents.push_back(comp);

    return comp.get();
}

void *GetHeatConductionComp(const char *id, const char *taskFile)
{
    auto comp = make_shared<HeatConductionModel>(id, taskFile);
    componenents.push_back(comp);

    return comp.get();
}