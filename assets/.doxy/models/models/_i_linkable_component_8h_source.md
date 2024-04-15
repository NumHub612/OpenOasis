

# File ILinkableComponent.h

[**File List**](files.md) **>** [**Inc**](dir_e48a3e9a07fc2444cdac51c67822643f.md) **>** [**ILinkableComponent.h**](_i_linkable_component_8h.md)

[Go to the documentation of this file](_i_linkable_component_8h.md)


```C++

#pragma once
#include "IAdaptedOutputFactory.h"
#include "LinkableComponentStatus.h"
#include "LinkableComponentStatusChangeEventArgs.h"


namespace OpenOasis
{
class ILinkableComponent : public IIdentifiable
{
public:
    using ListenFunc =
        std::function<void(std::shared_ptr<LinkableComponentStatusChangeEventArgs>)>;

public:
    virtual std::vector<std::shared_ptr<IArgument>> GetArguments() const = 0;

    virtual LinkableComponentStatus GetStatus() const = 0;

    virtual std::vector<std::shared_ptr<IInput>> GetInputs() const = 0;

    virtual std::vector<std::shared_ptr<IOutput>> GetOutputs() const = 0;

    virtual std::vector<std::shared_ptr<IAdaptedOutputFactory>>
    GetAdaptedOutputFactories() const = 0;

    virtual void Initialize() = 0;

    virtual std::vector<std::string> Validate() = 0;

    virtual void Prepare() = 0;

    virtual void Update() = 0;

    virtual void Finish() = 0;

    virtual void RemoveListener(const ListenFunc &func) = 0;
    virtual void AddListener(const ListenFunc &func)    = 0;
};

}  // namespace OpenOasis
```


