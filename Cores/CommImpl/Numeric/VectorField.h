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
#include "TensroField.h"
#include "ScalarField.h"
#include "Vector.h"
#include <vector>
#include <array>
#include <algorithm>


namespace OpenOasis
{
namespace CommImpl
{
namespace Numeric
{
/// @brief Description and manipulation of 2D or 3D vector data.
template <typename T, std::size_t N>
class VectorField
{
public:
    virtual ~VectorField() = default;
    VectorField(std::size_t size)
    {
        mData.resize(size, Vector<T, N>());
    }

    ///////////////////////////////////////////////////////////////////////////////////
    // Methods for the vector data operation.
    //

    /// @brief Initialize the vector field with specified value.
    /// @param value The initial value.
    void Initialize(const Vector<T, N> &value)
    {
        std::fill(mData.begin(), mData.end(), value);
    }

    /// @brief Resize the vector field.
    /// @param size The new size.
    void Resize(std::size_t size)
    {
        mData.resize(size);
        mData.shrink_to_fit();
    }

    /// @brief Clean the vector field data to default value.
    void Clean()
    {
        std::fill(mData.begin(), mData.end(), Vector<T, N>());
    }

    /// @brief Clear the vector field.
    void Clear()
    {
        mData.clear();
    }

    Vector<T, N> &operator()(int i)
    {
        return mData.at(i);
    }

    ///////////////////////////////////////////////////////////////////////////////////
    // Methods for the vector field operation.
    //

private:
    std::vector<Vector<T, N>> mData;
};

}  // namespace Numeric
}  // namespace CommImpl
}  // namespace OpenOasis