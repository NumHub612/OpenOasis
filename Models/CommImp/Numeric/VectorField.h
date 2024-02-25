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


namespace OpenOasis::CommImp::Numeric
{
/// @brief Vector field with default zero vector in 2D or 3D space.
template <typename T, std::size_t N = 3>
class VectorField : public Field<Vector<T, N>>
{
public:
    virtual ~VectorField() = default;

    VectorField(FieldRange range = FieldRange::CELL)
    {
        this->mRange = range;
        this->mType  = FieldType::VECTOR;
    }

    VectorField(
        std::size_t size, const Vector<T, N> &val = {},
        FieldRange range = FieldRange::CELL) :
        Field<Vector<T, N>>(size, val)
    {
        this->mRange = range;
        this->mType  = FieldType::VECTOR;
    }
};

using VectorFieldInt3D = VectorField<int, 3>;
using VectorFieldInt2D = VectorField<int, 2>;
using VectorFieldDbl3D = VectorField<double, 3>;
using VectorFieldDbl2D = VectorField<double, 2>;

}  // namespace OpenOasis::CommImp::Numeric