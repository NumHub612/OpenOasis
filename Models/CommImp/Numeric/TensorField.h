/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  TensorField.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  TensorField for the definition and calculation of tensor fields.
 *
 ** ***********************************************************************************/
#pragma once
#include "Field.h"
#include "Tensor.h"


namespace OpenOasis::CommImp::Numeric
{
/// @brief Tensor field.
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