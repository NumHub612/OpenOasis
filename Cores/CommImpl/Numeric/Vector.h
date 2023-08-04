/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  Vector.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Define Vector template class for numerical calculation.
 *
 ** ***********************************************************************************/
#pragma once
#include <array>


namespace OpenOasis
{
namespace CommImpl
{
namespace Numeric
{
template <typename T, std::size_t N>
class Vector
{
public:
    static_assert(N > 0, "Size of static-sized vector should be greater than zero.");
    static_assert(
        std::is_arithmetic<T>::value,
        "Vector only can be instantiated with arithmetic types");

    virtual ~Vector() = default;

    Vector()
    {
        mElement.fill(static_cast<T>(0));
    }

    Vector(const Vector &other)
    {
        mElement = other.mElement;
    }

    template <typename... Args>
    Vector(Args... args)
    {
        static_assert(sizeof...(args) == N, "Invalid number of parameters.");

        SetAt(0, args...);
    }

    template <typename U>
    Vector(const std::initializer_list<U> &lst)
    {
        Set(lst);
    }

    ///////////////////////////////////////////////////////////////////////////////////
    // Methods for vector data operation.
    //

    void Set(const Vector &other)
    {
        for (std::size_t i = 0; i < N; ++i)
        {
            mElement[i] = other[i];
        }
    }

    template <typename... Args>
    void SetAt(std::size_t i, T v, Args... args)
    {
        mElement.at(i) = v;

        SetAt(i + 1, args...);
    }

    void SetAt(size_t i, T v)
    {
        mElement.at(i) = v;
    }

    template <typename U>
    void Set(const std::initializer_list<U> &lst)
    {
        static_assert(lst.size() >= N);

        for (std::size_t i = 0; i < N; ++i)
        {
            mElement[i] = static_cast<T>(lst[i]);
        }
    }

    constexpr std::size_t Size() const
    {
        return N;
    }

    T &operator[](std::size_t i)
    {
        return mElement.at(i);
    }

    ///////////////////////////////////////////////////////////////////////////////////
    // Methods for vector calculation.
    //

private:
    std::array<T, N> mElement;
};

}  // namespace Numeric
}  // namespace CommImpl
}  // namespace OpenOasis