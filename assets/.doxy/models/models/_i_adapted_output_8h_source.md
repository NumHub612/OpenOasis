

# File IAdaptedOutput.h

[**File List**](files.md) **>** [**Inc**](dir_e48a3e9a07fc2444cdac51c67822643f.md) **>** [**IAdaptedOutput.h**](_i_adapted_output_8h.md)

[Go to the documentation of this file](_i_adapted_output_8h.md)


```C++

#pragma once
#include "IArgument.h"
#include "IOutput.h"


namespace OpenOasis
{
class IAdaptedOutput : public IOutput
{
public:
    virtual std::vector<std::shared_ptr<IArgument>> GetArguments() const = 0;

    virtual void Initialize() = 0;

    virtual std::weak_ptr<IOutput> GetAdaptee() const = 0;

    virtual void SetAdaptee(std::shared_ptr<IOutput> adaptee) = 0;

    virtual void Refresh() = 0;
};

}  // namespace OpenOasis
```


