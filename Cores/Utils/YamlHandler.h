/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  YamlHandler.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  To provide unified json file read and write function.
 *
 ** ***********************************************************************************/
#pragma once
#include "Tools/RapidYaml/rapidyaml.hpp"
#include <optional>


namespace OpenOasis
{
namespace Utils
{
/// @brief YamlLoader class loads and parses the configurations from a yaml file.
/// @todo Not support `double` value.
class YamlLoader
{
private:
    ryml::Tree mYaml;

public:
    YamlLoader(const std::string &filePath);

    std::vector<std::string> GetKeys(const std::vector<std::string> &levels) const;

    bool HasKeys(
        const std::vector<std::string> &levels,
        const std::vector<std::string> &keys) const;

    template <typename T>
    std::optional<T>
    GetValue(const std::vector<std::string> &levels, const std::string &key) const
    {
        ryml::ConstNodeRef node = mYaml.rootref();
        for (const auto &level : levels)
        {
            ryml::csubstr k{level.c_str(), level.size()};
            if (node.has_child(k))
                node = node[k];
            else
                return std::nullopt;
        }

        ryml::csubstr k{key.c_str(), key.size()};
        if (node.is_map() && node.has_child(k))
        {
            T result;
            node[k] >> result;

            return result;
        }
        else { return std::nullopt; }
    }

    template <typename T>
    std::optional<std::vector<T>>
    GetArray(const std::vector<std::string> &levels, const std::string &key) const
    {
        ryml::ConstNodeRef node = mYaml.rootref();
        for (const auto &level : levels)
        {
            ryml::csubstr k{level.c_str(), level.size()};
            if (node.has_child(k)) { node = node[k]; }
            else { return std::nullopt; }
        }

        ryml::csubstr k{key.c_str(), key.size()};
        if (node.is_map() && node.has_child(k) && node[k].is_seq())
        {
            node = node[k];

            std::vector<T> results;
            for (int i = 0; i < node.num_children(); ++i)
            {
                T value;
                node[i] >> value;

                results.push_back(value);
            }

            return results;
        }
        else { return std::nullopt; }
    }

private:
    std::string GetFileContents(const std::string &filename);
};


/// @brief YamlWriter class writes the configurations to a yaml file.
class YamlWriter
{};

}  // namespace Utils
}  // namespace OpenOasis