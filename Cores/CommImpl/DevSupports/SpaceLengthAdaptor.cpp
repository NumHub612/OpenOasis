/** ***********************************************************************************
 *    @File      :  SpaceLengthAdaptor.cpp
 *    @Brief     :  AdaptedOutput multiplies the values of the valueset with the length.
 *
 ** ***********************************************************************************/
#include "SpaceLengthAdaptor.h"
#include "ExtensionMethods.h"
#include "ElementMapper.h"
#include "Cores/CommImpl/Dimension.h"
#include "Cores/CommImpl/Unit.h"
#include "Cores/CommImpl/Quantity.h"
#include "Cores/Utils/Exception.h"
#include "Cores/Utils/StringHelper.h"
#include "Tools/MagicEnum/WrapMagicEnum.hpp"


namespace OpenOasis::CommImpl::DevSupports
{
using namespace Spatial;
using namespace Utils;
using namespace std;


SpaceLengthAdaptor::SpaceLengthAdaptor(
    const string &id, const shared_ptr<IOutput> &adaptee) :
    AbstractAdaptedOutput(id, adaptee)
{
    mLengthExponent = 1.0;
    mLengthArgument = make_shared<ArgumentDouble>("LengthExponent", 1.0);

    mArguments.emplace(make_pair("length", mLengthArgument));
    Initialize();

    // Check the adaptee data.
    auto elementSet = adaptee->GetElementSet();
    if (elementSet == nullptr)
    {
        throw invalid_argument("Adaptee must have an IElementSet as SpatialDefinition");
    }

    if (elementSet->GetElementType() != ElementType::Polyline)
    {
        throw invalid_argument(
            "Adaptee must have a SpatialDefinition having polyline as elements");
    }

    if (adaptee->GetValueDefinition()->GetValueType() != typeid(double))
    {
        throw invalid_argument("Adaptee valuetype must be typeof(double)");
    }

    if (!dynamic_pointer_cast<IQuantity>(adaptee->GetValueDefinition()))
    {
        throw invalid_argument("Adaptee valueDefinition must be an IQuantity");
    }
}

void SpaceLengthAdaptor::Initialize()
{
    CalculateFactors(GetElementSet());
    UpdateQuantity();
}

void SpaceLengthAdaptor::SetValues(shared_ptr<IValueSet> value)
{}

shared_ptr<IValueDefinition> SpaceLengthAdaptor::GetValueDefinition() const
{
    return mOutput.lock()->GetValueDefinition();
}

shared_ptr<IElementSet> SpaceLengthAdaptor::GetElementSet() const
{
    return mOutput.lock()->GetElementSet();
}

void SpaceLengthAdaptor::SetTimeSet(shared_ptr<ITimeSet> times)
{}

shared_ptr<ITimeSet> SpaceLengthAdaptor::GetTimeSet() const
{
    return mOutput.lock()->GetTimeSet();
}

void SpaceLengthAdaptor::Refresh()
{
    for (auto adaptedOutput : mAdaptedOutputs)
    {
        adaptedOutput->Refresh();
    }
}

void SpaceLengthAdaptor::SetElementSet(shared_ptr<IElementSet> elements)
{}

void SpaceLengthAdaptor::Reset()
{
    mLengthArgument.reset();
    mQuantity.reset();
    mOutput.reset();
    mConsumers.clear();
    mAdaptedOutputs.clear();
    mFactors.clear();

    mLengthExponent = 1.0;

    BroadcastEventWithMsg("Output item reseted.");
    mItemChanged.Clear();

    Initialize();
}

shared_ptr<ITimeSet> SpaceLengthAdaptor::GetTimeExtent() const
{
    return mOutput.lock()->GetTimeSet();
}

shared_ptr<ITime> SpaceLengthAdaptor::GetCurrTime() const
{
    return ExtensionMethods::End(GetTimeExtent()->GetTimeHorizon());
}

shared_ptr<ISpatialDefinition> SpaceLengthAdaptor::GetSpatialDefinition() const
{
    return GetElementSet();
}

void SpaceLengthAdaptor::CalculateFactors(const shared_ptr<IElementSet> &elementSet)
{
    mFactors        = vector<double>(elementSet->GetElementCount());
    mLengthExponent = any_cast<double>(mLengthArgument->GetValue());

    for (int i = 0; i < mFactors.size(); i++)
    {
        XYPolyline element = ElementMapper::CreateXYPolyline(elementSet, i);
        double     length  = element.GetLength();
        if (mLengthExponent == 1) { mFactors[i] = length; }
        else if (mLengthExponent == -1) { mFactors[i] = 1.0 / length; }
        else { mFactors[i] = pow(length, mLengthExponent); }
    }
}

void SpaceLengthAdaptor::UpdateQuantity()
{
    auto sourceQuantity =
        dynamic_pointer_cast<IQuantity>(mOutput.lock()->GetValueDefinition());
    auto sourceUnit = sourceQuantity->GetUnit();

    auto dimension = make_shared<Dimension>();
    for (auto dimBase : magic_enum::enum_values<DimensionBase>())
    {
        dimension->SetPower(dimBase, sourceUnit->GetDimension()->GetPower(dimBase));
    }

    dimension->SetPower(
        DimensionBase::Length,
        dimension->GetPower(DimensionBase::Length) + mLengthExponent);

    string pu = StringHelper::FormatSimple(" * m^{}", mLengthExponent);
    string pq = StringHelper::FormatSimple(" * length^{}", mLengthExponent);

    auto unit = make_shared<Unit>(
        dimension,
        sourceUnit->GetCaption() + pu,
        sourceUnit->GetDescription() + pu,
        sourceUnit->GetConversionFactorToSI(),
        sourceUnit->GetOffSetToSI());

    mQuantity = make_shared<Quantity>(
        unit, sourceQuantity->GetCaption() + pq, sourceQuantity->GetDescription() + pq);
}

shared_ptr<IValueSet>
SpaceLengthAdaptor::GetValues(const shared_ptr<IBaseExchangeItem> &querier)
{
    return ExtensionMethods::MultiplyElementValues(
        mOutput.lock()->GetValues(querier), mFactors);
}

shared_ptr<SpaceLengthAdaptor> SpaceLengthAdaptor::GetInstance()
{
    return dynamic_pointer_cast<SpaceLengthAdaptor>(shared_from_this());
}

}  // namespace OpenOasis::CommImpl::DevSupports