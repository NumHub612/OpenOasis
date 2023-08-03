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
#include <vector>
#include <algorithm>


namespace OpenOasis
{
namespace CommImpl
{
namespace Numeric
{
/// @brief Tensor field for 2d and 3d cases.
template <typename T, size_t N>
class TensorField
{
public:
    static_assert(N > 0, "Size of static-sized tensor should be greater than zero.");
    static_assert(
        std::is_arithmetic<T>::value,
        "TensorField only can be instantiated with arithmetic types");

    explicit TensorField(int size)
    {
        mDefault = {};
        mData.resize(size);
    }

    /// @brief Initialize the tensor field with a value.
    /// @param value The initial value.
    void Initialize(std::array<std::array<T, N>, N> value)
    {
        mDefault = value;
        std::fill(data.begin(), data.end(), value);
    }

    /// @brief Resize the tensor field.
    /// @param size The new size.
    void Resize(int size)
    {
        mData.resize(size);
        mData.shrink_to_fit();
    }

    /// @brief Clean the tensor field data to the default value.
    void Clean()
    {
        std::fill(data.begin(), data.end(), mDefault);
    }

    /// @brief Clear the tensor field.
    void Clear()
    {
        mData.clear();
    }

    std::array<std::array<T, N>, N> &operator[](int i)
    {
        return mData.at(i);
    }

private:
    std::vector<sstd::array<std::array<T, N>, N>> mData;
    std::array<std::array<T, N>, N>               mDefault;
};

}  // namespace Numeric
}  // namespace CommImpl
}  // namespace OpenOasis