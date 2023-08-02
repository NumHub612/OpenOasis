#pragma once

// Define dll export macro.
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
