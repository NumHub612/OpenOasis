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


namespace OpenOasis::CommImpl::Numeric
{
/// @brief Tensor field.
template <typename T>
class TensorField : public Field<Tensor<T>>
{
public:
    virtual ~TensorField() = default;

    TensorField(FieldRange range = FieldRange::CELL)
    {
        this->mRange = range;
        this->mType  = FieldType::TENSOR;
    }

    TensorField(
        std::size_t size, const Tensor<T> &val = {},
        FieldRange range = FieldRange::CELL) :
        Field<Tensor<T>>(size, val)
    {
        this->mRange = range;
        this->mType  = FieldType::TENSOR;
    }
};

using TensorFieldInt = TensorField<int>;
using TensorFieldDbl = TensorField<double>;

}  // namespace OpenOasis::CommImpl::Numeric