

# File ITimeExtension.h

[**File List**](files.md) **>** [**AdditionalControl**](dir_f42854fb7a47e961c6b84a97d295c858.md) **>** [**ITimeExtension.h**](_i_time_extension_8h.md)

[Go to the documentation of this file](_i_time_extension_8h.md)


```C++

#pragma once
#include "Models/Inc/ITimeSet.h"
#include <memory>


namespace OpenOasis
{
namespace AdditionalControl
{
class ITimeExtension
{
public:
    virtual std::shared_ptr<ITimeSet> GetTimeExtent() const = 0;

    virtual std::shared_ptr<ITime> GetCurrTime() const = 0;
};

}  // namespace AdditionalControl
}  // namespace OpenOasis
```


