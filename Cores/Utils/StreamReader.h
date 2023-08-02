/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  StreamReader.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  To provide file stream reading and writing operations.
 *
 ** ***********************************************************************************/
#pragma once
#include <fstream>


namespace OpenOasis
{
namespace Utils
{
/// @brief File reading and writing handler with std::fstream.
///
/// @note
/// Notice that negative return value means error or failure.
/// Notice that the line number in IO is counted from 1.
/// Notice that the position of get-pointer and put-pointer change in sync.
/// Notice that pure english path name.
class StreamReader
{
private:
    std::fstream mReader;

public:
    /////////////////////////////////////////////////////////////////////////////
    // Static Methods for file status manipulation.
    //

    std::fstream &Init(
        const std::string &file,
        std::ios::openmode mode = std::ios::in | std::ios::out);

    void Reset();

    void Close();

    long CountBytes();

    long CountLines();

    /////////////////////////////////////////////////////////////////////////////
    // Methods for file reading and writing manipulation.
    //
    // "lineInd", means index of the line in file, counted from 1.
    // "lineNum", means number of lines.
    // "lineLen", means length of the lines wanted to return.

    bool GetLine(std::string &line);

    bool GetLine(std::string &line, long lineIdx);

    bool PutLine(const std::string &line, long lineIdx);

    bool PutLine(const std::string &line);

    long TellLine();

    bool SeekLine(long lineIdx, long offset = 0);

    bool SkipLine(long lineNum);

    bool BackLine(long lineLen);

    bool IsEnd();

    /////////////////////////////////////////////////////////////////////////////
    // Methods for file binary manipulation.
    //
    // Notice that convention format(`size+string`) is used in binary string IO.

    bool GetBinaryStr(std::string &str);

    bool PutBinaryStr(const std::string &str);
};

}  // namespace Utils
}  // namespace OpenOasis