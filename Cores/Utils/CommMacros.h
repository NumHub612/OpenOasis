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


// define WINDOWS.
#undef WINDOWS
#ifdef _WIN32
#define WINDOWS
#endif

// define LINUX.
#undef LINUX
#ifdef __linux__
#define LINUX
#endif

// include platform headers.
#ifdef WINDOWS
#include <windows.h>
#else
#include <dlfcn.h>
#include <stdexcept>
#endif
