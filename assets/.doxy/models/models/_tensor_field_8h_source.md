

# File TensorField.h

[**File List**](files.md) **>** [**CommImp**](dir_6202b98a8704f42b1ea358646461643f.md) **>** [**Numeric**](dir_a0ece07902893bffce0f747cc8ee06c8.md) **>** [**TensorField.h**](_tensor_field_8h.md)

[Go to the documentation of this file](_tensor_field_8h.md)


```C++

#pragma once
#include "Models/Utils/CommConstants.h"
#include "Field.h"
#include "Tensor.h"


namespace OpenOasis::CommImp::Numeric
{
template <typename T>
class TensorField : public Field<Tensor<T>>
{
public:
    virtual ~TensorField() = default;

    TensorField(FieldDomain domain = FieldDomain::CELL)
    {
        this->mDomain = domain;
        this->mType   = FieldType::TENSOR;
    }

    TensorField(
        std::size_t size, const Tensor<T> &val = {},
        FieldDomain domain = FieldDomain::CELL) :
        Field<Tensor<T>>(size, val)
    {
        this->mDomain = domain;
        this->mType   = FieldType::TENSOR;
    }
};

using TensorFieldDbl = TensorField<double>;
using TensorFieldInt = TensorField<int>;
using TensorFieldFp  = TensorField<Utils::real>;

}  // namespace OpenOasis::CommImp::Numeric
```


