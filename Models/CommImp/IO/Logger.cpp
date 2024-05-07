/** ***********************************************************************************
 *    @File      :  Logger.cpp
 *    @Brief     :  Provide logger.
 *
 ** ***********************************************************************************/
#include "Logger.h"
#include <unordered_map>
#include <mutex>


namespace OpenOasis::CommImp::IO
{
using namespace std;


int Logger::DEFAULT_LOGGER_SIZE = 1024 * 1024 * 5;
int Logger::DEFAULT_FILE_NUM    = 9;

unordered_map<string, shared_ptr<spdlog::logger>> Logger::mLoggers = {
    {"OasisLogger",
     spdlog::rotating_logger_mt(
         "OasisLogger", "OasisLogger", DEFAULT_LOGGER_SIZE, DEFAULT_FILE_NUM)}};

static mutex mtx;

shared_ptr<spdlog::logger> Logger::GetLogger(const string &loggerId)
{
    unique_lock<mutex> guard(mtx);

    if (mLoggers.find(loggerId) != mLoggers.end())
    {
        mLoggers[loggerId]->set_level(spdlog::level::warn);
        return mLoggers[loggerId];
    }
    else
    {
        auto logger = spdlog::rotating_logger_mt(
            loggerId, loggerId, DEFAULT_LOGGER_SIZE, DEFAULT_FILE_NUM);
        logger->set_level(spdlog::level::warn);

        mLoggers.insert(make_pair(loggerId, logger));
        return logger;
    }
}

}  // namespace OpenOasis::CommImp::IO