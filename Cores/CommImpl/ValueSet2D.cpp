/** ***********************************************************************************
 *    @File      :  ValueSet2D.cpp
 *    @Brief     :  To represent an ordered two-dimensional list of values.
 *
 ** ***********************************************************************************/
#include "ValueSet2D.h"
#include "Quantity.h"
#include "Cores/Utils/Exception.h"
#include "Cores/Utils/StringHelper.h"
#include <algorithm>
#include <functional>


namespace OpenOasis::CommImpl
{
using namespace Utils;
using namespace std;


// class ValueSet2D--------------------------------------------------------------------

ValueSet2D::ValueSet2D(shared_ptr<IQuantity> valueDef)
{
    mValueDef = valueDef;
}

ValueSet2D::ValueSet2D(const shared_ptr<IValueSet> &valueSet)
{
    mValues2D = GetValues(valueSet);

    auto valDef = dynamic_pointer_cast<IQuantity>(valueSet->GetValueDefinition());
    mValueDef   = make_shared<Quantity>(valDef);
}

ValueSet2D::ValueSet2D(ValueSet2D &&obj)
{
    mValueDef = move(obj.mValueDef);
    mValues2D = move(obj.mValues2D);
}

// ValueSet2D::ValueSet2D(
//     const vector<vector<any>> &values2D, shared_ptr<IQuantity> valueDef)
// {
//     mValues2D = values2D;
//     mValueDef = move(valueDef);
// }

// ValueSet2D::ValueSet2D(
//     const vector<vector<double>> &values2D, shared_ptr<IQuantity> valueDef)
// {
//     for (const auto &arr : values2D)
//     {
//         vector<any> tmp;
//         for (const auto &val : arr)
//         {
//             tmp.emplace_back(val);
//         }

//         mValues2D.emplace_back(tmp);
//     }

//     mValueDef = move(valueDef);
// }

shared_ptr<IValueDefinition> ValueSet2D::GetValueDefinition() const
{
    return mValueDef;
}

any ValueSet2D::GetValue(const std::vector<int> &indices) const
{
    CheckAllDimensionSpecified(indices);

    int timeIndex    = indices[0];
    int elementIndex = indices[1];
    CheckTimeIndex(timeIndex);
    CheckElementIndex(timeIndex, elementIndex);
    return mValues2D.at(timeIndex).at(elementIndex);
}

void ValueSet2D::SetOrAddValue(const std::vector<int> &indices, const any &value)
{
    CheckAllDimensionSpecified(indices);

    int timeIndex = indices[0];
    int elemIndex = indices[1];

    if (timeIndex < 0 || elemIndex < 0)
    {
        throw IllegalArgumentException(
            "Negative time or element index used to set or add value to set.");
    }
    if (timeIndex > GetTimesCount())
    {
        throw IllegalArgumentException(StringHelper::FormatSimple(
            "Time index {} far exceed valueset time range {}.",
            timeIndex,
            GetTimesCount()));
    }

    if (timeIndex < GetTimesCount() && elemIndex < GetElementsCount(timeIndex))
    {
        if (!IsValidValueType(value))
        {
            throw IllegalArgumentException(StringHelper::FormatSimple(
                "The added value type {} doesn't match the value set {}.",
                value.type().name(),
                mValues2D[timeIndex][elemIndex].type().name()));
        }

        mValues2D[timeIndex][elemIndex] = value;
    }
    else { AddValue(indices, value); }
}

int ValueSet2D::GetNumberOfIndices() const
{
    // Two-dimensional value set.
    return 2;
}

int ValueSet2D::GetIndexCount(const std::vector<int> &indices) const
{
    // Check parameter validity.
    CheckIndicesOutOfDimension(indices);

    if (indices.size() == 1) { return mValues2D.size(); }

    // Query the length of first dimension.
    if (indices[0] >= GetTimesCount())
    {
        throw IllegalArgumentException(StringHelper::FormatSimple(
            "The first query index {} out of range {}.", indices[0], GetTimesCount()));
    }

    // Query the length of specified index in second dimension.
    int elementIndex = indices[1];
    CheckElementIndex(indices[0], elementIndex);

    return mValues2D[indices[0]].size();
}

void ValueSet2D::AddValue(const vector<int> &indices, const any &value)
{
    // Add values.
    int timeIndex = min(indices[0], GetTimesCount());
    int elemIndex = min(indices[1], GetElementsCount(timeIndex - 1));

    try
    {
        if (!IsValidValueType(value))
        {
            throw IllegalArgumentException(
                "The added value type doesn't match the value set.");
        }

        if (timeIndex >= GetTimesCount()) { mValues2D.push_back(vector<any>()); }

        auto &values = mValues2D[timeIndex];
        values.insert(values.begin() + elemIndex, value);
    }
    catch (const bad_any_cast &e)
    {
        throw InvalidOperationException(
            "The added value doesn't match the specified dimension.");
    }
}

void ValueSet2D::RemoveValue(const vector<int> &indices)
{
    if (mValues2D.empty()) return;

    // Check paramter validity.
    CheckIndicesOutOfDimension(indices);

    // Remove a time.
    int timeIndex = indices[0];
    CheckTimeIndex(timeIndex);

    if (indices.size() == 1)
    {
        mValues2D.erase(mValues2D.begin() + timeIndex);
        return;
    }

    // Remove a element.
    int elementIndex = indices[1];
    CheckElementIndex(timeIndex, elementIndex);

    auto &source = mValues2D[timeIndex];
    source.erase(source.begin() + elementIndex);
}

bool ValueSet2D::IsValues2D() const
{
    // Time(ITimeSet)-Space(IElementSet) value set.
    return true;
}

vector<any> ValueSet2D::GetTimeSeriesValuesForElement(int elementIndex) const
{
    for (int t = 0; t < GetTimesCount(); ++t)
    {
        CheckElementIndex(t, elementIndex);
    }

    vector<any> values;
    for (size_t timeIndex = 0; timeIndex < mValues2D.size(); timeIndex++)
    {
        values.push_back(mValues2D.at(timeIndex).at(elementIndex));
    }

    return values;
}

void ValueSet2D::SetTimeSeriesValuesForElement(
    int elementIndex, const vector<any> &values)
{
    if (values.size() != GetTimesCount())
    {
        throw IllegalArgumentException(
            "Invalid timeseries values length out of current value set.");
    }

    for (int t = 0; t < GetTimesCount(); ++t)
    {
        CheckElementIndex(t, elementIndex);
    }

    for (int t = 0; t < GetTimesCount(); ++t)
    {
        if (!IsValidValueType(values[t]))
        {
            throw IllegalArgumentException(
                "The added value type doesn't match the value set.");
        }
        mValues2D[t][elementIndex] = values[t];
    }
}

vector<any> ValueSet2D::GetElementValuesForTime(int timeIndex) const
{
    CheckTimeIndex(timeIndex);
    return mValues2D.at(timeIndex);
}

void ValueSet2D::SetElementValuesForTime(int timeIndex, const vector<any> &values)
{
    CheckTimeIndex(timeIndex);

    if (values.size() != mValues2D[timeIndex].size())
    {
        throw IllegalArgumentException(
            "Invalid elements values length out of current value set.");
    }

    if (!all_of(
            begin(values),
            end(values),
            bind(&ValueSet2D::IsValidValueType, this, placeholders::_1)))
    {
        throw IllegalArgumentException(
            "The added value type doesn't match the value set.");
    }

    mValues2D[timeIndex] = values;
}

int ValueSet2D::GetTimesCount() const
{
    if (mValues2D.empty()) return 0;

    return mValues2D.size();
}

int ValueSet2D::GetElementsCount(int timeIndex) const
{
    if (timeIndex < 0 || timeIndex >= GetTimesCount()) { return 0; }

    if (mValues2D[timeIndex].empty()) return 0;

    return mValues2D[timeIndex].size();
}

void ValueSet2D::SetValueDefinition(shared_ptr<IValueDefinition> value)
{
    mValueDef = dynamic_pointer_cast<IQuantity>(value);
}

vector<vector<any>> ValueSet2D::GetValues(const shared_ptr<IValueSet> &valueSet) const
{
    if (!valueSet->IsValues2D()) { return {}; }

    int sizeOfTimes    = valueSet->GetIndexCount({0});
    int sizeOfElements = valueSet->GetIndexCount({0, 0});

    vector<vector<any>> data(sizeOfTimes);
    for (int t = 0; t < sizeOfTimes; ++t)
    {
        vector<any> ts(sizeOfElements);
        for (int i = 0; i < sizeOfElements; ++i)
        {
            ts[i] = valueSet->GetValue({t, i});
        }

        data[t] = ts;
    }

    return data;
}

bool ValueSet2D::IsValidValueType(const any &value) const
{
    return true;
}

void ValueSet2D::CheckIndicesOutOfDimension(const vector<int> &indices) const
{
    if (indices.empty()) { throw IllegalArgumentException("Empty indices specified."); }

    if (indices.size() > 2)
    {
        throw ArgumentOutOfRangeException(
            "The given indices were out of the value set dimensions(2).");
    }
}

void ValueSet2D::CheckAllDimensionSpecified(const vector<int> &indices) const
{
    if (indices.size() != 2)
    {
        throw ArgumentOutOfRangeException(
            "Invalid given indices exceeded or omitted the value set dimensions(2).");
    }
}

void ValueSet2D::CheckTimeIndex(int timeIndex) const
{
    if (timeIndex < 0)
    {
        throw IllegalArgumentException(
            "Invalid timeindex (" + to_string(timeIndex)
            + "), negative index not allowed.");
    }

    int size = GetTimesCount();
    if (timeIndex >= size)
    {
        throw IllegalArgumentException(
            "Invalid timeindex (" + to_string(timeIndex) + "), only " + to_string(size)
            + " times available.");
    }
}

void ValueSet2D::CheckElementIndex(int timeIndex, int elementIndex) const
{
    if (elementIndex < 0)
    {
        throw IllegalArgumentException(
            "Invalid elementindex (" + to_string(elementIndex)
            + "), negative index nog allowed.");
    }

    int size = GetElementsCount(timeIndex);
    if (elementIndex >= size)
    {
        throw IllegalArgumentException(
            "Invalid elementindex (" + to_string(elementIndex) + "), only "
            + to_string(size) + " elements available.");
    }
}


// class IntValueSet2D-----------------------------------------------------------------

bool IntValueSet2D::IsValidValueType(const any &value) const
{
    try
    {
        auto data = any_cast<int>(value);
        return true;
    }
    catch (const std::bad_any_cast &e)
    {
        return false;
    }
}


// class StrValueSet2D-----------------------------------------------------------------

bool StrValueSet2D::IsValidValueType(const any &value) const
{
    try
    {
        auto data = any_cast<string>(value);
        return true;
    }
    catch (const std::bad_any_cast &e)
    {
        return false;
    }
}


// class DblValueSet2D-----------------------------------------------------------------

DblValueSet2D::DblValueSet2D(
    const vector<vector<double>> &values2D, shared_ptr<IQuantity> valueDef)
{
    for (const auto &arr : values2D)
    {
        vector<any> tmp;
        for (const auto &val : arr)
        {
            tmp.emplace_back(val);
        }

        mValues2D.emplace_back(tmp);
    }

    mValueDef = move(valueDef);
}

bool DblValueSet2D::IsValidValueType(const any &value) const
{
    try
    {
        auto data = any_cast<double>(value);
        return true;
    }
    catch (const std::bad_any_cast &e)
    {
        return false;
    }
}


}  // namespace OpenOasis::CommImpl