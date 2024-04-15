

# File IArgument.h

[**File List**](files.md) **>** [**Inc**](dir_e48a3e9a07fc2444cdac51c67822643f.md) **>** [**IArgument.h**](_i_argument_8h.md)

[Go to the documentation of this file](_i_argument_8h.md)


```C++

#pragma once
#include "IIdentifiable.h"
#include <any>
#include <vector>
#include <typeinfo>


namespace OpenOasis
{
class IArgument : public IIdentifiable
{
public:
    virtual const std::type_info &GetValueType() const = 0;

    virtual bool IsOptional() const = 0;

    virtual bool IsReadOnly() const = 0;

    virtual std::any GetValue() const = 0;

    virtual void SetValue(std::any value) = 0;

    virtual std::any GetDefaultValue() const = 0;

    virtual std::vector<std::any> GetPossibleValues() const = 0;
};

}  // namespace OpenOasis
```


