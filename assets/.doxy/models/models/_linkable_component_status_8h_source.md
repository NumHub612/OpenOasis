

# File LinkableComponentStatus.h

[**File List**](files.md) **>** [**Inc**](dir_e48a3e9a07fc2444cdac51c67822643f.md) **>** [**LinkableComponentStatus.h**](_linkable_component_status_8h.md)

[Go to the documentation of this file](_linkable_component_status_8h.md)


```C++

#pragma once


namespace OpenOasis
{
enum class LinkableComponentStatus
{
    Created,

    Initializing,

    Initialized,

    Validating,

    Valid,

    WaitingForData,

    Invalid,

    Preparing,

    Updating,

    Updated,

    Done,

    Finishing,

    Finished,

    Failed
};

}  // namespace OpenOasis
```


