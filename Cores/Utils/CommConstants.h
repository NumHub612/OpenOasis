/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  CommConstants.hpp
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  To provide common constants.
 *
 ** ***********************************************************************************/
#pragma once
#include <limits>
#include <cmath>


// commonly used constants ------------------------------------------------------------

const int          _INT_MAX       = (std::numeric_limits<int>::max)();
const unsigned int _UINT_MAX      = (std::numeric_limits<unsigned int>::max)();
const double       _DBL_MAX       = (std::numeric_limits<double>::max)();
const double       _DBL_EPSILON   = (std::numeric_limits<double>::epsilon)();
const float        _FLOAT_MAX     = (std::numeric_limits<float>::max)();
const float        _FLOAT_EPSILON = (std::numeric_limits<float>::epsilon)();

#define IsEqual(a, b) (abs(a - b) <= _DBL_EPSILON)
#define IsBigger(a, b) (a - b > _DBL_EPSILON)
#define IsNoLessThan(a, b) (a - b >= _DBL_EPSILON)


// single and double precision switches -----------------------------------------------

#ifdef USE_SP
typedef float real;
const real    FP_EPSILON = _FLOAT_EPSILON;
const real    FP_MAX     = _FLOAT_MAX;
#else
typedef double real;
const real     FP_EPSILON = _DBL_EPSILON;
const real     FP_MAX     = _DBL_MAX;
#endif

#define IsRealEqual(a, b) (abs(a - b) <= FP_EPSILON)
#define IsRealBigger(a, b) (a - b > FP_EPSILON)
