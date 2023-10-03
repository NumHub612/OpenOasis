/** ***********************************************************************************
 *    @File      :  TimeAdaptor.cpp
 *    @Brief     :  Class contains temporal adaptive data operations.
 *
 ** ***********************************************************************************/
#include "TimeAdaptor.h"
#include "ExchangeItemHelper.h"
#include "ExtensionMethods.h"
#include "Cores/CommImpl/Time.h"
#include "Cores/CommImpl/Quantity.h"
#include "Cores/CommImpl/ExchangeItemEventArgs.h"
#include "Cores/Utils/Exception.h"
#include "Cores/Utils/MapHelper.h"
#include "Cores/Utils/StringHelper.h"


namespace OpenOasis::CommImpl::DevSupports
{
using namespace Temporal;
using namespace Utils;
using namespace std;

TimeAdaptor::TimeAdaptor(const string &id) : AbstractAdaptedOutput(id)
{}

TimeAdaptor::TimeAdaptor(const string &id, const shared_ptr<IOutput> &adaptee) :
    AbstractAdaptedOutput(id, adaptee)
{}

shared_ptr<ITimeSet> TimeAdaptor::GetTimeSet() const
{
    return mBuffers.GetTimeSet();
}

void TimeAdaptor::SetTimeSet(shared_ptr<ITimeSet> value)
{
    mTimeSet = value;

    BroadcastEventWithMsg("TimeSet reseted");
}

shared_ptr<IElementSet> TimeAdaptor::GetElementSet() const
{
    return mOutput.lock()->GetElementSet();
}

void TimeAdaptor::SetElementSet(shared_ptr<IElementSet> value)
{}

void TimeAdaptor::SetValues(shared_ptr<IValueSet> value)
{
    throw NotImplementedException("TimeAdaptor::SetValues()");
}

shared_ptr<IValueSet>
TimeAdaptor::GetValues(const shared_ptr<IBaseExchangeItem> &specifiedQuerier)
{
    //------------------------------------------------------
    // Check if we need to update the output component.

    shared_ptr<IBaseExchangeItem> querier = specifiedQuerier;
    if (!querier) { querier = mConsumers.back().lock(); }

    // Time set of query must be defined and have at least 1 time.
    if (querier->GetTimeSet() == nullptr || querier->GetTimeSet()->GetTimes().empty())
    {
        throw runtime_error(StringHelper::FormatSimple(
            "Invalid query specifier {} for in GetValues() call to time adaptor {}.",
            querier->GetId(),
            mId));
    }

    // Determine query time.
    double queryTimestamp =
        ExtensionMethods::End(querier->GetTimeSet()->GetTimeHorizon())->GetTimeStamp();

    // Determine the times available in the buffer.
    auto   currentTimes       = mOutput.lock()->GetTimeSet()->GetTimes();
    double availableTimestamp = -numeric_limits<double>::infinity();
    if (currentTimes.size() > 0)
    {
        availableTimestamp = ExtensionMethods::End(currentTimes.back())->GetTimeStamp();
    }

    // Check if we need to update.
    // In case the output component is "busy",  this may not actually update values
    // up to queryTime, in which case the mBuffers.GetValues below will extrapolate.
    if (availableTimestamp < queryTimestamp) { Update(querier); }

    // Pull data from Output item.
    auto currentValues = mOutput.lock()->GetValues({});
    currentTimes       = mOutput.lock()->GetTimeSet()->GetTimes();
    for (int t = 0; t < currentTimes.size(); ++t)
    {
        const auto    &data = currentValues->GetElementValuesForTime(t);
        vector<double> dataInDbl;
        for (const auto &val : data)
        {
            dataInDbl.push_back(any_cast<double>(val));
        }

        mBuffers.AddValues(currentTimes[t], dataInDbl);
    }

    //------------------------------------------------------
    // Retrieve values from the buffer.

    // Return the values for the required time(s).
    vector<vector<double>> resultValues;
    if (querier->GetTimeSet() != nullptr && !currentTimes.empty())
    {
        for (int t = 0; t < currentTimes.size(); t++)
        {
            const auto &queryTime         = querier->GetTimeSet()->GetTimeHorizon();
            const auto &valuesForTimeStep = mBuffers.GetValues(queryTime);

            resultValues.push_back(valuesForTimeStep);
        }
    }

    const auto &earliestConsumerTime =
        ExchangeItemHelper::GetEarliestConsumerTime(GetInstance());
    if (earliestConsumerTime != nullptr) { mBuffers.ClearBefore(earliestConsumerTime); }

    return make_shared<ValueSetDbl>(
        resultValues, dynamic_pointer_cast<IQuantity>(GetValueDefinition()));
}

bool TimeAdaptor::Update(const shared_ptr<IBaseExchangeItem> &specifier)
{
    // Time set of query must be defined and have at least 1 time.
    if (specifier->GetTimeSet() == nullptr
        || specifier->GetTimeSet()->GetTimes().empty())
    {
        throw runtime_error(StringHelper::FormatSimple(
            "Given TimeSet of output item {} can't produce one set of values for {}.",
            mOutput.lock()->GetId(),
            specifier->GetId()));
    }

    // Output time set must be defined.
    const auto &output = mOutput.lock();
    if (output->GetTimeSet() == nullptr || output->GetTimeSet()->GetTimes().empty())
    {
        throw runtime_error(StringHelper::FormatSimple(
            "Invalid specifier {} in output item {} for updating according to time.",
            output->GetId(),
            specifier->GetId()));
    }

    // Compute until this time is available.
    double queryTimestamp =
        ExtensionMethods::End(specifier->GetTimeSet()->GetTimeHorizon())
            ->GetTimeStamp();

    // The current available time from the output item.
    double      availableTimestamp = -numeric_limits<double>::infinity();
    const auto &times              = output->GetTimeSet()->GetTimes();
    if (times.size() > 0)
    {
        availableTimestamp = ExtensionMethods::End(times.back())->GetTimeStamp();
    }

    // Update component until querytime is available.
    // If component is "busy" (LinkableComponentStatus.Updating), the
    // component will not be updated.
    const auto &component = GetComponent().lock();
    while ((component->GetStatus() == LinkableComponentStatus::Valid
            || component->GetStatus() == LinkableComponentStatus::Updated)
           && availableTimestamp + Time::EpsilonForTimeCompare < queryTimestamp)
    {
        component->Update({});

        availableTimestamp =
            ExtensionMethods::End(output->GetTimeSet()->GetTimeHorizon())
                ->GetTimeStamp();
    }

    // Return true if component was updated up until queryTimestamp.
    return (availableTimestamp + Time::EpsilonForTimeCompare >= queryTimestamp);
}

void TimeAdaptor::Refresh()
{
    const auto &component = GetComponent().lock();
    if (component->GetStatus() != LinkableComponentStatus::Preparing
        && component->GetStatus() != LinkableComponentStatus::Updating)
    {
        throw runtime_error(
            "Update can only be called from component when it's validating/updating");
    }

    const auto &values = mOutput.lock()->GetValues({});
    const auto &times  = mOutput.lock()->GetTimeSet()->GetTimes();

    for (int t = 0; t < times.size(); ++t)
    {
        vector<double> data;
        for (const auto &val : values->GetTimeSeriesValuesForElement(t))
        {
            data.push_back(any_cast<double>(val));
        }

        mBuffers.SetOrAddValues(times[t], data);
    }

    RefreshAdaptedOutputs();
}

void TimeAdaptor::RefreshAdaptedOutputs()
{
    for (auto &adaptor : mAdaptedOutputs)
    {
        if (!adaptor->GetConsumers().empty() || !adaptor->GetAdaptedOutputs().empty())
        {
            adaptor->Refresh();
        }
    }
}

void TimeAdaptor::Reset()
{
    mTimeSet.reset();
    mOutput.reset();
    mConsumers.clear();
    mAdaptedOutputs.clear();

    BroadcastEventWithMsg("Output item reseted.");
    mBuffers.Reset();
    mItemChanged.Clear();
}

shared_ptr<ITimeSet> TimeAdaptor::GetTimeExtent() const
{
    return mTimeSet;
}

shared_ptr<ITime> TimeAdaptor::GetCurrentTime() const
{
    return ExtensionMethods::End(mTimeSet->GetTimeHorizon());
}

shared_ptr<ISpatialDefinition> TimeAdaptor::GetSpatialDefinition() const
{
    return GetElementSet();
}

shared_ptr<TimeAdaptor> TimeAdaptor::GetInstance()
{
    return dynamic_pointer_cast<TimeAdaptor>(shared_from_this());
}


}  // namespace OpenOasis::CommImpl::DevSupports