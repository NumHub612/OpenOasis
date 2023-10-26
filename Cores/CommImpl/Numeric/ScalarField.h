/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  ScalarField.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  ScalarField for the definition and calculation of scalar fields.
 *
 ** ***********************************************************************************/
#pragma once
#include "Field.h"
#include <type_traits>


namespace OpenOasis::CommImpl::Numeric
{
/// @brief Scaler field with default value 0.
template <typename T>
class ScalarField : public Field<T>
{
public:
    static_assert(
        std::is_arithmetic<T>::value,
        "ScalarField only can be instantiated with arithmetic types");

    virtual ~ScalarField() = default;

    ScalarField() : mType(FieldType::SCALAR)
    {}
    ScalarField(std::size_t size, T val = 0) : Field<T>(size, val)
    {
        mType = FieldType::SCALAR;
    }
};

using ScalarFieldDbl = ScalarField<double>;
using ScalarFieldInt = ScalarField<int>;

}  // namespace OpenOasis::CommImpl::Numeric