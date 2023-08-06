/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  CommMacros.hpp
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  To provide some commonly used marcos.
 *
 ** ***********************************************************************************/
#pragma once


// Define WINDOWS.
#undef WINDOWS
#ifdef _WIN32
#define WINDOWS
#endif

// Define LINUX.
#undef LINUX
#ifdef __linux__
#define LINUX
#endif

// Include platform headers.
#ifdef WINDOWS
#include <windows.h>
#else
#include <dlfcn.h>
#include <stdexcept>
#endif

// Define OO_ASSERT.
#if defined(DEBUG) || defined(_DEBUG)
#define OO_DEBUG_MODE
#include <cassert>
#define OO_ASSERT(x) assert(x)
#else
#define OO_ASSERT(x)
#endif