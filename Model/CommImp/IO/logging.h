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
#include "ThirdPart/spdlog/spdlog.h"
#include "ThirdPart/spdlog/sinks/rotating_file_sink.h"


namespace OpenOasis
{
namespace CommImp
{
namespace IO
{
/// @brief To get rotating logger with specified id.
std::shared_ptr<spdlog::logger> GetLogger(const std::string &loggerId = "OasisLog");

}  // namespace IO
}  // namespace CommImp
}  // namespace OpenOasis
