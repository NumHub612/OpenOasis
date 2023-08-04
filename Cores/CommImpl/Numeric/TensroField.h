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
#include "Tensor.h"
#include <vector>
#include <array>
#include <algorithm>


namespace OpenOasis
{
namespace CommImpl
{
namespace Numeric
{
/// @brief Description and manipulation of 2D or 3D tensor data.
template <typename T, std::size_t N>
class TensorField
{
public:
    virtual ~TensorField() = default;
    TensorField(std::size_t size)
    {
        mData.resize(size, Tensor<T, N>());
    }

    ///////////////////////////////////////////////////////////////////////////////////
    // Methods for the tensor data operation.
    //

    /// @brief Initialize the tensor field with specified value.
    /// @param value The initial value.
    void Initialize(const Tensor<T, N> &value)
    {
        std::fill(mData.begin(), mData.end(), value);
    }

    /// @brief Resize the tensor field.
    /// @param size The new size.
    void Resize(std::size_t size)
    {
        mData.resize(size);
        mData.shrink_to_fit();
    }

    /// @brief Clean the tensor field data to the default value.
    void Clean()
    {
        std::fill(mData.begin(), mData.end(), Tensor<T, N>());
    }

    /// @brief Clear the tensor field.
    void Clear()
    {
        mData.clear();
    }

    Tensor<T, N> &operator()(int i)
    {
        return mData.at(i);
    }

    ///////////////////////////////////////////////////////////////////////////////////
    // Methods for the tensor field operation.
    //

private:
    std::vector<Tensor<T, N>> mData;
};

}  // namespace Numeric
}  // namespace CommImpl
}  // namespace OpenOasis