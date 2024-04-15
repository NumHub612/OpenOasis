

# File IUnit.h

[**File List**](files.md) **>** [**Inc**](dir_e48a3e9a07fc2444cdac51c67822643f.md) **>** [**IUnit.h**](_i_unit_8h.md)

[Go to the documentation of this file](_i_unit_8h.md)


```C++

#pragma once
#include "IDescribable.h"
#include "IDimension.h"
#include <memory>


namespace OpenOasis
{
class IUnit : public IDescribable
{
public:
    virtual std::shared_ptr<IDimension> GetDimension() const = 0;

    virtual double GetConversionFactorToSI() const = 0;

    virtual double GetOffSetToSI() const = 0;
};

}  // namespace OpenOasis
```


