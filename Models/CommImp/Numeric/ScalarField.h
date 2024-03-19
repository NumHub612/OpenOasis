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
#include "Models/Utils/CommMacros.h"
#include "Field.h"
#include <type_traits>


namespace OpenOasis::CommImp::Numeric
{
/// @brief Scaler field.
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