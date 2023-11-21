#include "OasisHeatsModule.h"
#include "OasisHeatsVersion.h"
#include "Cores/SystHeats/HeatConductionModel/HeatConductionModel.h"


using namespace OpenOasis::SystHeats;
using namespace std;


static vector<shared_ptr<OpenOasis::ILinkableComponent>> componenents;

const char *GetHeatPackageVersion()
{
    return VERSION_STR;
}

void *GetHeatConductionModule(const char *id, const char *taskFile)
{
    auto comp = make_shared<HeatConductionModel>(id, taskFile);
    componenents.push_back(comp);

    return comp.get();
}