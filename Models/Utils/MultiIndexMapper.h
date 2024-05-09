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
/// @brief Customized unordered_map using multiple indexes as key.
/// @tparam N The number of indexes.
/// @note Indexes have order, different order means different key.
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
struct MultiEqualFunc
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
struct MultiHashFunc
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
using MultiIndexMap =
    std::unordered_map<MultiIndex<N>, T, MultiHashFunc<N>, MultiEqualFunc<N>>;


/// @brief Customized unordered_map using a tuple of indexes as key.
/// @tparam N The number of indexes.
/// @note Indexes have no order, different orders mean one same key.
template <std::size_t N = 2>
class TupleIndex
{
public:
    static_assert(N > 1, "Using std::unordered_map<int, T> instead.");

    TupleIndex() = default;
    TupleIndex(const std::array<int, N> &lst) : indexes(lst)
    {}

    std::array<int, N> indexes;
};


template <std::size_t N = 2>
struct TupleEqualFunc
{
    bool operator()(const TupleIndex<N> &lhs, const TupleIndex<N> &rhs) const
    {
        for (std::size_t i = 0; i < N; ++i)
        {
            int  l     = lhs.indexes[i];
            bool found = false;
            for (std::size_t j = 0; j < N; ++j)
            {
                if (l == rhs.indexes[j])
                {
                    found = true;
                    break;
                }
            }

            if (!found)
                return false;
        }
        return true;
    }
};


template <std::size_t N = 2>
struct TupleHashFunc
{
    std::size_t operator()(const TupleIndex<N> &key) const
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
using TupleIndexMap =
    std::unordered_map<TupleIndex<N>, T, TupleHashFunc<N>, TupleEqualFunc<N>>;

}  // namespace OpenOasis::Utils