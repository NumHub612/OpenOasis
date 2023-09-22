#pragma once
#include "Cores/Utils/CommMacros.h"

EXPORT const char *GetHeatPackageVersion();

/// @brief Get `HeatConduction` object which no external deletion is required.
/// @param id model id.
/// @param taskFile File contains task configurations.
/// @return `HeatConductionModule` object raw pointer.
EXPORT void *GetHeatConductionModule(const char *id, const char *taskFile);
