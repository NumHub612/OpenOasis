

# File VectorField.h

[**File List**](files.md) **>** [**CommImp**](dir_6202b98a8704f42b1ea358646461643f.md) **>** [**Numeric**](dir_a0ece07902893bffce0f747cc8ee06c8.md) **>** [**VectorField.h**](_vector_field_8h.md)

[Go to the documentation of this file](_vector_field_8h.md)


```C++

#pragma once
#include "Models/Utils/CommConstants.h"
#include "Field.h"
#include "Vector.h"


namespace OpenOasis::CommImp::Numeric
{
template <typename T, std::size_t N = 3>
class VectorField : public Field<Vector<T, N>>
{
public:
    virtual ~VectorField() = default;

    VectorField(FieldDomain domain = FieldDomain::CELL)
    {
        this->mDomain = domain;
        this->mType   = FieldType::VECTOR;
    }

    VectorField(
        std::size_t size, const Vector<T, N> &val = {},
        FieldDomain domain = FieldDomain::CELL) :
        Field<Vector<T, N>>(size, val)
    {
        this->mDomain = domain;
        this->mType   = FieldType::VECTOR;
    }
};

using VectorFieldInt3D = VectorField<int, 3>;
using VectorFieldInt2D = VectorField<int, 2>;
using VectorFieldDbl3D = VectorField<double, 3>;
using VectorFieldDbl2D = VectorField<double, 2>;
using VectorFieldFp    = VectorField<Utils::real, 3>;

}  // namespace OpenOasis::CommImp::Numeric
```


