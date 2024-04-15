

# File IValueDefinition.h

[**File List**](files.md) **>** [**Inc**](dir_e48a3e9a07fc2444cdac51c67822643f.md) **>** [**IValueDefinition.h**](_i_value_definition_8h.md)

[Go to the documentation of this file](_i_value_definition_8h.md)


```C++

#pragma once
#include "IDescribable.h"
#include <any>
#include <typeinfo>


namespace OpenOasis
{
class IValueDefinition : public IDescribable
{
public:
    virtual const std::type_info &GetValueType() const = 0;

    virtual std::any GetMissingDataValue() const = 0;
};

}  // namespace OpenOasis
```


