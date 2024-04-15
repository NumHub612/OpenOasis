

# File IInput.h

[**File List**](files.md) **>** [**Inc**](dir_e48a3e9a07fc2444cdac51c67822643f.md) **>** [**IInput.h**](_i_input_8h.md)

[Go to the documentation of this file](_i_input_8h.md)


```C++

#pragma once
#include "IBaseExchangeItem.h"
#include "IValueSet.h"
#include "ITimeSet.h"


namespace OpenOasis
{
class IOutput;

class IInput : public IBaseExchangeItem
{
public:
    virtual std::vector<std::weak_ptr<IOutput>> GetProviders() const = 0;

    virtual void AddProvider(std::shared_ptr<IOutput> provider) = 0;

    virtual void RemoveProvider(const std::shared_ptr<IOutput> &provider) = 0;
};

}  // namespace OpenOasis
```


