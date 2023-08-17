/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  JsonHandler.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  To provide unified json file read and write function.
 *
 ** ***********************************************************************************/
#pragma once
#include "Tools/Json/json.hpp"
#include <optional>


namespace OpenOasis
{
namespace Utils
{
/// @brief JsonLoader class loads and parses the configurations from a json file.
class JsonLoader
{
private:
    nlohmann::json mJson;

public:
    JsonLoader(const std::string &filePath);

    bool IsNull(const std::vector<std::string> &levels, const std::string &key) const;

    std::vector<std::string> GetKeys(const std::vector<std::string> &levels) const;

    template <typename T>
    std::optional<T>
    GetValue(const std::vector<std::string> &levels, const std::string &key) const
    {
        nlohmann::json json = mJson;
        for (const auto &node : levels)
        {
            json = (json.contains(node)) ? json.at(node) : nlohmann::json();
        }

        if (json.contains(key))
        {
            return json.at(key);
        }
        else
        {
            return std::nullopt;
        }
    }

    template <typename T>
    std::optional<std::vector<T>>
    GetArray(const std::vector<std::string> &levels, const std::string &key) const
    {
        nlohmann::json json = mJson;
        for (const auto &node : levels)
        {
            json = (json.contains(node)) ? json.at(node) : nlohmann::json();
        }

        if (json.contains(key) && json.at(key).is_array())
        {
            vector<T> results;
            for (const auto &val : json.at(key))
                results.push_back(val);
            return results;
        }
        else
        {
            return std::nullopt;
        }
    }
};


/// @brief JsonWriter class writes the configurations to a json file.
class JsonWriter
{
private:
    std::string    mFilePath;
    nlohmann::json mJson;

    static unsigned int sTmpFileCount;

public:
    JsonWriter(const std::string &filePath);

    std::string GetOutputFilePath() const;

    void Save();

    template <typename T>
    void SetValue(
        const std::vector<std::string> &levels, const std::string &key, const T &value)
    {
        nlohmann::json parentJson = {{key, value}};
        for (auto it = levels.rbegin(); it != levels.rend(); ++it)
        {
            parentJson = nlohmann::json{{*it, parentJson}};
        }

        for (const auto &[key, value] : parentJson.items())
        {
            mJson[key] = value;
        }
    }

    template <typename T>
    void SetArray(
        const std::vector<std::string> &levels, const std::string &key,
        const std::vector<T> &values)
    {
        nlohmann::json json;
        json[key] = (values.empty()) ? nlohmann::json::array() : values;

        nlohmann::json parentJson = json;
        for (auto it = levels.rbegin(); it != levels.rend(); ++it)
        {
            parentJson = nlohmann::json{{*it, parentJson}};
        }

        for (const auto &[key, value] : parentJson.items())
        {
            mJson[key] = value;
        }
    }
};


}  // namespace Utils
}  // namespace OpenOasis