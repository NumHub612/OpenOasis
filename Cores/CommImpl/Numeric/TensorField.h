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
/// @brief Tensor field with default zero tensor.
template <typename T>
class TensorField : public Field<Tensor<T>>
{
public:
    virtual ~TensorField() = default;

    TensorField() = default;
    TensorField(std::size_t size, const Tensor<T> &value = {}) :
        Field<Tensor<T>>(size, value)
    {}

    FieldType Type() const override
    {
        return FieldType::TENSOR;
    }
};

using TensorFieldInt = TensorField<int>;
using TensorFieldDbl = TensorField<double>;

}  // namespace OpenOasis::CommImpl::Numeric