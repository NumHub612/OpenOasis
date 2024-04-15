

# File ISpatialDefinition.h

[**File List**](files.md) **>** [**Inc**](dir_e48a3e9a07fc2444cdac51c67822643f.md) **>** [**ISpatialDefinition.h**](_i_spatial_definition_8h.md)

[Go to the documentation of this file](_i_spatial_definition_8h.md)


```C++

#pragma once
#include "IDescribable.h"


namespace OpenOasis
{
class ISpatialDefinition : public IDescribable
{
public:
    virtual std::string GetSpatialReferenceSystem() const = 0;

    virtual int GetElementCount() const = 0;

    virtual int GetVersion() const = 0;
};

}  // namespace OpenOasis
```


