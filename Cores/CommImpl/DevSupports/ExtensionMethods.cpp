/** ***********************************************************************************
 *    @File      :  ExtensionMethods.cpp
 *    @Brief     :  Extensional static methods for spatial and temporal operation.
 *
 ** ***********************************************************************************/
#include "ExtensionMethods.h"
#include "Cores/CommImpl/Time.h"
#include "Cores/CommImpl/TimeSet.h"
#include "Cores/CommImpl/Quantity.h"
#include "Cores/CommImpl/ValueSet2D.h"
#include "Cores/Utils/Exception.h"
#include "Cores/Utils/StringHelper.h"


namespace OpenOasis::CommImpl::DevSupports
{
using namespace Utils;
using namespace std;

shared_ptr<IQuantity>
ExtensionMethods::Quantity(const shared_ptr<IBaseExchangeItem> &item)
{
    auto valueDef = item->GetValueDefinition();
    if (!valueDef)
    {
        throw IllegalArgumentException(StringHelper::FormatSimple(
            "Null value definition of exchange tiem [{}] .", item->GetId()));
    }

    auto qualDef = dynamic_pointer_cast<CommImpl::Quantity>(valueDef);
    if (!qualDef)
    {
        throw InvalidOperationException(StringHelper::FormatSimple(
            "Can't get quantity from exchange item [{}] .", item->GetId()));
    }

    return qualDef;
}

bool ExtensionMethods::TimeEquals(
    const shared_ptr<ITime> &time1, const shared_ptr<ITime> &time2)
{
    if (abs(time1->GetTimeStamp() - time2->GetTimeStamp())
        > Time::EpsilonForTimeCompare)
        return false;
    else
        return true;
}

shared_ptr<ITime> ExtensionMethods::Start(const shared_ptr<ITime> &time)
{
    return make_shared<Time>(time->GetTimeStamp());
}

shared_ptr<ITime> ExtensionMethods::End(const shared_ptr<ITime> &time)
{
    return make_shared<Time>(time->GetTimeStamp() + time->GetDurationInDays());
}

double ExtensionMethods::EndTimeStamp(const shared_ptr<ITime> &time)
{
    return time->GetTimeStamp() + time->GetDurationInDays();
}

void ExtensionMethods::SetSingleTime(
    const shared_ptr<ITimeSet> &timeSet, std::shared_ptr<ITime> timeStamp)
{
    if (timeStamp->GetDurationInDays() == 0 && timeSet->HasDurations())
    {
        throw runtime_error(
            "Can not set single time STAMP in a time set with duration");
    }
    else if (timeStamp->GetDurationInDays() > 0 && !timeSet->HasDurations())
    {
        throw runtime_error(
            "Can not set single time SPAN in a time set without duration");
    }

    if (timeSet->GetTimes().size() > 1) { timeSet->GetTimes().clear(); }
    if (timeSet->GetTimes().empty()) { timeSet->GetTimes().push_back(timeStamp); }
    else { timeSet->GetTimes()[0] = timeStamp; }
}

void ExtensionMethods::SetSingleTimeStamp(
    const shared_ptr<ITimeSet> &timeSet, double timestamp)
{
    SetSingleTime(timeSet, make_shared<Time>(timestamp));
}

void ExtensionMethods::SetSingleTimeStamp(
    const shared_ptr<ITimeSet> &timeSet, const DateTime &dateTime)
{
    Time tempVar(dateTime);
    SetSingleTime(timeSet, make_shared<Time>(dateTime));
}

void ExtensionMethods::SetSingleTimeSpan(
    const shared_ptr<ITimeSet> &timeSet, const DateTime &dateTime,
    double durationInDays)
{
    SetSingleTime(timeSet, make_shared<Time>(dateTime, durationInDays));
}

void ExtensionMethods::SetSingleTimeSpan(
    const shared_ptr<ITimeSet> &timeSet, double start, double end)
{
    SetSingleTime(timeSet, make_shared<Time>(start, end - start));
}

void ExtensionMethods::SetSingleTimeSpan(
    const shared_ptr<ITimeSet> &timeSet, const shared_ptr<ITime> &startTime,
    const shared_ptr<ITime> &endTime)
{
    SetSingleTimeSpan(
        timeSet,
        startTime->GetTimeStamp(),
        endTime->GetTimeStamp() + endTime->GetDurationInDays());
}

int ExtensionMethods::ElementCount(const shared_ptr<IValueSet> &values)
{
    return values->GetIndexCount({0, 0});
}

int ExtensionMethods::TimesCount(const shared_ptr<IValueSet> &values)
{
    return values->GetIndexCount({0});
}

shared_ptr<IValueSet> ExtensionMethods::MultiplyElementValues(
    const shared_ptr<IValueSet> &sourceValueset, const vector<double> &factors)
{
    if (sourceValueset->GetValueDefinition()->GetValueType() != typeid(double))
    {
        throw invalid_argument(
            "Not support to multiply non-double element values with factors.");
    }

    int elemSize = sourceValueset->GetIndexCount({0, 0});
    if (elemSize != factors.size())
    {
        throw invalid_argument(StringHelper::FormatSimple(
            "ValueSet element size({}) doesn't match factors size({}) \
                while multipling them together.",
            elemSize,
            factors.size()));
    }

    auto values = make_shared<ValueSet2D>(sourceValueset);
    for (int t = 0; t < sourceValueset->GetIndexCount({0}); ++t)
    {
        for (int i = 0; i < elemSize; ++i)
        {
            double value = any_cast<double>(sourceValueset->GetValue({t, i}));
            double res   = value * factors[i];

            values->SetOrAddValue({t, i}, res);
        }
    }

    return values;
}

}  // namespace OpenOasis::CommImpl::DevSupports