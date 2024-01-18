/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  TimeInterpolator.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Time interpolation adaptor.
 *
 ** ***********************************************************************************/
#pragma once
#include "TimeAdaptor.h"


namespace OpenOasis::CommImpl::DevSupports
{
/// @brief Time interpolation adaptor.
class TimeInterpolator : public TimeAdaptor
{
private:
    static const std::string mTimeInterpolatorId;

public:
    virtual ~TimeInterpolator()
    {}

    TimeInterpolator();
    TimeInterpolator(const std::shared_ptr<IOutput> &adaptee);
};

}  // namespace OpenOasis::CommImpl::DevSupports