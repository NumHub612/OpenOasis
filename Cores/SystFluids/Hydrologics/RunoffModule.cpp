/** ***********************************************************************************
 *    @File      :  RunoffModule.cpp
 *    @Brief     :  Runoff module.
 *
 ** ***********************************************************************************/
#include "RunoffModule.h"
#include "Cores/CommImpl/Arguments.h"
#include "Cores/CommImpl/Time.h"
#include "Cores/CommImpl/Dimension.h"
#include "Cores/CommImpl/Unit.h"
#include "Cores/CommImpl/Quantity.h"
#include "Cores/CommImpl/IO/logging.h"
#include "Cores/Utils/StringHelper.h"
#include "Cores/Utils/FilePathHelper.h"
#include "Cores/Utils/Exception.h"
#include "Cores/Utils/StreamReader.h"


namespace OpenOasis::SystFluids::Hydrologics
{
using namespace Spatial;
using namespace Utils;
using namespace std;


// class RunoffModule------------------------------------------------------------------

RunoffModule::RunoffModule(const RunoffModule &obj) : LinkableComponent(obj.GetId())
{
    mCaption     = "Rainfall module";
    mDescription = "Rainfall module used for providing rain intensity data";

    mRequiredArguments = {"ID", "task_file"};
    mArguments["ID"]   = make_shared<ArgumentString>("ID", mId);

    mTimeExtent = make_shared<TimeSet>();
    mValues = make_shared<ValueSetDbl>(vector<vector<double>>{{0.0}}, GetQuantity());
}

RunoffModule::RunoffModule(const string &id, const string &taskFile) :
    LinkableComponent(id)
{
    mArguments["task_file"] = make_shared<ArgumentString>("task_file", taskFile);

    mTimeExtent = make_shared<TimeSet>();
    mValues = make_shared<ValueSetDbl>(vector<vector<double>>{{0.0}}, GetQuantity());
}

shared_ptr<IQuantity> RunoffModule::GetQuantity()
{
    auto dime = make_shared<Dimension>(PredefinedDimensions::VolumePerTime);
    auto unit = make_shared<Unit>(dime, "Runoff", "runoff (m^3/s)", 1., 0.);
    auto quan = make_unique<Quantity>(unit, "Runoff", "Runoff", -9999.);
    return quan;
}

void RunoffModule::InitializeArguments()
{
    // initialize/activate arguments.

    for (const auto &kid : mRequiredArguments)
    {
        if (kid == "task_file")
        {
            if (mArguments.count(kid) == 0)
            {
                throw runtime_error(StringHelper::FormatSimple(
                    "RunoffModule ({}) has not set task file argument.", mId));
            }

            string file = any_cast<string>(mArguments[kid]->GetValue());
            if (!FilePathHelper::FileExists(file))
            {
                throw FileLoadException(StringHelper::FormatSimple(
                    "RunoffModule ({}) task file unexistent: [{}] .", mId, file));
            }
        }
    }
}

void RunoffModule::InitializeSpace()
{
    Element elem(
        mId, "runoff module point", "runoff module point", {Coordinate{0, 0, 0}});

    mElements = make_shared<ElementSet>(
        "runoff module elmentset",
        "runoff module elmentset",
        ElementType::Point,
        vector<Element>{elem});
}

void RunoffModule::InitializeTime()
{
    mTimes = make_shared<TimeSet>();

    mCurrent     = DateTime::FromString("2023-1-1 00:00:00");
    mRunningStep = TimeSpan::FromString("01:00:00");
    mCurrentTime = make_shared<Time>(mCurrent.GetTimeStampInDays());

    mTimes->AddTime(mCurrentTime);
    mTimeExtent->AddTime(make_shared<Time>(mCurrentTime));
    mTimeExtent->AddTime(make_shared<Time>(mCurrent.GetTimeStampInDays() + 0.5));
}

void RunoffModule::InitializeInputs()
{
    auto comp  = dynamic_pointer_cast<RunoffModule>(shared_from_this());
    auto input = make_shared<RunoffInput>(mId, comp);
    input->SetCaption("RunoffModule input item");
    input->SetDescription("RunoffModule input item providing runoff.");
    input->SetElementSet(mElements);

    auto dime = make_shared<Dimension>(PredefinedDimensions::LengthPerTime);
    auto unit = make_shared<Unit>(dime, "Rainfall intensity", "(mm/s)", 1.e-3, 0.0);
    auto quan = make_shared<Quantity>(unit, "Rainfall", "", -9999.);
    input->SetValues(make_shared<ValueSet2D>(quan));

    mInputs.push_back(input);
}

void RunoffModule::InitializeOutputs()
{
    auto comp   = dynamic_pointer_cast<RunoffModule>(shared_from_this());
    auto output = make_shared<RunoffOutput>(mId, comp);
    output->SetCaption("RunoffModule output item");
    output->SetDescription("RunoffModule output item providing runoff.");

    output->SetElementSet(mElements);
    output->SetTimeSet(make_shared<TimeSet>());
    output->SetValues(make_shared<ValueSet2D>(GetQuantity()));
    mOutputs.push_back(output);
}

vector<string> RunoffModule::OnValidate()
{
    return {};
}

void RunoffModule::PrepareInputs()
{
    for (auto &input : mInputs)
    {
        input->SetTimeSet(mTimes);
        input->GetValues(nullptr)->SetOrAddValue({0, 0}, 0.0);
    }
}

void RunoffModule::PrepareOutputs()
{
    for (auto &output : mOutputs)
    {
        output->GetTimeSet()->AddTime(mCurrentTime);
        output->GetValues(nullptr)->SetOrAddValue({0, 0}, 0.0);

        for (auto &adaptor : output->GetAdaptedOutputs())
        {
            adaptor->Initialize();
        }
    }
}

void RunoffModule::ApplyInputData(const std::shared_ptr<IValueSet> &values)
{
    auto quan = dynamic_pointer_cast<IQuantity>(values->GetValueDefinition());
    auto unit = quan->GetUnit();

    double k = unit->GetConversionFactorToSI();
    double b = unit->GetOffSetToSI();

    double rawRainfall = any_cast<double>(values->GetValue({0, 0}));
    double rainfall    = k * rawRainfall + b;
    double inflow      = rainfall * 1000.0;

    mInflow += inflow;
}

void RunoffModule::PerformTimestep(const vector<shared_ptr<IOutput>> &requiredOutputs)
{
    mCurrent.AddTimeSpan(mRunningStep);
    double runoff = mInflow;
    int    tCount = mTimes->GetCount();

    mCurrentTime = make_shared<Time>(mCurrent);

    mTimes->AddTime(mCurrentTime);
    mValues->SetOrAddValue({tCount, 0}, runoff);

    mInflow = 0.0;
}

void RunoffModule::UpdateOutputs(const vector<shared_ptr<IOutput>> &requiredOutputs)
{
    for (const auto &output : requiredOutputs)
    {
        auto valueset = output->GetValues(nullptr);
        auto timeset  = output->GetTimeSet();

        const auto &values = mValues->GetTimeSeriesValuesForElement(0);
        int         tCount = timeset->GetTimes().size();

        valueset->SetOrAddValue({tCount, 0}, values.back());
        timeset->AddTime(make_shared<Time>(mCurrentTime));
    }
}

// class RunoffInput-------------------------------------------------------------------

RunoffInput::RunoffInput(const string &id, const shared_ptr<RunoffModule> &component) :
    Input(id, component)
{}


// class RunoffOutput------------------------------------------------------------------

RunoffOutput::RunoffOutput(
    const string &id, const shared_ptr<RunoffModule> &component) :
    Output(id, component)
{}

}  // namespace OpenOasis::SystFluids::Hydrologics