

# File LinkableComponentStatusChangeEventArgs.h

[**File List**](files.md) **>** [**Inc**](dir_e48a3e9a07fc2444cdac51c67822643f.md) **>** [**LinkableComponentStatusChangeEventArgs.h**](_linkable_component_status_change_event_args_8h.md)

[Go to the documentation of this file](_linkable_component_status_change_event_args_8h.md)


```C++

#pragma once
#include <memory>
#include <string>
#include "LinkableComponentStatus.h"


namespace OpenOasis
{
class ILinkableComponent;

class LinkableComponentStatusChangeEventArgs
{
public:
    // The linkable component that fired the status change event.
    //

    virtual std::shared_ptr<ILinkableComponent> GetLinkableComponent() const = 0;

    virtual void SetLinkableComponent(std::shared_ptr<ILinkableComponent> obj) = 0;

    // The linkable component's status before the status change.
    //

    virtual LinkableComponentStatus GetOldStatus() const = 0;

    virtual void SetOldStatus(LinkableComponentStatus value) = 0;

    // The linkable component's status after the status change.
    //

    virtual LinkableComponentStatus GetNewStatus() const = 0;

    virtual void SetNewStatus(LinkableComponentStatus value) = 0;

    // Message providing additional information on the status change.
    //

    virtual std::string GetMessages() const = 0;

    virtual void SetMessages(const std::string &msg) = 0;
};

}  // namespace OpenOasis
```


