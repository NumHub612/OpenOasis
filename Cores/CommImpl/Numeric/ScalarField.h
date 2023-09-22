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
#include "Vector.h"
#include <vector>
#include <algorithm>


namespace OpenOasis
{
namespace CommImpl
{
namespace Numeric
{
/// @brief Scaler field with default value 0.
template <typename T>
class ScalarField
{
public:
    static_assert(
        std::is_arithmetic<T>::value,
        "ScalarField only can be instantiated with arithmetic types");

private:
    std::vector<T> mData;

public:
    virtual ~ScalarField() = default;
    ScalarField(std::size_t size, T val = 0)
    {
        mData.resize(size, val);
    }

    std::vector<T> Data()
    {
        return mData;
    }

    /// @brief Initialize the scalar field with a value.
    /// @param value The initial value.
    void Initialize(T value)
    {
        std::fill(mData.begin(), mData.end(), value);
    }

    /// @brief Resize the scalar field.
    /// @param size The new size.
    void Resize(std::size_t size)
    {
        mData.resize(size);
        mData.shrink_to_fit();
    }

    /// @brief Clean the scalar field data to the default value(0).
    void Clean()
    {
        std::fill(mData.begin(), mData.end(), T(0));
    }

    /// @brief Clear the scalar field.
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

    void SetAt(std::size_t i, T value)
    {
        mData.at(i) = value;
    }

    void SetAt(
        std::size_t start, std::size_t end, const ScalarField &other,
        std::size_t offset = 0)
    {
        std::size_t j = offset;
        for (std::size_t i = start; i < end; ++i) mData.at(i) = other(j++);
    }

    T &operator()(int i)
    {
        return mData.at(i);
    }

    const T &operator()(int i) const
    {
        return mData.at(i);
    }
};

using ScalarFieldInt   = ScalarField<int>;
using ScalarFieldFloat = ScalarField<float>;
using ScalarFieldDbl   = ScalarField<double>;

}  // namespace Numeric
}  // namespace CommImpl
}  // namespace OpenOasis