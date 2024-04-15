

# File IOutput.h

[**File List**](files.md) **>** [**Inc**](dir_e48a3e9a07fc2444cdac51c67822643f.md) **>** [**IOutput.h**](_i_output_8h.md)

[Go to the documentation of this file](_i_output_8h.md)


```C++

#pragma once
#include "IBaseExchangeItem.h"
#include "IInput.h"
#include "IValueSet.h"


namespace OpenOasis
{
class IAdaptedOutput;

class IOutput : public IBaseExchangeItem
{
public:
    virtual std::vector<std::weak_ptr<IInput>> GetConsumers() const = 0;

    virtual void AddConsumer(std::shared_ptr<IInput> consumer) = 0;

    virtual void RemoveConsumer(const std::shared_ptr<IInput> &consumer) = 0;

    virtual std::vector<std::shared_ptr<IAdaptedOutput>> GetAdaptedOutputs() const = 0;

    virtual void
    RemoveAdaptedOutput(const std::shared_ptr<IAdaptedOutput> &adaptedOutput) = 0;

    virtual void AddAdaptedOutput(std::shared_ptr<IAdaptedOutput> adaptedOutput) = 0;
};

}  // namespace OpenOasis
```


