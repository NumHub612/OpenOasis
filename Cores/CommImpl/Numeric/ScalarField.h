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

    virtual ~ScalarField() = default;
    ScalarField(std::size_t size)
    {
        mData.resize(size, T(0));
    }

    ///////////////////////////////////////////////////////////////////////////////////
    // Methods for the scalar data operation.
    //

    /// @brief Initialize the scalar field with a value.
    /// @param value The initial value.
    void Initialize(T value)
    {
        std::fill(data.begin(), data.end(), value);
    }

    /// @brief Resize the scalar field.
    /// @param size The new size.
    void Resize(std::size_t size)
    {
        mData.resize(size);
        mData.shrink_to_fit();
    }

    /// @brief Clean the scalar field data to the default value.
    void Clean()
    {
        std::fill(data.begin(), data.end(), T(0));
    }

    /// @brief Clear the scalar field.
    void Clear()
    {
        mData.clear();
    }

    T &operator()(int i)
    {
        return mData.at(i);
    }

    ///////////////////////////////////////////////////////////////////////////////////
    // Methods for the scalar field operation.
    //

    /// @brief Return gradient vector at given position.
    virtual Vector<T, N> Gradient(std::size_t i) const
    {
        throw std::exception("Not implemented");
    }

private:
    std::vector<T> mData;
};

using ScalarFieldI = ScalarField<int>;
using ScalarFieldF = ScalarField<float>;
using ScalarFieldD = ScalarField<double>;

}  // namespace Numeric
}  // namespace CommImpl
}  // namespace OpenOasis