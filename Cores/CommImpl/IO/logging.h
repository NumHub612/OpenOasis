/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  logging.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Provide logger.
 *
 ** ***********************************************************************************/
#pragma once
#include "Tools/Spdlog/spdlog.h"
#include "Tools/Spdlog/sinks/rotating_file_sink.h"


namespace OpenOasis
{
namespace CommImpl
{
namespace IO
{
/// @brief To get rotating logger with specified id.
std::shared_ptr<spdlog::logger> GetLogger(const std::string &loggerId = "OasisLog");

}  // namespace IO
}  // namespace CommImpl
}  // namespace OpenOasis