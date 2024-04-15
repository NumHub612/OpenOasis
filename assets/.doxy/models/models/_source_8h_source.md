

# File Source.h

[**File List**](files.md) **>** [**CommImp**](dir_6202b98a8704f42b1ea358646461643f.md) **>** [**Numeric**](dir_a0ece07902893bffce0f747cc8ee06c8.md) **>** [**Source.h**](_source_8h.md)

[Go to the documentation of this file](_source_8h.md)


```C++

#pragma once
#include <vector>

namespace OpenOasis::CommImp::Numeric
{
class Source
{
public:
    virtual std::vector<double> GetSource() = 0;
};
}  // namespace OpenOasis::CommImp::Numeric
```


