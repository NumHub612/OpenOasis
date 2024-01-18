/** ***********************************************************************************
 *    @File      :  StreamReader.cpp
 *    @Brief     :  To provide file stream reading and writing operations.
 *
 ** ***********************************************************************************/
#include "StreamReader.h"
#include <string>

using namespace OpenOasis::Utils;
using namespace std;


// class StreamReader -----------------------------------------------------------

fstream &StreamReader::Init(const string &file, ios::openmode mode)
{
    //=======================================================================
    // Notice that different openmode has different writing behavior. Such as,
    // if using `ios::in | ios:app`, then you would write to the end of file,
    // `seekLine()` would not help you repostion the put-pointer;
    // if using `ios::in | ios:out`, then `seekLine()` would worked.
    //=======================================================================

    mReader = fstream(file, mode);
    return mReader;
}

void StreamReader::Reset()
{
    //=======================================================================
    // Notice that get-pointer and put-pointer located at `ios::beg` while
    // fstream created with mode of `ios::in | ios:app` or `ios::in | ios:out`.
    //
    // Notice that get-pointer and put-pointer would change in sync while
    // using `seekg()` or `seekp()`.
    //=======================================================================

    if (mReader.is_open())
    {
        mReader.clear();
        mReader.seekg(0L, ios::beg);  // set get-pointer to the begin of file.
    }
}

void StreamReader::Close()
{
    if (mReader.is_open())
    {
        mReader.clear();  // clear file stream status.
        mReader.close();  // release buffer and close file.
    }
}

long StreamReader::CountBytes()
{
    if (mReader.is_open())
    {
        streampos pos = mReader.tellg();  // save get-pointer's current position.

        mReader.seekg(0L, ios::end);  // couldnt use `seekg(ios::end)`.
        long size = mReader.tellg();

        mReader.clear();
        mReader.seekg(pos);  // reset get-pointer to origin position.
        return size;
    }
    else
    {
        return -1;  // negative value means error(similarly hereinafter).
    }
}

long StreamReader::CountLines()
{
    if (mReader.is_open())
    {
        streampos pos   = mReader.tellg();
        long      lines = 0;
        string    temp;

        mReader.seekg(0L, ios::beg);
        while (getline(mReader, temp))
        {
            lines++;
        }
        mReader.clear();
        mReader.seekg(pos);

        return lines;  // line number counted from 1(similarly hereinafter).
    }
    else
    {
        return -1;
    }
}

long StreamReader::TellLine()
{
    if (mReader.is_open())
    {
        streampos pos      = mReader.tellg();
        long      currLine = 0;
        string    line;

        mReader.seekg(0L, ios::beg);
        while (getline(mReader, line))  // move get-pointer to next line head.
        {
            currLine++;
            if (mReader.tellg() >= pos)
            {
                break;
            }
        }
        mReader.clear();
        mReader.seekg(pos);

        return currLine;
    }
    else
    {
        return -1;
    }
}

bool StreamReader::SeekLine(long lineInd, long offset)
{
    if (mReader.is_open())
    {
        long   currLine = 0;
        string line;

        // check if it's the first line.
        mReader.seekg(0L, ios::beg);
        if (currLine == lineInd - 1)
        {
            return true;
        }

        // move get-pointer to the begin of given line(the end of last line).
        while (getline(mReader, line) && (++currLine < lineInd - 1)) {}
        if (currLine == lineInd - 1)
        {
            if (mReader.seekg(offset, ios::cur))
            {
                return true;
            }
        }
    }

    return false;
}

bool StreamReader::SkipLine(long lineNum)
{
    if (mReader.is_open())
    {
        string line;
        while (getline(mReader, line) && (--lineNum)) {}
        if (lineNum == 0)
        {
            return true;
        }
    }
    return false;
}

bool StreamReader::BackLine(long lineLen)
{
    if (mReader.is_open())
    {
        if (mReader.seekg(-lineLen, ios::cur))
        {
            return true;
        }
    }

    return false;
}

bool StreamReader::IsEnd()
{
    if (mReader.is_open())
    {
        if (mReader.eof())
        {
            return true;
        }
    }

    return false;
}

bool StreamReader::GetLine(string &line)
{
    //=======================================================================
    // Notice that `getline()` would remove `\r\n` automatically.
    //=======================================================================

    line.clear();  // clear origin string.

    if (mReader.is_open())
    {
        if (getline(mReader, line))
        {
            return true;
        }
    }

    return false;
}

bool StreamReader::GetLine(string &line, long lineNum)
{
    line.clear();

    mReader.seekg(0L, ios::beg);
    long   currLine = 0;
    string temp;

    while (getline(mReader, temp) && (++currLine < lineNum)) {}
    if (currLine == lineNum)
    {
        line = temp;
        return true;
    }
    else
    {
        return false;
    }
}

bool StreamReader::PutLine(const string &line)
{
    if (mReader.is_open())
    {
        mReader << line;
        mReader << "\n";
        mReader.flush();  // flush buffer.
        if (mReader.good())
        {
            return true;
        }
    }

    return false;
}

bool StreamReader::GetBinaryStr(string &str)
{
    //=======================================================================
    // Notice that it's odd that `read()` would have different behavior in
    // win7-x86-SDK and win10-SDK.
    //
    // Notice that it's necessary to determine a binary string input format,
    // such as `size+string` in general.
    //=======================================================================

    str.clear();  // clear origin string.

    if (mReader.is_open() && mReader.peek() != EOF)
    {
        size_t size;
        mReader >> size;  // get string size(convention format, size+string).

        str.resize(size);  // resize string size to fit reading characters.
        mReader.read(&str[0], size);

        if (mReader.good())
        {
            return true;
        }
    }

    return false;
}

bool StreamReader::PutBinaryStr(const string &str)
{
    if (mReader.is_open())
    {
        mReader << str.size();  // write string size first.
        mReader << str;         // write string in binary after.
        if (mReader.good())
        {
            return true;
        }
    }

    return false;
}
