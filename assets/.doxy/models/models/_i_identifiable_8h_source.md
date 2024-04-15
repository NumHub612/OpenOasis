

# File IIdentifiable.h

[**File List**](files.md) **>** [**Inc**](dir_e48a3e9a07fc2444cdac51c67822643f.md) **>** [**IIdentifiable.h**](_i_identifiable_8h.md)

[Go to the documentation of this file](_i_identifiable_8h.md)


```C++

#pragma once
#include "IDescribable.h"
#include <string>


namespace OpenOasis
{
class IIdentifiable : public IDescribable
{
public:
    virtual std::string GetId() const = 0;
};

}  // namespace OpenOasis
```


