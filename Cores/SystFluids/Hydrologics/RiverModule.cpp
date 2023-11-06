/** ***********************************************************************************
 *    @File      :  RiverModule.cpp
 *    @Brief     :  Simple river module for framework usage example.
 *
 ** ***********************************************************************************/
#include "RiverModule.h"
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


RiverModule::RiverModule(const string &id) : LinkableComponent(id)
{
    mCaption     = "River module";
    mDescription = "River module used for framework usage example";
    mNodeNum     = 5;

    mRequiredArguments = {"ID"};
    mArguments["ID"]   = make_shared<ArgumentString>("ID", mId);

    mTimeExtent = make_shared<TimeSet>();

    auto q0 = vector<double>(mNodeNum, 10.0);
    mFlowValues =
        make_shared<ValueSetDbl>(vector<vector<double>>{q0}, GetFlowQuantity());

    auto z0 = vector<double>(mNodeNum, 0.0);
    mWaterLevelValues =
        make_shared<ValueSetDbl>(vector<vector<double>>{z0}, GetWaterLevelQuantity());

    mTimeCount = 1;
}

shared_ptr<IQuantity> RiverModule::GetFlowQuantity()
{
    auto dime = make_shared<Dimension>(PredefinedDimensions::VolumePerTime);
    auto unit = make_shared<Unit>(dime, "flow", "flow (m^3/s)", 1., 0.);
    auto quan = make_unique<Quantity>(unit, "flow", "flow(m^3/s)", -9999.);
    return quan;
}

shared_ptr<IQuantity> RiverModule::GetWaterLevelQuantity()
{
    auto dime = make_shared<Dimension>(PredefinedDimensions::Length);
    auto unit = make_shared<Unit>(dime, "water level", "waterlevel(m)", 1., 0.);
    auto quan = make_unique<Quantity>(unit, "water level", "water level(m)", -9999.);
    return quan;
}

void RiverModule::InitializeSpace()
{
    auto rivernet = vector<Coordinate>(mNodeNum);
    for (int i = 0; i < mNodeNum; i++)
    {
        rivernet[i] = Coordinate{i * 10.0, 0, 0};
    }
    Element elem(mId, "river network", "river network", rivernet);

    mElements = make_shared<ElementSet>(
        "river network elmentset",
        "river network elmentset",
        ElementType::Polyline,
        vector<Element>{elem});
}

void RiverModule::InitializeTime()
{
    mTimes = make_shared<TimeSet>();

    mCurrent     = DateTime::FromString("2023-1-1 00:00:00");
    mRunningStep = TimeSpan::FromString("01:00:00");
    mCurrentTime = make_shared<Time>(mCurrent.GetTimeStampInDays());

    mTimes->AddTime(make_shared<Time>(mCurrentTime));
    mTimeExtent->AddTime(make_shared<Time>(mCurrentTime));
    mTimeExtent->AddTime(make_shared<Time>(mCurrent.GetTimeStampInDays() + 0.5));
}

void RiverModule::InitializeInputs()
{
    for (int i = 0; i < mNodeNum; i++)
    {
        auto comp = dynamic_pointer_cast<RiverModule>(shared_from_this());

        auto    nodeId = mId + "_node_" + to_string(i);
        Element node(
            nodeId, "rivernet node", "rivernet node", {Coordinate{i * 10.0, 0, 0}});

        auto element = make_shared<ElementSet>(
            "river network node",
            "river network node",
            ElementType::Point,
            vector<Element>{node});

        auto inputId = mId + "_input_" + "_q_" + to_string(i);
        auto input   = make_shared<Input>(inputId, comp);
        input->SetCaption("River model input item");
        input->SetDescription("River model input item requiring flow data.");
        input->SetElementSet(element);
        input->SetValues(make_shared<ValueSet2D>(GetFlowQuantity()));
        mInputs.push_back(input);

        inputId = mId + "_input_" + "_z_" + to_string(i);
        input   = make_shared<Input>(inputId, comp);
        input->SetCaption("River model input item");
        input->SetDescription("River model input item requiring stage data.");
        input->SetElementSet(element);
        input->SetValues(make_shared<ValueSet2D>(GetWaterLevelQuantity()));
        mInputs.push_back(input);
    }
}

void RiverModule::InitializeOutputs()
{
    for (int i = 0; i < mNodeNum; ++i)
    {
        auto comp = dynamic_pointer_cast<RiverModule>(shared_from_this());

        auto    nodeId = mId + "_node_" + to_string(i);
        Element node(
            nodeId, "rivernet node", "rivernet node", {Coordinate{i * 10.0, 0, 0}});

        auto element = make_shared<ElementSet>(
            "river network node",
            "river network node",
            ElementType::Point,
            vector<Element>{node});

        auto outputId = mId + "_output_" + "_q_" + to_string(i);
        auto output   = make_shared<Output>(outputId, comp);
        output->SetCaption("River model output item");
        output->SetDescription("River model output item providing flow data.");
        output->SetElementSet(element);
        output->SetTimeSet(make_shared<TimeSet>());
        output->SetValues(make_shared<ValueSet2D>(GetFlowQuantity()));
        mOutputs.push_back(output);

        outputId = mId + "_output_" + "_z_" + to_string(i);
        output   = make_shared<Output>(outputId, comp);
        output->SetCaption("River model output item");
        output->SetDescription("River model output item providing stage data.");
        output->SetElementSet(element);
        output->SetTimeSet(make_shared<TimeSet>());
        output->SetValues(make_shared<ValueSet2D>(GetWaterLevelQuantity()));
        mOutputs.push_back(output);
    }
}

vector<string> RiverModule::OnValidate()
{
    return {};
}

void RiverModule::PrepareInputs()
{
    for (auto &input : mInputs)
    {
        input->SetTimeSet(make_shared<TimeSet>(mTimes));
        input->GetValues(nullptr)->SetOrAddValue({0, 0}, 0.0);
    }
}

void RiverModule::PrepareOutputs()
{
    for (auto &output : mOutputs)
    {
        output->GetTimeSet()->AddTime(mCurrentTime);
        auto valueset = output->GetValues(nullptr);

        if (output->GetId().find("q") != string::npos)
        {
            valueset->SetOrAddValue({0, 0}, 10.0);
        }
        else { valueset->SetOrAddValue({0, 0}, 0.0); }

        for (auto &adaptor : output->GetAdaptedOutputs())
        {
            adaptor->Initialize();
        }
    }
}

void RiverModule::UpdateInputs()
{
    for (const auto &input : mInputs)
    {
        if (input->GetProviders().empty()) continue;

        const auto &arr       = StringHelper::Split(input->GetId(), '_');
        int         nodeIndex = stoi(arr.back());

        const auto &values = input->GetValues(nullptr);
        auto quan = dynamic_pointer_cast<IQuantity>(values->GetValueDefinition());
        auto unit = quan->GetUnit();

        double k = unit->GetConversionFactorToSI();
        double b = unit->GetOffSetToSI();

        double value  = any_cast<double>(values->GetValue({0, 0}));
        int    tCount = mTimes->GetCount();
        if (input->GetId().find("q") != string::npos)
        {
            double inflow = k * value + b;
            double flow   = any_cast<double>(mFlowValues->GetValue({0, nodeIndex}));
            double z      = TurnFlowToStage(flow + inflow);
            mFlowValues->SetOrAddValue({tCount - 1, nodeIndex}, flow + inflow);
            mWaterLevelValues->SetOrAddValue({tCount - 1, nodeIndex}, z);
        }
        else
        {
            double stage = k * value + b;
            double flow  = TurnStageToFlow(stage);
            mWaterLevelValues->SetOrAddValue({tCount - 1, nodeIndex}, stage);
            mFlowValues->SetOrAddValue({tCount - 1, nodeIndex}, flow);
        }
    }
}

void RiverModule::PerformTimestep(const vector<shared_ptr<IOutput>> &requiredOutputs)
{
    mCurrent.AddTimeSpan(mRunningStep);
    mCurrentTime = make_shared<Time>(mCurrent);

    for (int i = 0; i < mNodeNum; i++)
    {
        double flow = any_cast<double>(mFlowValues->GetValue({mTimeCount - 1, i}));
        mFlowValues->SetOrAddValue({mTimeCount, i}, flow / 2.);
        mWaterLevelValues->SetOrAddValue({mTimeCount, i}, TurnFlowToStage(flow / 2.));

        // for (int j = i + 1; j < mNodeNum; j++)
        // {
        //     double q = any_cast<double>(mFlowValues->GetValue({mTimeCount - 1, j}));
        //     mFlowValues->SetOrAddValue({mTimeCount - 1, j}, q + flow / (j + 1));
        // }
    }

    mTimes->AddTime(make_shared<Time>(mCurrent));
    mTimeCount = mTimes->GetTimes().size();
}

void RiverModule::UpdateOutputs(const vector<shared_ptr<IOutput>> &requiredOutputs)
{
    for (const auto &output : requiredOutputs)
    {
        const auto &arr       = StringHelper::Split(output->GetId(), '_');
        int         nodeIndex = stoi(arr.back());

        auto valueset = output->GetValues(nullptr);
        auto timeset  = output->GetTimeSet();

        int tCount = timeset->GetTimes().size();
        if (output->GetId().find("q") != string::npos)
        {
            const auto &values = mFlowValues->GetElementValuesForTime(mTimeCount - 1);
            double      flow   = any_cast<double>(values.at(nodeIndex));

            valueset->SetOrAddValue({tCount, 0}, flow);
        }
        else
        {
            const auto &values =
                mWaterLevelValues->GetElementValuesForTime(mTimeCount - 1);
            double stage = any_cast<double>(values.at(nodeIndex));

            valueset->SetOrAddValue({tCount, 0}, stage);
        }

        timeset->AddTime(make_shared<Time>(mCurrentTime));
    }
}

shared_ptr<IIdentifiable> RiverModule::KeepCurrentState()
{
    string id    = mId + "_state_" + DateTime::ToString(mCurrent);
    auto   state = make_shared<RiverState>(id);

    state->current          = mCurrent;
    state->flowValues       = make_shared<ValueSet2D>(mFlowValues);
    state->waterLevelValues = make_shared<ValueSet2D>(mWaterLevelValues);
    state->times            = make_shared<TimeSet>(mTimes);
    state->timeCount        = mTimeCount;
    state->currentTime      = make_shared<Time>(mCurrentTime);
    state->status           = mStatus;

    mStates.emplace_back(state);
    return state;
}

void RiverModule::RestoreState(const shared_ptr<IIdentifiable> &stateId)
{
    auto iter = find_if(begin(mStates), end(mStates), [stateId](const auto &state) {
        return state->GetId() == stateId->GetId();
    });

    if (iter == end(mStates))
    {
        throw IllegalArgumentException(StringHelper::FormatSimple(
            "River model {} state with id {} not found.", mId, stateId->GetId()));
    }

    auto state        = *iter;
    mCurrent          = state->current;
    mFlowValues       = state->flowValues;
    mWaterLevelValues = state->waterLevelValues;
    mTimes            = state->times;
    mTimeCount        = state->timeCount;
    mCurrentTime      = state->currentTime;
    mStatus           = state->status;
}

void RiverModule::ClearState(const shared_ptr<IIdentifiable> &stateId)
{
    auto iter = find_if(begin(mStates), end(mStates), [&stateId](const auto &state) {
        return state->GetId() == stateId->GetId();
    });

    if (iter != end(mStates)) { mStates.erase(iter); }
}


}  // namespace OpenOasis::SystFluids