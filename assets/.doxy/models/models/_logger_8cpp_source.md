

# File Logger.cpp

[**File List**](files.md) **>** [**CommImp**](dir_6202b98a8704f42b1ea358646461643f.md) **>** [**IO**](dir_3b1940e7bde9c1f91eabae8dc723b4f2.md) **>** [**Logger.cpp**](_logger_8cpp.md)

[Go to the documentation of this file](_logger_8cpp.md)


```C++

#include "Logger.h"
#include <unordered_map>
#include <mutex>


namespace OpenOasis::CommImp::IO
{
using namespace std;

static const string DEFAULT_LOGGER_ID = "OasisLog";

static int DEFAULT_LOGGER_SIZE = 1024 * 1024 * 5;
static int DEFAULT_FILE_NUM    = 9;

static unordered_map<string, shared_ptr<spdlog::logger>> OasisLoggers = {
    {DEFAULT_LOGGER_ID,
     spdlog::rotating_logger_mt(
         DEFAULT_LOGGER_ID, DEFAULT_LOGGER_ID, DEFAULT_LOGGER_SIZE, DEFAULT_FILE_NUM)}};

static mutex mtx;

shared_ptr<spdlog::logger> GetLogger(const string &loggerId)
{
    unique_lock<mutex> guard(mtx);

    if (OasisLoggers.find(loggerId) != OasisLoggers.end())
    {
        OasisLoggers[loggerId]->set_level(spdlog::level::warn);
        return OasisLoggers[loggerId];
    }
    else
    {
        auto logger = spdlog::rotating_logger_mt(
            loggerId, loggerId, DEFAULT_LOGGER_SIZE, DEFAULT_FILE_NUM);
        logger->set_level(spdlog::level::warn);

        OasisLoggers.insert(make_pair(loggerId, logger));
        return logger;
    }
}

}  // namespace OpenOasis::CommImp::IO
```


