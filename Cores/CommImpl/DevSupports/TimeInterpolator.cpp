/** ***********************************************************************************
 *    @File      :  TimeInterpolator.cpp
 *    @Brief     :  Time interpolation adaptor.
 *
 ** ***********************************************************************************/
#include "TimeInterpolator.h"


namespace OpenOasis::CommImpl::DevSupports
{
using namespace std;

const string TimeInterpolator::mTimeInterpolatorId = "TimeInterpolator";

TimeInterpolator::TimeInterpolator() : TimeAdaptor(mTimeInterpolatorId)
{
    mBuffers.SetDoExtrapolate(false);
}

TimeInterpolator::TimeInterpolator(const shared_ptr<IOutput> &adaptee) :
    TimeAdaptor(adaptee->GetId() + "->" + mTimeInterpolatorId, adaptee)
{}

}  // namespace OpenOasis::CommImpl::DevSupports