/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  ValueSet2D.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  To represent an ordered two-dimensional list of values.
 *
 ** ***********************************************************************************/
#pragma once
#include "Cores/Inc/IValueSet.h"
#include "Cores/Inc/IQuantity.h"


namespace OpenOasis
{
namespace CommImpl
{
/// @brief Common implementation of `IValueSet` in two dimension (time-space).
class ValueSet2D : public IValueSet
{
protected:
    std::vector<std::vector<std::any>> mValues2D;
    std::shared_ptr<IQuantity>         mValueDef;

public:
    virtual ~ValueSet2D()
    {}
    ValueSet2D()
    {}

    ValueSet2D(std::shared_ptr<IQuantity> valueDef);
    ValueSet2D(const std::shared_ptr<IValueSet> &valueSet);
    ValueSet2D(ValueSet2D &&obj);

    // ValueSet2D(
    //     const std::vector<std::vector<std::any>> &values2D,
    //     std::shared_ptr<IQuantity>                valueDef);
    // ValueSet2D(
    //     const std::vector<std::vector<double>> &values2D,
    //     std::shared_ptr<IQuantity>              valueDef);

    ///////////////////////////////////////////////////////////////////////////////////
    // Implement methods inherited from `IValueSet`.
    //

    virtual std::shared_ptr<IValueDefinition> GetValueDefinition() const override;

    virtual std::any GetValue(const std::vector<int> &indices) const override;

    virtual void
    SetOrAddValue(const std::vector<int> &indices, const std::any &value) override;

    virtual void RemoveValue(const std::vector<int> &indices) override;

    virtual int GetNumberOfIndices() const override;

    virtual int GetIndexCount(const std::vector<int> &indices) const override;

    virtual bool IsValues2D() const override;

    virtual std::vector<std::any>
    GetTimeSeriesValuesForElement(int elementIndex) const override;

    virtual void SetTimeSeriesValuesForElement(
        int elementIndex, const std::vector<std::any> &values) override;

    virtual std::vector<std::any> GetElementValuesForTime(int timeIndex) const override;

    virtual void SetElementValuesForTime(
        int timeIndex, const std::vector<std::any> &values) override;

    ///////////////////////////////////////////////////////////////////////////////////
    // Local methods for convenience.
    //

    int GetElementsCount(int timeIndex) const;

    int GetTimesCount() const;

    void SetValueDefinition(std::shared_ptr<IValueDefinition> value);

protected:
    // To check if given indices out of the value set dimensions.
    void CheckIndicesOutOfDimension(const std::vector<int> &indices) const;

    // To check if each dimension were specified.
    void CheckAllDimensionSpecified(const std::vector<int> &indices) const;

    std::vector<std::vector<std::any>>
    GetValues(const std::shared_ptr<IValueSet> &valueSet) const;

    void AddValue(const std::vector<int> &indices, const std::any &value);

    // To check if the value type match the value set while adding/setting value in.
    virtual bool IsValidValueType(const std::any &value) const;

    void CheckTimeIndex(int timeIndex) const;

    void CheckElementIndex(int timeIndex, int elementIndex) const;
};


/// @brief Two-dimensional value set contains integer data.
class ValueSetInt : public ValueSet2D
{
private:
    bool IsValidValueType(const std::any &value) const override;
};


/// @brief Two-dimensional value set contains string data.
class ValueSetStr : public ValueSet2D
{
private:
    bool IsValidValueType(const std::any &value) const override;
};


/// @brief Two-dimensional value set contains double data.
class ValueSetDbl : public ValueSet2D
{
public:
    virtual ~ValueSetDbl() = default;
    ValueSetDbl(
        const std::vector<std::vector<double>> &values2D,
        std::shared_ptr<IQuantity>              valueDef);

private:
    bool IsValidValueType(const std::any &value) const override;
};

}  // namespace CommImpl
}  // namespace OpenOasis