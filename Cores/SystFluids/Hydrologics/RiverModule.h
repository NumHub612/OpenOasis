/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  RiverModule.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Simple river model for usage example.
 *    The river model is a simple stationary river model. The solution depends on the
 *    input of the current time step only, i.e., no history
 *    from time step to time step.
 *
 *    It takes the inflow on each of the nodes and moves it down the river.
 *    Half of the inflow is leaked, the other half is moved to the next node storage
 *    and added to it. All inflow is either leaked or discharged
 *    in each timestep.

 *    The model has a constant runoff inflow of 10 L/s on each node. Additional runoff
 *    or inflow can be added to each of the nodes (though adding on the
 *    last node has no effect).

 *    It could make the model more "dynamic" by letting 1/3 leak, 1/3 move
 *    to next node and 1/3 stay on the current node.
 *
 ** ***********************************************************************************/
#pragma once
#include "Cores/CommImpl/LinkableComponent.h"
#include "Cores/CommImpl/Output.h"
#include "Cores/CommImpl/Input.h"
#include "Cores/CommImpl/ElementSet.h"
#include "Cores/CommImpl/ValueSet2D.h"
#include "Cores/CommImpl/TimeSet.h"
#include "Cores/CommImpl/Identifier.h"
#include "Cores/Utils/DateTime.h"


namespace OpenOasis::SystFluids
{
using namespace CommImpl;
using namespace Utils;


/// @brief Simple river module for framework usage example.
class RiverModule : public LinkableComponent
{
private:
    struct RiverState : public Identifier
    {
    public:
        RiverState(const std::string &id) : Identifier(id)
        {}

        std::shared_ptr<ValueSet2D> flowValues;
        std::shared_ptr<ValueSet2D> waterLevelValues;
        std::shared_ptr<TimeSet>    times;
        std::shared_ptr<ITime>      currentTime;
        DateTime                    current;
        int                         timeCount;
        LinkableComponentStatus     status;
    };

private:
    std::shared_ptr<ElementSet> mElements;
    std::shared_ptr<ValueSet2D> mFlowValues;
    std::shared_ptr<ValueSet2D> mWaterLevelValues;
    std::shared_ptr<TimeSet>    mTimes;

    DateTime mCurrent;
    TimeSpan mRunningStep;

    int mNodeNum;
    int mTimeCount;

    std::vector<std::shared_ptr<RiverState>> mStates;

public:
    RiverModule(const std::string &id);
    virtual ~RiverModule() = default;

    std::shared_ptr<IIdentifiable> KeepCurrentState() override;

    void RestoreState(const std::shared_ptr<IIdentifiable> &stateId) override;

    void ClearState(const std::shared_ptr<IIdentifiable> &stateId) override;

private:
    void InitializeArguments() override
    {}

    void InitializeSpace() override;

    void InitializeTime() override;

    void InitializeInputs() override;

    void InitializeOutputs() override;

    std::vector<std::string> OnValidate() override;

    void PrepareInputs() override;

    void PrepareOutputs() override;

    void UpdateInputs() override;

    void ApplyInputData(const std::shared_ptr<IValueSet> &values) override
    {}

    void UpdateOutputs(
        const std::vector<std::shared_ptr<IOutput>> &requiredOutputs) override;

    void PerformTimestep(
        const std::vector<std::shared_ptr<IOutput>> &requiredOutputs) override;

    bool IsIterationConverged() const override
    {
        return false;
    }

    std::shared_ptr<IQuantity> GetFlowQuantity();

    std::shared_ptr<IQuantity> GetWaterLevelQuantity();

    double TurnFlowToStage(double flow)
    {
        return flow / 10.0;
    }

    double TurnStageToFlow(double stage)
    {
        return stage * 10.0;
    }
};

}  // namespace OpenOasis