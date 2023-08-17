/** ***********************************************************************************
 *    @File      :  YamlHandler.cpp
 *    @Brief     :  To provide unified json file read and write function.
 *
 ** ***********************************************************************************/
#include "YamlHandler.h"
#include "FilePathHelper.h"
#include "StringHelper.h"


namespace OpenOasis::Utils
{
using namespace std;


// ------------------------------------------------------------------------------------

YamlLoader::YamlLoader(const string &filePath)
{
    if (!FilePathHelper::FileExists(filePath))
    {
        throw invalid_argument(
            StringHelper::FormatSimple("File {} does not exist. ", filePath));
    }

    mYaml = ryml::parse_in_arena(ryml::to_csubstr(GetFileContents(filePath)));
}

string YamlLoader::GetFileContents(const string &filename)
{
    string cc;
    FILE  *fp = fopen(filename.c_str(), "rb");
    fseek(fp, 0, SEEK_END);

    long sz = ftell(fp);
    cc.resize(static_cast<string::size_type>(sz));
    if (sz)
    {
        rewind(fp);
        fread(&(cc)[0], 1, cc.size(), fp);
    }
    fclose(fp);

    return cc;
}

vector<string> YamlLoader::GetKeys(const vector<string> &levels) const
{
    ryml::ConstNodeRef node = mYaml.crootref();
    for (const auto &k : levels)
    {
        ryml::csubstr key{k.c_str(), k.size()};
        if (node.has_child(key))
        {
            node = node[key];
        }
        else
        {
            return {};
        }
    }

    vector<string> keys;
    for (ryml::ConstNodeRef n : node.children())
    {
        auto &key = n.key();
        keys.push_back(string(key.str, key.len));
    }

    return keys;
}


// ------------------------------------------------------------------------------------

}  // namespace OpenOasis::Utils
