

# File IManageState.h

[**File List**](files.md) **>** [**Inc**](dir_e48a3e9a07fc2444cdac51c67822643f.md) **>** [**IManageState.h**](_i_manage_state_8h.md)

[Go to the documentation of this file](_i_manage_state_8h.md)


```C++

#pragma once
#include "IIdentifiable.h"
#include <memory>


namespace OpenOasis
{
class IManageState
{
public:
    virtual std::shared_ptr<IIdentifiable> KeepCurrentState() = 0;

    virtual void RestoreState(const std::shared_ptr<IIdentifiable> &stateId) = 0;

    virtual void ClearState(const std::shared_ptr<IIdentifiable> &stateId) = 0;
};

}  // namespace OpenOasis
```


