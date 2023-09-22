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
/// @brief Description and manipulation of 2D or 3D vector fields.
template <typename T, std::size_t N>
class VectorField
{
private:
    std::vector<Vector<T, N>> mData;

public:
    virtual ~VectorField() = default;
    VectorField(std::size_t size)
    {
        mData.resize(size, Vector<T, N>());
    }

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

    /// @brief Clean the vector field data to the default value.
    void Clean()
    {
        std::fill(mData.begin(), mData.end(), Vector<T, N>());
    }

    /// @brief Clear the vector field.
    void Clear()
    {
        mData.clear();
    }

    /// @brief Iterates the field and invoke given @p func for each element.
    ///
    /// This function iterates the field elements and invoke
    /// the callback function @p func. The callback function takes field's
    /// element as its input. Below is the sample usage:
    ///
    /// VectorField<float, 2> field(10);
    /// field.ForEach([](Vector<float, 2> elem) {printf("%f\n", elem(0));});
    template <typename Callback>
    void ForEach(Callback func)
    {
        for (auto &elem : mData) { func(elem); }
    }

    std::size_t Size() const
    {
        return mData.size();
    }

    void SetAt(std::size_t i, const Vector<T, N> &value)
    {
        mData.at(i) = value;
    }

    void SetAt(
        std::size_t start, std::size_t end, const VectorField &other,
        std::size_t offset = 0)
    {
        std::size_t j = offset;
        for (std::size_t i = start; i < end; ++i) mData.at(i) = other(j++);
    }

    Vector<T, N> &operator()(std::size_t i)
    {
        return mData.at(i);
    }

    const Vector<T, N> &operator()(std::size_t i) const
    {
        return mData.at(i);
    }
};

}  // namespace Numeric
}  // namespace CommImpl
}  // namespace OpenOasis