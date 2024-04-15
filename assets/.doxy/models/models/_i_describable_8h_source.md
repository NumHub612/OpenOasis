

# File IDescribable.h

[**File List**](files.md) **>** [**Inc**](dir_e48a3e9a07fc2444cdac51c67822643f.md) **>** [**IDescribable.h**](_i_describable_8h.md)

[Go to the documentation of this file](_i_describable_8h.md)


```C++

#pragma once
#include <string>


namespace OpenOasis
{
class IDescribable
{
public:
    // Caption string.
    //

    virtual std::string GetCaption() const = 0;

    virtual void SetCaption(const std::string &value) = 0;

    // Additional descriptive information about the entity.
    //

    virtual std::string GetDescription() const = 0;

    virtual void SetDescription(const std::string &value) = 0;
};

}  // namespace OpenOasis
```


