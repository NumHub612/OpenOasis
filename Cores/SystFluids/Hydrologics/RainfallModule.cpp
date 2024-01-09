/** ***********************************************************************************
 *    @File      :  RainfallModule.cpp
 *    @Brief     :  Rainfall module.
 *
 ** ***********************************************************************************/
#include "RainfallModule.h"
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


// class RainfallModule----------------------------------------------------------------

RainfallModule::RainfallModule(const RainfallModule &obj) :
    LinkableComponent(obj.GetId())
{
    mCaption     = "Rainfall module";
    mDescription = "Rainfall module used for providing rain intensity data";

    mRequiredArguments = {"ID", "coordinate_file", "rainfall_file"};
    mArguments["ID"]   = make_shared<ArgumentString>("ID", mId);

    mTimeExtent = make_shared<TimeSet>();
}

RainfallModule::RainfallModule(
    const string &id, shared_ptr<IElementSet> elements, shared_ptr<ITimeSet> times,
    shared_ptr<IValueSet> values) :
    LinkableComponent(id)
{
    mElements = make_shared<ElementSet>(elements);
    mValues   = make_shared<ValueSet2D>(values);
    mTimes    = make_shared<TimeSet>(times);

    mTimeExtent = make_shared<TimeSet>();
    mTimeExtent->AddTime(times->GetTimes().front());
}

RainfallModule::RainfallModule(
    const string &id, const string &coorFile, const string &dataFile) :
    LinkableComponent(id)
{
    mArguments["coordinate_file"] =
        make_shared<ArgumentString>("coordinate_file", coorFile);
    mArguments["rainfall_file"] =
        make_shared<ArgumentString>("rainfall_file", dataFile);

    mTimeExtent = make_shared<TimeSet>();
}

shared_ptr<IQuantity> RainfallModule::GetQuantity()
{
    auto dim  = make_shared<Dimension>(PredefinedDimensions::LengthPerTime);
    auto unit = make_shared<Unit>(
        dim, "Rainfall intensity", "Rainfall intensity (mm/s)", 1.e-3, 0.0);

    auto quant = make_unique<Quantity>(unit, "Rainfall data", "Rainfall data", -9999.);
    return quant;
}

void RainfallModule::InitializeArguments()
{
    // initialize/activate arguments.

    for (const auto &kid : mRequiredArguments)
    {
        if (kid == "rainfall_file" && !mValues && !mTimes)
        {
            if (mArguments.count(kid) == 0)
            {
                throw runtime_error(StringHelper::FormatSimple(
                    "RainfallModule ({}) has not set rainfall file argument.", mId));
            }

            string file = any_cast<string>(mArguments[kid]->GetValue());
            if (!FilePathHelper::FileExists(file))
            {
                throw FileLoadException(StringHelper::FormatSimple(
                    "RainfallModule ({}) rainfall file unexistent: [{}] .", mId, file));
            }
        }
        else if (kid == "coordinate_file" && !mElements)
        {
            if (mArguments.count(kid) == 0)
            {
                throw runtime_error(StringHelper::FormatSimple(
                    "RainfallModule [{}] has not set coordinate file argument.", mId));
            }

            string file = any_cast<string>(mArguments[kid]->GetValue());
            if (!FilePathHelper::FileExists(file))
            {
                throw FileLoadException(StringHelper::FormatSimple(
                    "RainfallModule [{}] coordinate file unexistent: [{}] .",
                    mId,
                    file));
            }
        }
    }
}

void RainfallModule::InitializeSpace()
{
    if (mElements) return;

    string file = any_cast<string>(mArguments["coordinate_file"]->GetValue());

    StreamReader reader;
    reader.Init(file);

    string line;
    while (reader.GetLine(line))
    {
        vector<string> arr = StringHelper::Split(line, ',');
        if (arr.empty() || arr.size() < 3) continue;

        if (arr[0] != mId) continue;

        double x = stod(arr[1].c_str(), nullptr);
        double y = stod(arr[2].c_str(), nullptr);
        double z = (arr.size() > 3) ? stod(arr[3].c_str(), nullptr) : NAN;

        Element elem(
            mId,
            "rainfall module point",
            "rainfall module point",
            {Coordinate{x, y, z}});

        mElements = make_shared<ElementSet>(
            "rainfall module elmentset",
            "rainfall module elmentset",
            ElementType::Point,
            vector<Element>{elem});
        break;
    }

    if (!mElements)
    {
        throw InvalidDataException(StringHelper::FormatSimple(
            "RainfallModule [{}] coordinate load failed.", mId));
    }
}

void RainfallModule::InitializeTime()
{
    if (mValues && mTimes) return;

    mTimes  = make_shared<TimeSet>();
    mValues = make_shared<ValueSetDbl>(vector<vector<double>>{}, GetQuantity());

    string file = any_cast<string>(mArguments["rainfall_file"]->GetValue());

    StreamReader reader;
    reader.Init(file);

    auto preTime   = make_shared<Time>();
    int  timeCount = 0;

    string line;
    while (reader.GetLine(line))
    {
        vector<string> arr = StringHelper::Split(line, ',');
        if (arr.empty() || arr.size() < 3) continue;

        if (arr[0] != mId) continue;

        DateTime datetime(DateTime::FromString(arr[1]));
        double   timestampInDays = datetime.GetTimeStampInDays();
        auto     curTime         = make_shared<Time>(timestampInDays);

        if (curTime->CompareTo(preTime) < 0)
        {
            throw InvalidDataException(
                "Rainfall needs an increasing time series, but "
                + Time::ToString(curTime) + " < " + Time::ToString(preTime));
        }

        mTimes->AddTime(curTime);
        preTime = curTime;

        double rain = stod(arr[2].c_str(), nullptr);
        mValues->SetOrAddValue({timeCount++, 0}, rain);
    }

    mCurrentTime = mTimes->GetTimes().at(0);
    mTimeExtent  = mTimes;
}

void RainfallModule::InitializeOutputs()
{
    mOutputs.clear();

    auto comp   = dynamic_pointer_cast<RainfallModule>(shared_from_this());
    auto output = make_shared<RainfallOutput>(mId, comp);
    output->SetCaption("Rainfall module output item");
    output->SetDescription("Raingfall module output item providing ranfall intensity.");

    output->SetElementSet(mElements);
    output->SetTimeSet(make_shared<TimeSet>());
    output->SetValues(make_shared<ValueSet2D>(GetQuantity()));
    mOutputs.push_back(output);
}

vector<string> RainfallModule::OnValidate()
{
    return {};
}

void RainfallModule::PrepareOutputs()
{
    for (auto &output : mOutputs)
    {
        output->GetTimeSet()->AddTime(mCurrentTime);
        output->GetValues(nullptr)->SetOrAddValue({0, 0}, mValues->GetValue({0, 0}));

        for (auto &adaptor : output->GetAdaptedOutputs())
        {
            adaptor->Initialize();
        }
    }
}

void RainfallModule::UpdateOutputs(const vector<shared_ptr<IOutput>> &requiredOutputs)
{
    for (const auto &output : requiredOutputs)
    {
        auto valueset = output->GetValues(nullptr);
        auto timeset  = output->GetTimeSet();

        // int tCount = valueset->GetIndexCount({0});
        int tCount = timeset->GetTimes().size();

        valueset->SetOrAddValue({tCount, 0}, mValues->GetValue({mCurrentIdx, 0}));
        timeset->AddTime(mCurrentTime);
    }
}

void RainfallModule::PerformTimestep(const vector<shared_ptr<IOutput>> &requiredOutputs)
{
    mCurrentIdx += 1;

    mCurrentTime = mTimes->GetTimes().at(mCurrentIdx);
}


// class RainfallOutput----------------------------------------------------------------

RainfallOutput::RainfallOutput(
    const string &id, const shared_ptr<RainfallModule> &component) :
    Output(id, component)
{}

}  // namespace OpenOasis::SystFluids::Hydrologics
