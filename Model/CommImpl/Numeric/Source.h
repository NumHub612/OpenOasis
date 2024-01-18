/** ***********************************************************************************
 *    Copyright (C) 2023, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  Source.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Abstract Source class for definition of source vector.
 *
 ** ***********************************************************************************/
#pragma once
#include <vector>

namespace OpenOasis::CommImpl::Numeric
{
class Source
{
public:
    virtual std::vector<double> GetSource() = 0;
};
}  // namespace OpenOasis::CommImpl::Numeric