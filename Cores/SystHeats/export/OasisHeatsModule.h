#pragma once

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

EXPORT const char *GetHeatPackageVersion();

/// @brief Get `HeatConduction` object which no external deletion is required.
/// @param id model id.
/// @param taskFile File contains task configurations.
/// @return `HeatConductionModule` object raw pointer.
EXPORT void *GetHeatConductionModule(const char *id, const char *taskFile);
