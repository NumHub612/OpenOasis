#include "OasisFlows.h"
#include "Model/SystHeats/HeatConductionModel/HeatConductionModel.h"


// using namespace OpenOasis::SystFluids::Hydrologics;
using namespace OpenOasis::SystHeats;
using namespace std;

static vector<shared_ptr<OpenOasis::ILinkableComponent>> componenents;


void *GetHeatConductionComp(const char *id, const char *taskFile);


static unordered_map<string, function<void *(const char *, const char *)>>
    componentFactory = {{"HeatConductionComp", GetHeatConductionComp}};


void *GetComponent(const char *id, const char *type, const char *task)
{
    if (componentFactory.count(type) == 1)
    {
        return componentFactory[type](id, task);
    }

    return nullptr;
}

void *GetHeatConductionComp(const char *id, const char *taskFile)
{
    auto comp = make_shared<HeatConductionModel>(id, taskFile);
    componenents.push_back(comp);

    return comp.get();
}