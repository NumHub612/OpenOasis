/** ***********************************************************************************
 *    @File      :  logging.cpp
 *    @Brief     :  Provide logger.
 *
 ** ***********************************************************************************/
#include "logging.h"
#include <unordered_map>
#include <mutex>


namespace OpenOasis::CommImpl::IO
{
using namespace std;

static unordered_map<string, shared_ptr<spdlog::logger>> OasisLoggers = {
    {"OasisLog",
     spdlog::rotating_logger_mt("OasisLog", "OasisLog", 1024 * 1024 * 5, 9)}};

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
        auto logger =
            spdlog::rotating_logger_mt(loggerId, loggerId, 1024 * 1024 * 5, 9);
        logger->set_level(spdlog::level::warn);

        OasisLoggers.insert(make_pair(loggerId, logger));
        return logger;
    }
}

}  // namespace OpenOasis::CommImpl::IO