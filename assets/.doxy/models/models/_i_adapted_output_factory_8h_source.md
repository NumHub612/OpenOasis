

# File IAdaptedOutputFactory.h

[**File List**](files.md) **>** [**Inc**](dir_e48a3e9a07fc2444cdac51c67822643f.md) **>** [**IAdaptedOutputFactory.h**](_i_adapted_output_factory_8h.md)

[Go to the documentation of this file](_i_adapted_output_factory_8h.md)


```C++

#pragma once
#include "IAdaptedOutput.h"
#include "IOutput.h"


namespace OpenOasis
{
class IAdaptedOutputFactory : public IIdentifiable
{
public:
    virtual std::vector<std::shared_ptr<IIdentifiable>> GetAvailableAdaptedOutputIds(
        const std::shared_ptr<IOutput> &adaptee,
        const std::shared_ptr<IInput>  &target) = 0;

    virtual std::shared_ptr<IAdaptedOutput> CreateAdaptedOutput(
        const std::shared_ptr<IIdentifiable> &adaptedOutputId,
        const std::shared_ptr<IOutput>       &adaptee,
        const std::shared_ptr<IInput>        &target) = 0;
};

}  // namespace OpenOasis
```


