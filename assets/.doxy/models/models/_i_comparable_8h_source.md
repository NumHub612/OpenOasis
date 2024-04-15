

# File IComparable.h

[**File List**](files.md) **>** [**AdditionalControl**](dir_f42854fb7a47e961c6b84a97d295c858.md) **>** [**IComparable.h**](_i_comparable_8h.md)

[Go to the documentation of this file](_i_comparable_8h.md)


```C++

#pragma once
#include <memory>


namespace OpenOasis
{
namespace AdditionalControl
{
class IComparable
{
public:
    virtual int CompareTo(const std::shared_ptr<IComparable> &obj) const = 0;
};


}  // namespace AdditionalControl
}  // namespace OpenOasis
```


