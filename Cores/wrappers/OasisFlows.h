#pragma once

// Macros of platform.
#undef WINDOWS
#ifdef _WIN32
#define WINDOWS
#endif

#undef LINUX
#ifdef __linux__
#define LINUX
#endif

#ifdef WINDOWS
#include <windows.h>
#else
#include <dlfcn.h>
#include <stdexcept>
#endif

#ifdef __cplusplus
#ifndef EXTERNC
#define EXTERNC extern "C"
#endif
#else
#define EXTERNC
#endif

#ifdef WINDOWS
#ifndef EXPORT
#define EXPORT EXTERNC __declspec(dllexport)
#endif
#else
#define EXPORT EXTERNC
#endif

// ------------------------------------------------------------------------------
// Exports of fluid components.
// ------------------------------------------------------------------------------

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


// ------------------------------------------------------------------------------
// Exports of heat components.
// ------------------------------------------------------------------------------

/// @brief Get `HeatConduction` object which no external deletion is required.
/// @param id model id.
/// @param taskFile File contains task configurations.
/// @return `HeatConductionModule` object raw pointer.
EXPORT void *GetHeatConductionModule(const char *id, const char *taskFile);