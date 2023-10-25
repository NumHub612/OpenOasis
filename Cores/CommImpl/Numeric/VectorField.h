/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  VectorField.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  VectorField for the definition and calculation of vector fields.
 *
 ** ***********************************************************************************/
#pragma once
#include "Field.h"
#include "Vector.h"


namespace OpenOasis::CommImpl::Numeric
{
/// @brief Vector field with default zero vector in 2D or 3D space.
template <typename T, std::size_t N>
class VectorField : public Field<Vector<T, N>>
{
public:
    virtual ~VectorField() = default;

    VectorField() = default;
    VectorField(std::size_t size, const Vector<T, N> &value = {}) :
        Field<Vector<T, N>>(size, value){};

    FieldType Type() const override
    {
        return FieldType::VECTOR;
    }
};

using VectorFieldInt3D = VectorField<int, 3>;
using VectorFieldInt2D = VectorField<int, 2>;
using VectorFieldDbl3D = VectorField<double, 3>;
using VectorFieldDbl2D = VectorField<double, 2>;

}  // namespace OpenOasis::CommImpl::Numeric