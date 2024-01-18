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
#include "ThirdPart/Json/json.hpp"
#include <optional>
#include <vector>


namespace OpenOasis
{
namespace Utils
{
/// @brief JsonLoader class loads and parses the configurations from a json file.
/// @note  JsonLoader reads the configurations with type.
class JsonLoader
{
private:
    nlohmann::json mJson;

public:
    JsonLoader(){};
    JsonLoader(const std::string &file);

    void LoadByContent(const std::string &content);
    void LoadByFile(const std::string &file);

    bool IsNull(const std::vector<std::string> &levels, const std::string &key) const;

    std::vector<std::string> GetKeys(const std::vector<std::string> &levels) const;

    template <typename T>
    std::optional<T>
    GetValue(const std::vector<std::string> &levels, const std::string &key) const
    {
        nlohmann::json json = mJson;
        for (const auto &node : levels)
        {
            if (json.contains(node)) { json = json.at(node); }
            else { return std::nullopt; }
        }

        if (json.contains(key)) { return json.at(key); }
        else { return std::nullopt; }
    }

    template <typename T>
    std::optional<T> GetValue(
        const std::vector<std::string> &levels, unsigned int index,
        const std::string &key) const
    {
        nlohmann::json json = mJson;
        for (const auto &node : levels)
        {
            if (json.contains(node)) { json = json.at(node); }
            else { return std::nullopt; }
        }

        if (json.is_array() && json.size() > index)
        {
            json = json[index];

            if (json.contains(key)) { return json.at(key); }
            else { return std::nullopt; }
        }
        else { return std::nullopt; }
    }

    int GetArraySize(const std::vector<std::string> &levels) const;

    std::unordered_map<std::string, std::string>
    GetMap(const std::vector<std::string> &levels) const;

    template <typename T>
    std::optional<std::vector<T>>
    GetArray(const std::vector<std::string> &levels, const std::string &key) const
    {
        nlohmann::json json = mJson;
        for (const auto &node : levels)
        {
            if (json.contains(node)) { json = json.at(node); }
            else { return std::nullopt; }
        }

        if (json.contains(key) && json.at(key).is_array())
        {
            std::vector<T> results;
            for (const auto &val : json.at(key)) results.push_back(val);

            return results;
        }
        else { return std::nullopt; }
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

        for (const auto &[key, value] : parentJson.items()) { mJson[key] = value; }
    }

    template <typename T>
    void SetArray(
        const std::vector<std::string> &levels, const std::string &key,
        const std::vector<T> &values)
    {
        nlohmann::json json;
        if (values.empty())
            json[key] = nlohmann::json::array();
        else
            json[key] = values;

        nlohmann::json parentJson = json;
        for (auto it = levels.rbegin(); it != levels.rend(); ++it)
        {
            parentJson = nlohmann::json{{*it, parentJson}};
        }

        for (const auto &[key, value] : parentJson.items()) { mJson[key] = value; }
    }
};


}  // namespace Utils
}  // namespace OpenOasis