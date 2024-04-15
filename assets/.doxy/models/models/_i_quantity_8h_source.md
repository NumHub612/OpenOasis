

# File IQuantity.h

[**File List**](files.md) **>** [**Inc**](dir_e48a3e9a07fc2444cdac51c67822643f.md) **>** [**IQuantity.h**](_i_quantity_8h.md)

[Go to the documentation of this file](_i_quantity_8h.md)


```C++

#pragma once
#include "IUnit.h"
#include "IValueDefinition.h"


namespace OpenOasis
{
class IQuantity : public IValueDefinition
{
public:
    virtual std::shared_ptr<IUnit> GetUnit() const = 0;
};

}  // namespace OpenOasis
```


