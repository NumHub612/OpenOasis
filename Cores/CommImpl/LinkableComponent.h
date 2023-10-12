/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  LinkableComponent.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Generic implementation of `ILinkableComponent` with more details.
 *
 ** ***********************************************************************************/
#pragma once
#include "Cores/Inc/ILinkableComponent.h"
#include "Cores/Inc/IOutput.h"
#include "Cores/Inc/IInput.h"
#include "Cores/Inc/IManageState.h"
#include "Cores/Inc/LinkableComponentStatusChangeEventArgs.h"
#include "Cores/Utils/EventHandler.h"


namespace OpenOasis
{
namespace CommImpl
{
using Utils::EventHandler;

/// @brief Generic implementation of `ILinkableComponent` with more process details.
///
/// The implementation here predefines a set of methods that are useful in
/// concrete model engine development.
class LinkableComponent : public ILinkableComponent,
                          public IManageState,
                          public std::enable_shared_from_this<LinkableComponent>
{
protected:
    // --- Object Identity.

    std::string mId          = "";
    std::string mCaption     = "";
    std::string mDescription = "";

    // --- Object Attributes.

    /// The `mStatusChanged` event is fired when Status of this component changes.
    EventHandler<void, std::shared_ptr<LinkableComponentStatusChangeEventArgs>>
        mStatusListeners;

    std::shared_ptr<LinkableComponentStatusChangeEventArgs> mEventArgs;

    std::vector<std::string> mRequiredArguments = {};

    std::vector<std::shared_ptr<IAdaptedOutputFactory>> mAdaptedOutputFactories;

    // --- Object States.

    LinkableComponentStatus mStatus = LinkableComponentStatus::Created;

    bool mCascadingUpdateCallsDisabled = false;

    std::shared_ptr<ITimeSet> mTimeExtent  = nullptr;  // todo: removed.
    std::shared_ptr<ITime>    mCurrentTime = nullptr;  // todo: removed.

    std::unordered_map<std::string, std::shared_ptr<IArgument>> mArguments;

    std::vector<std::shared_ptr<IInput>>  mInputs;
    std::vector<std::shared_ptr<IOutput>> mOutputs;

public:
    virtual ~LinkableComponent() = default;

    LinkableComponent(LinkableComponent &&obj);
    LinkableComponent(const std::string &id);

    ///////////////////////////////////////////////////////////////////////////////////
    // Implement methods inherited from `IDescribable`.
    //

    virtual std::string GetDescription() const override;

    virtual void SetDescription(const std::string &value) override;

    virtual std::string GetCaption() const override;

    virtual void SetCaption(const std::string &value) override;

    ///////////////////////////////////////////////////////////////////////////////////
    // Implement methods inherited from `IIdentifiable`.
    //

    virtual std::string GetId() const override;

    ///////////////////////////////////////////////////////////////////////////////////
    // Implement methods inherited from `ILinkableComponent`.
    //

    virtual std::vector<std::shared_ptr<IArgument>> GetArguments() const override;

    virtual std::vector<std::shared_ptr<IInput>> GetInputs() const override;

    virtual LinkableComponentStatus GetStatus() const override;

    virtual std::vector<std::shared_ptr<IOutput>> GetOutputs() const override;

    virtual std::vector<std::shared_ptr<IAdaptedOutputFactory>>
    GetAdaptedOutputFactories() const override;

    virtual void Initialize() override;

    virtual std::vector<std::string> Validate() override;

    virtual void Prepare() override;

    virtual void
    Update(const std::vector<std::shared_ptr<IOutput>> &requiredOutputs) override;

    virtual void Finish() override;

    virtual void AddListener(const ListenFuncType &func) override;

    virtual void RemoveListener(const ListenFuncType &func) override;

    ///////////////////////////////////////////////////////////////////////////////////
    // Implement methods inherited from `IManageState`.
    //
    // These interfaces are used to manage component state, enabling iterative coupling.
    // Therefore, the data stored in each snapshot of the component must be able to
    // restore the component to its current state.
    //

    virtual std::shared_ptr<IIdentifiable> KeepCurrentState() override;

    virtual void RestoreState(const std::shared_ptr<IIdentifiable> &stateId) override;

    virtual void ClearState(const std::shared_ptr<IIdentifiable> &stateId) override;

public:
    ///////////////////////////////////////////////////////////////////////////////////
    // Additional methods for iteration and optimization.
    //

    virtual void SetCascadingUpdateCallsDisabled(bool status);

    virtual bool GetCascadingUpdateCallsDisabled() const;

    virtual bool IsIterationConverged() const;

    virtual bool IsOptimizationTerminated() const;

    virtual std::shared_ptr<LinkableComponent> GetSnapshot() const;

    ///////////////////////////////////////////////////////////////////////////////////
    // Additional methods for time info and time stepping.
    //

    /// @brief Start time stamp of simulation.
    virtual std::shared_ptr<ITime> GetStartTime() const;

    /// @brief End time stamp of simulation.
    virtual std::shared_ptr<ITime> GetEndTime() const;

    /// @brief The current time stamp, where the engine currently has reached.
    virtual std::shared_ptr<ITime> GetNowTime() const;

    ///////////////////////////////////////////////////////////////////////////////////
    // Internal methods for component initializing.
    //

    virtual void SetArguments(const std::vector<std::shared_ptr<IArgument>> &arguments);

    virtual void SetStatus(LinkableComponentStatus status, const std::string &msg = "");

    virtual void SetAdaptedOutputFactories();

    virtual void InitializeArguments() = 0;

    virtual void InitializeSpace() = 0;

    virtual void InitializeTime() = 0;

    virtual void InitializeInputs() = 0;

    virtual void InitializeOutputs() = 0;

    ///////////////////////////////////////////////////////////////////////////////////
    // Internal methods for component Validating and Preparing.
    //

    virtual std::vector<std::string> OnValidate() = 0;

    virtual void OnPrepare();

    virtual void PrepareInputs() = 0;

    virtual void PrepareOutputs() = 0;

    ///////////////////////////////////////////////////////////////////////////////////
    // Internal methods for component Updating.
    //
    // TODO: refactor UpdateInputs() and UpdateOutputs() to be more generic.
    //

    virtual void UpdateInputs();

    virtual void ApplyInputData(const std::shared_ptr<IValueSet> &values) = 0;

    virtual void
    UpdateOutputs(const std::vector<std::shared_ptr<IOutput>> &requiredOutputs) = 0;

    /// @brief Updates the component one time step.
    ///
    /// This methods will not trigger an update of the input and output items,
    /// the `Update()` method does exactly that.
    virtual void
    PerformTimestep(const std::vector<std::shared_ptr<IOutput>> &outputs) = 0;

    virtual void UpdateInputTimesAndValues();

    ///////////////////////////////////////////////////////////////////////////////////
    // Internal methods for component Finishing.
    //

    virtual void Reset();

    virtual void BroadcastEvent(
        const std::string &msg, LinkableComponentStatus oldState,
        LinkableComponentStatus newState);
};

}  // namespace CommImpl
}  // namespace OpenOasis