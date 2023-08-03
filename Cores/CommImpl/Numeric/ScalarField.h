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
#include <vector>
#include <algorithm>


namespace OpenOasis
{
namespace CommImpl
{
namespace Numeric
{
/// @brief Scaler field.
template <typename T>
class ScalarField
{
public:
    static_assert(
        std::is_arithmetic<T>::value,
        "ScalarField only can be instantiated with arithmetic types");

    explicit ScalarField(int size)
    {
        mDefault = 0;
        mData.resize(size);
    }

    /// @brief Initialize the scalar field with a value.
    /// @param value The initial value.
    void Initialize(T value)
    {
        mDefault = value;
        std::fill(data.begin(), data.end(), value);
    }

    /// @brief Resize the scalar field.
    /// @param size The new size.
    void Resize(int size)
    {
        mData.resize(size);
        mData.shrink_to_fit();
    }

    /// @brief Clean the scalar field data to the default value.
    void Clean()
    {
        std::fill(data.begin(), data.end(), mDefault);
    }

    /// @brief Clear the scalar field.
    void Clear()
    {
        mData.clear();
    }

    T &operator[](int i)
    {
        return mData.at(i);
    }

private:
    std::vector<T> mData;
    T              mDefault;
};

}  // namespace Numeric
}  // namespace CommImpl
}  // namespace OpenOasis