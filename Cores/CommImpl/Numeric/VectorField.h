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
#include <vector>
#include <array>
#include <algorithm>


namespace OpenOasis
{
namespace CommImpl
{
namespace Numeric
{
/// @brief Vector field for 2d and 3d cases.
template <typename T, size_t N>
class VectorField
{
public:
    static_assert(N > 0, "Size of static-sized vector should be greater than zero.");
    static_assert(
        std::is_arithmetic<T>::value,
        "VectorField only can be instantiated with arithmetic types");

    explicit VectorField(int size)
    {
        mDefault = {};
        mData.resize(size);
    }

    /// @brief Initialize the vector field with a value.
    /// @param value The initial value.
    void Initialize(std::array<T, N> value)
    {
        mDefault = value;
        std::fill(data.begin(), data.end(), value);
    }

    /// @brief Resize the vector field.
    /// @param size The new size.
    void Resize(int size)
    {
        mData.resize(size);
        mData.shrink_to_fit();
    }

    /// @brief Clean the vector field data to the default value.
    void Clean()
    {
        std::fill(data.begin(), data.end(), mDefault);
    }

    /// @brief Clear the vector field.
    void Clear()
    {
        mData.clear();
    }

    std::array<T, N> &operator[](int i)
    {
        return mData.at(i);
    }

private:
    std::vector<std::array<T, N>> mData;
    std::array<T, N>              mDefault;
};

}  // namespace Numeric
}  // namespace CommImpl
}  // namespace OpenOasis