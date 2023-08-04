/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  Tensor.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Define Tensor template class for numerical calculation.
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
class Tensor
{
public:
    static_assert(N > 0, "Size of static-sized tensor should be greater than zero.");
    static_assert(
        std::is_arithmetic<T>::value,
        "Tensor only can be instantiated with arithmetic types");

    Tensor()
    {
        mElement.fill(static_cast<T>(0));
    }

    Tensor(const Tensor &other)
    {
        mElement = other.mElement;
    }

    template <typename... Args>
    Tensor(Args... args)
    {
        static_assert(sizeof...(args) == N * N, "Invalid number of parameters.");

        SetAt(0, args...);
    }

    template <typename U>
    Tensor(const std::initializer_list<U> &lst)
    {
        Set(lst);
    }

    ///////////////////////////////////////////////////////////////////////////////////
    // Methods for Tensor data operation.
    //

    void Set(const Tensor &other)
    {
        for (std::size_t i = 0; i < N; ++i)
        {
            for (std::size_t j = 0; j < N; ++j)
            {
                std::size_t idx = i * N + j;
                mElement[idx]   = other[idx];
            }
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
        static_assert(lst.size() >= N * N);

        for (std::size_t i = 0; i < N * N; ++i)
        {
            mElement[i] = static_cast<T>(lst[i]);
        }
    }

    constexpr std::size_t size() const
    {
        return N;
    }

    T &operator[](std::size_t i, std::size_t j)
    {
        return mElement.at(i * N + j);
    }

    ///////////////////////////////////////////////////////////////////////////////////
    // Methods for Tensor calculation.
    //

private:
    std::array<T, N * N> mElement;
};

}  // namespace Numeric
}  // namespace CommImpl
}  // namespace OpenOasis