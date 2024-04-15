

# File IValueSet.h

[**File List**](files.md) **>** [**Inc**](dir_e48a3e9a07fc2444cdac51c67822643f.md) **>** [**IValueSet.h**](_i_value_set_8h.md)

[Go to the documentation of this file](_i_value_set_8h.md)


```C++

#pragma once
#include "IValueDefinition.h"
#include <any>
#include <typeinfo>
#include <vector>
#include <memory>


namespace OpenOasis
{
class IValueSet
{
public:
    // Generic value set with multi-dimensional.
    //

    virtual std::shared_ptr<IValueDefinition> GetValueDefinition() const = 0;

    virtual int GetNumberOfIndices() const = 0;

    virtual int GetIndexCount(const std::vector<int> &indices) const = 0;

    virtual std::any GetValue(const std::vector<int> &indices) const = 0;

    virtual void RemoveValue(const std::vector<int> &indices) = 0;

    virtual void
    SetOrAddValue(const std::vector<int> &indices, const std::any &value) = 0;

    // Two-dimensional list of values.
    //
    // The first dimension represents time corresponding to the `ITimeSet`,
    // the second contains each elements value corresponding to the `IElementSet`.
    //

    virtual bool IsValues2D() const = 0;

    virtual std::vector<std::any>
    GetTimeSeriesValuesForElement(int elementIndex) const = 0;

    virtual void SetTimeSeriesValuesForElement(
        int elementIndex, const std::vector<std::any> &values) = 0;

    virtual void
    SetElementValuesForTime(int timeIndex, const std::vector<std::any> &values) = 0;

    virtual std::vector<std::any> GetElementValuesForTime(int timeIndex) const = 0;
};

}  // namespace OpenOasis
```


