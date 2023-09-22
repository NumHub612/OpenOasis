#pragma once
#include "Cores/Utils/CommMacros.h"

EXPORT const char *GetFluidPackageVersion();

/// @brief Get `RainfallModule` object which no external deletion is required.
/// @param id Rainfall model id.
/// @param coorFile File contains coordinates of the rainfall model.
/// @param dataFile File contains rainfall data of the component.
/// @return `RainfallModule` object raw pointer.
EXPORT void *
GetRainfallModule(const char *id, const char *coorFile, const char *dataFile);


/// @brief Get `RunoffModule` object which no external deletion is required.
/// @param id Runoff model id.
/// @param taskFile File contains task settings for the model.
/// @return `RunoffModule` object raw pointer.
EXPORT void *GetRunoffModule(const char *id, const char *taskFile);


/// @brief Get `RiverModule` object which no external deletion is required.
/// @param id River model id.
/// @return `RiverModule` object raw pointer.
EXPORT void *GetRiverModule(const char *id);