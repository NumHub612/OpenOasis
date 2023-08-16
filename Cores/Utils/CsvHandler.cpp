/** ***********************************************************************************
 *    @File      :  CsvHandler.cpp
 *    @Brief     :  To provide unified csv file read and write function.
 *
 ** ***********************************************************************************/
#include "CsvHandler.h"
#include "FilePathHelper.h"
#include "StringHelper.h"


namespace OpenOasis::Utils
{
using namespace std;


// ------------------------------------------------------------------------------------

CsvLoader::CsvLoader(
    const string &filePath, bool hasColumnHeader, bool hasRowHeader, char delimiter)
{
    if (!FilePathHelper::FileExists(filePath))
    {
        throw invalid_argument(
            StringHelper::FormatSimple("File {} does not exist.", filePath));
    }
    mHasColumnHeader = hasColumnHeader;
    mHasRowHeader    = hasRowHeader;

    int colHeaderIdx = (hasColumnHeader) ? 0 : -1;
    int rowHeaderIdx = (hasRowHeader) ? 0 : -1;

    mCsv = rapidcsv::Document(
        filePath,
        rapidcsv::LabelParams(colHeaderIdx, rowHeaderIdx),
        rapidcsv::SeparatorParams(delimiter));
}

optional<vector<string>> CsvLoader::GetColumnLabels() const
{
    if (mHasColumnHeader)
        return mCsv.GetColumnNames();
    else
        return nullopt;
}

optional<vector<string>> CsvLoader::GetRowLabels() const
{
    if (mHasRowHeader)
        return mCsv.GetRowNames();
    else
        return nullopt;
}

int CsvLoader::GetColumnCount() const
{
    return mCsv.GetColumnCount();
}

int CsvLoader::GetRowCount() const
{
    return mCsv.GetRowCount();
}

optional<vector<DateTime>> CsvLoader::GetColumnAsDateTime(const string &label) const
{
    try
    {
        const auto &values = mCsv.GetColumn<string>(label);

        vector<DateTime> results(values.size());
        transform(begin(values), end(values), begin(results), [](const auto &val) {
            return DateTime::FromString(val);
        });

        return results;
    }
    catch (...)
    {
        return nullopt;
    }
}

optional<vector<DateTime>> CsvLoader::GetColumnAsDateTime(int idx) const
{
    try
    {
        const auto &values = mCsv.GetColumn<string>(idx);

        vector<DateTime> results(values.size());
        transform(begin(values), end(values), begin(results), [](const auto &val) {
            return DateTime::FromString(val);
        });

        return results;
    }
    catch (...)
    {
        return nullopt;
    }
}


// ------------------------------------------------------------------------------------

unsigned int CsvWriter::sTmpFileCount = 0;

CsvWriter::CsvWriter(const string &filePath, char delimiter)
{
    if (!FilePathHelper::FileExists(filePath))
    {
        try
        {
            if (FilePathHelper::DirectoryExists(filePath))
            {
                const auto &newFilePath = FilePathHelper::Combine(
                    filePath,
                    StringHelper::FormatSimple("Oasis_temp_{}.csv", sTmpFileCount++));

                FilePathHelper::MakeFile(newFilePath);
                mFilePath = newFilePath;
            }
        }
        catch (...)
        {
            throw invalid_argument(StringHelper::FormatSimple(
                "File or directory {} does not exist.", filePath));
        }
    }

    mCsv = rapidcsv::Document(
        mFilePath, rapidcsv::LabelParams(0, 0), rapidcsv::SeparatorParams(delimiter));
}

void CsvWriter::Save()
{
    mCsv.Save(mFilePath);
}

string CsvWriter::GetOutputFilePath() const
{
    return mFilePath;
}

void CsvWriter::SetColumnLabel(int idx, const string &label)
{
    mCsv.SetColumnName(idx, label);
}

void CsvWriter::SetRowLabel(int idx, const string &label)
{
    mCsv.SetRowName(idx, label);
}


}  // namespace OpenOasis::Utils