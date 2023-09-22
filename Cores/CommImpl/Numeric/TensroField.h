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
/// @brief Description and manipulation of the 3D tensor fields.
template <typename T>
class TensorField
{
private:
    std::vector<Tensor<T>> mData;

public:
    virtual ~TensorField() = default;
    TensorField(std::size_t size)
    {
        mData.resize(size, Tensor<T>());
    }

    /// @brief Initialize the tensor field with specified value.
    /// @param value The initial value.
    void Initialize(const Tensor<T> &value)
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

    /// @brief Clean the tensor field data to default value (0).
    void Clean()
    {
        std::fill(mData.begin(), mData.end(), Tensor<T>());
    }

    /// @brief Clear the tensor field.
    void Clear()
    {
        mData.clear();
    }

    /// @brief Iterates the field and invoke given @p func for each element.
    ///
    /// This function iterates the field elements and invoke
    /// the callback function @p func. The callback function takes
    /// field's element as its input.
    template <typename Callback>
    void ForEach(Callback func)
    {
        for (auto &elem : mData) { func(elem); }
    }

    std::size_t Size() const
    {
        return mData.size();
    }

    void SetAt(std::size_t i, const Tensor<T> &value)
    {
        mData.at(i) = value;
    }

    void SetAt(
        std::size_t start, std::size_t end, const TensorField &other,
        std::size_t offset = 0)
    {
        std::size_t j = offset;
        for (std::size_t i = start; i < end; ++i) mData.at(i) = other(j++);
    }

    Tensor<T> &operator()(int i)
    {
        return mData.at(i);
    }

    const Tensor<T> &operator()(int i) const
    {
        return mData.at(i);
    }
};

}  // namespace Numeric
}  // namespace CommImpl
}  // namespace OpenOasis