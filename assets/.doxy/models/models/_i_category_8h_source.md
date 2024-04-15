

# File ICategory.h

[**File List**](files.md) **>** [**Inc**](dir_e48a3e9a07fc2444cdac51c67822643f.md) **>** [**ICategory.h**](_i_category_8h.md)

[Go to the documentation of this file](_i_category_8h.md)


```C++

#pragma once
#include "IDescribable.h"
#include <any>


namespace OpenOasis
{
class ICategory : public IDescribable
{
public:
    virtual std::any GetValue() const = 0;
};

}  // namespace OpenOasis
```


