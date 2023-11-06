/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  TimeExterpolator.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Time extrapolation adaptor.
 *
 ** ***********************************************************************************/
#pragma once
#include "TimeAdaptor.h"


namespace OpenOasis::CommImpl::DevSupports
{
/// @brief Time extrapolation adaptor.
class TimeExtrapolator : public TimeAdaptor
{
private:
    static const std::string mTimeExtrapolatorId;

public:
    virtual ~TimeExtrapolator()
    {}

    TimeExtrapolator();
    TimeExtrapolator(const std::shared_ptr<IOutput> &adaptee);
};

}  