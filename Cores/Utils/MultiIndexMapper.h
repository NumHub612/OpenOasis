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
/// @brief Wrapper for unordered_map using multi-integer indexes as key.
template <typename T, std::size_t N = 2>
class MultiIndexMapper
{
public:
    static_assert(N > 1, "Using std::unordered_map<int, T> instead.");

    class Index
    {
    public:
        Index(const std::initializer_list<int> &lst) : indexes(lst){};
        Index() = default;

        std::array<int, N> indexes;
    };

    struct EqualFunc
    {
        bool operator()(const Index &lhs, const Index &rhs) const
        {
            for (std::size_t i = 0; i < N; ++i)
            {
                if (lhs.indexes[i] != rhs.indexes[i]) return false;
            }
            return true;
        }
    };

    struct HashFunc
    {
        std::size_t operator()(const Index &key) const
        {
            std::size_t res = 0;
            for (std::size_t i = 0; i < N; ++i)
            {
                res += std::hash<int>()(key.indexes[i]) / N;
            }
            return res;
        }
    };

public:
    using IndexMap = std::unordered_map<Index, T, HashFunc, EqualFunc>;

    static IndexMap GetInstance()
    {
        return IndexMap();
    }

private:
    MultiIndexMap(const MultiIndexMap &other) = delete;
    MultiIndexMap()                           = delete;
};

}  // namespace OpenOasis::Utils