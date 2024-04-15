

# File ISpaceExtension.h

[**File List**](files.md) **>** [**AdditionalControl**](dir_f42854fb7a47e961c6b84a97d295c858.md) **>** [**ISpaceExtension.h**](_i_space_extension_8h.md)

[Go to the documentation of this file](_i_space_extension_8h.md)


```C++

#pragma once
#include "Models/Inc/ISpatialDefinition.h"
#include <memory>


namespace OpenOasis
{
namespace AdditionalControl
{
class ISpaceExtension
{
public:
    virtual std::shared_ptr<ISpatialDefinition> GetSpatialDefinition() const = 0;
};

}  // namespace AdditionalControl
}  // namespace OpenOasis
```


