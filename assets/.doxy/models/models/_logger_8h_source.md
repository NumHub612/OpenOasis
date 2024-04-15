

# File Logger.h

[**File List**](files.md) **>** [**CommImp**](dir_6202b98a8704f42b1ea358646461643f.md) **>** [**IO**](dir_3b1940e7bde9c1f91eabae8dc723b4f2.md) **>** [**Logger.h**](_logger_8h.md)

[Go to the documentation of this file](_logger_8h.md)


```C++

#pragma once
#include "ThirdPart/spdlog/spdlog.h"
#include "ThirdPart/spdlog/sinks/rotating_file_sink.h"


namespace OpenOasis
{
namespace CommImp
{
namespace IO
{
std::shared_ptr<spdlog::logger> GetLogger(const std::string &loggerId = "OasisLog");

}  // namespace IO
}  // namespace CommImp
}  // namespace OpenOasis
```


