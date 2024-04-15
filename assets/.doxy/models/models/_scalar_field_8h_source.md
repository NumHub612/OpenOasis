

# File ScalarField.h

[**File List**](files.md) **>** [**CommImp**](dir_6202b98a8704f42b1ea358646461643f.md) **>** [**Numeric**](dir_a0ece07902893bffce0f747cc8ee06c8.md) **>** [**ScalarField.h**](_scalar_field_8h.md)

[Go to the documentation of this file](_scalar_field_8h.md)


```C++

#pragma once
#include "Models/Utils/CommConstants.h"
#include "Field.h"
#include <type_traits>


namespace OpenOasis::CommImp::Numeric
{
template <typename T>
class ScalarField : public Field<T>
{
public:
    static_assert(
        std::is_arithmetic<T>::value,
        "ScalarField only can be instantiated with arithmetic types");

    virtual ~ScalarField() = default;

    ScalarField(std::size_t size, T val = 0, FieldDomain domain = FieldDomain::CELL) :
        Field<T>(size, val)
    {
        this->mDomain = domain;
        this->mType   = FieldType::SCALAR;
    }

    ScalarField(FieldDomain domain = FieldDomain::CELL)
    {
        this->mDomain = domain;
        this->mType   = FieldType::SCALAR;
    }
};

using ScalarFieldDbl = ScalarField<double>;
using ScalarFieldInt = ScalarField<int>;
using ScalarFieldFp  = ScalarField<Utils::real>;

}  // namespace OpenOasis::CommImp::Numeric
```


