/** ***********************************************************************************
 *    Copyright (C) 2023, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  MultiIndexMapper.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Customized unordered_map using multiple indexes as key.
 *
 ** ***********************************************************************************/
#pragma once
#include <unordered_map>
#include <array>


namespace OpenOasis::Utils
{
template <std::size_t N = 2>
class MultiIndex
{
public:
    static_assert(N > 1, "Using std::unordered_map<int, T> instead.");

    MultiIndex() = default;
    MultiIndex(const std::array<int, N> &lst) : indexes(lst)
    {}

    std::array<int, N> indexes;
};


template <std::size_t N = 2>
struct EqualFunc
{
    bool operator()(const MultiIndex<N> &lhs, const MultiIndex<N> &rhs) const
    {
        for (std::size_t i = 0; i < N; ++i)
        {
            if (lhs.indexes[i] != rhs.indexes[i])
                return false;
        }
        return true;
    }
};


template <std::size_t N = 2>
struct HashFunc
{
    std::size_t operator()(const MultiIndex<N> &key) const
    {
        std::size_t res = 0;
        for (std::size_t i = 0; i < N; ++i)
        {
            res += std::hash<int>()(key.indexes[i]) / N;
        }
        return res;
    }
};

template <typename T, std::size_t N = 2>
using MultiIndexMap = std::unordered_map<MultiIndex<N>, T, HashFunc<N>, EqualFunc<N>>;


}  // namespace OpenOasis::Utils