#include "OasisFlows.h"
#include "Model/SystFluids/Hydrologics/RainfallModule.h"
#include "Model/SystFluids/Hydrologics/RunoffModule.h"
#include "Model/SystFluids/Hydrologics/RiverModule.h"
#include "Model/SystHeats/HeatConductionModel/HeatConductionModel.h"


using namespace OpenOasis::SystFluids::Hydrologics;
using namespace OpenOasis::SystHeats;
using namespace std;

static vector<shared_ptr<OpenOasis::ILinkableComponent>> componenents;

void *GetComponent(const char *id, const char *task)
{
    return nullptr;
}