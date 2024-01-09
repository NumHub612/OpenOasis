/** ***********************************************************************************
 *    @File      :  JsonHandler.cpp
 *    @Brief     :  To provide unified json file read and write function.
 *
 ** ***********************************************************************************/
#include "JsonHandler.h"
#include "FilePathHelper.h"
#include "StringHelper.h"
#include <fstream>


namespace OpenOasis::Utils
{
using namespace std;


// ------------------------------------------------------------------------------------

JsonLoader::JsonLoader(const string &filePath)
{
    LoadByFile(filePath);
}

void JsonLoader::LoadByFile(const string &filePath)
{
    if (!FilePathHelper::FileExists(filePath))
    {
        throw invalid_argument(
            StringHelper::FormatSimple("File [{}] does not exist.", filePath));
    }

    mJson = nlohmann::json::parse(ifstream(filePath));
}

void JsonLoader::LoadByContent(const string &content)
{
    mJson = nlohmann::json::parse(content);
}

vector<string> JsonLoader::GetKeys(const vector<string> &levels) const
{
    nlohmann::json json = mJson;
    for (const auto &node : levels)
    {
        json = (json.contains(node)) ? json[node] : nlohmann::json();
    }

    vector<string> keys;
    for (const auto &it : json.items())
    {
        if (it.key() != "") keys.push_back(it.key());
    }

    return keys;
}

bool JsonLoader::IsNull(const vector<string> &levels, const string &key) const
{
    nlohmann::json json = mJson;
    for (const auto &node : levels)
    {
        json = (json.contains(node)) ? json[node] : nlohmann::json();
    }

    if (json.contains(key)) { return json[key].is_null(); }
    else { return true; }
}

int JsonLoader::GetArraySize(const vector<string> &levels) const
{
    nlohmann::json json = mJson;
    for (const auto &node : levels)
    {
        if (json.contains(node)) { json = json[node]; }
        else { return 0; }
    }

    if (json.is_array()) { return json.size(); }
    else { return 0; }
}

unordered_map<string, string> JsonLoader::GetMap(const vector<string> &levels) const
{
    nlohmann::json json = mJson;
    for (const auto &node : levels)
    {
        if (json.contains(node)) { json = json[node]; }
        else { return {}; }
    }

    unordered_map<string, string> map;
    for (const auto &it : json.items())
    {
        map.insert(make_pair(it.key(), it.value()));
    }

    return map;
}

// ------------------------------------------------------------------------------------

unsigned int JsonWriter::sTmpFileCount = 0;

JsonWriter::JsonWriter(const string &filePath)
{
    if (!FilePathHelper::FileExists(filePath))
    {
        try
        {
            if (FilePathHelper::DirectoryExists(filePath))
            {
                const auto &newFilePath = FilePathHelper::Combine(
                    filePath,
                    StringHelper::FormatSimple("Oasis_temp_{}.json", sTmpFileCount++));

                FilePathHelper::MakeFile(newFilePath);
                mFilePath = newFilePath;
            }
        }
        catch (...)
        {
            throw invalid_argument(StringHelper::FormatSimple(
                "File or directory [{}] does not exist.", filePath));
        }
    }
}

string JsonWriter::GetOutputFilePath() const
{
    return mFilePath;
}

void JsonWriter::Save()
{
    ofstream fout(mFilePath);
    fout << setw(4) << mJson << endl;
}

}  // namespace OpenOasis::Utils
