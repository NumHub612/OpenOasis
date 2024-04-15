

# File ITimeSet.h

[**File List**](files.md) **>** [**Inc**](dir_e48a3e9a07fc2444cdac51c67822643f.md) **>** [**ITimeSet.h**](_i_time_set_8h.md)

[Go to the documentation of this file](_i_time_set_8h.md)


```C++

#pragma once
#include "ITime.h"
#include <vector>
#include <memory>


namespace OpenOasis
{
class ITimeSet
{
public:
    virtual std::vector<std::shared_ptr<ITime>> GetTimes() const = 0;

    virtual void RemoveTime(int index) = 0;

    virtual void AddTime(std::shared_ptr<ITime> time) = 0;

    virtual bool HasDurations() const = 0;

    virtual double GetOffsetFromUtcInHours() const = 0;

    virtual std::shared_ptr<ITime> GetTimeHorizon() const = 0;
};

}  // namespace OpenOasis
```


