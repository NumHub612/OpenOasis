

# File IQuality.h

[**File List**](files.md) **>** [**Inc**](dir_e48a3e9a07fc2444cdac51c67822643f.md) **>** [**IQuality.h**](_i_quality_8h.md)

[Go to the documentation of this file](_i_quality_8h.md)


```C++

#pragma once
#include "IValueDefinition.h"
#include "ICategory.h"
#include <vector>
#include <memory>


namespace OpenOasis
{
class IQuality : public IValueDefinition
{
public:
    virtual std::vector<std::shared_ptr<ICategory>> GetCategories() const = 0;

    virtual bool IsOrdered() const = 0;
};

}  // namespace OpenOasis
```


