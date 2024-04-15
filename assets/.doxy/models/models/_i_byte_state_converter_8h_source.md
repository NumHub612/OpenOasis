

# File IByteStateConverter.h

[**File List**](files.md) **>** [**Inc**](dir_e48a3e9a07fc2444cdac51c67822643f.md) **>** [**IByteStateConverter.h**](_i_byte_state_converter_8h.md)

[Go to the documentation of this file](_i_byte_state_converter_8h.md)


```C++

#pragma once
#include "IIdentifiable.h"
#include <vector>
#include <memory>


namespace OpenOasis
{
class IByteStateConverter
{
public:
    virtual std::stringstream
    ConvertToByteStream(const std::shared_ptr<IIdentifiable> &stateId) = 0;

    virtual std::shared_ptr<IIdentifiable>
    ConvertFromByteStream(const std::stringstream &byteStream) = 0;
};

}  // namespace OpenOasis
```


