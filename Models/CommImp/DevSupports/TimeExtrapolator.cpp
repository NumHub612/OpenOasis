/** ***********************************************************************************
 *    @File      :  TimeExtrapolator.cpp
 *    @Brief     :  None.
 *
 ** ***********************************************************************************/
#include "TimeExtrapolator.h"


namespace OpenOasis::CommImp::DevSupports
{
using namespace std;

const string TimeExtrapolator::mTimeExtrapolatorId = "TimeExtrapolator";

TimeExtrapolator::TimeExtrapolator() : TimeAdaptor(mTimeExtrapolatorId)
{
    mBuffers.SetDoExtrapolate(true);
}

TimeExtrapolator::TimeExtrapolator(const shared_ptr<IOutput> &adaptee) :
    TimeAdaptor(adaptee->GetId() + "->" + mTimeExtrapolatorId, adaptee)
{}

}  // namespace OpenOasis::CommImp::DevSupports