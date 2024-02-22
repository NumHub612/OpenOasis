/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  RunoffModule.cpp
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Runoff module.
 *
 ** ***********************************************************************************/
#pragma once
#include "Model/CommImp/LinkableComponent.h"
#include "Model/CommImp/Output.h"
#include "Model/CommImp/Input.h"
#include "Model/CommImp/ElementSet.h"
#include "Model/CommImp/ValueSet2D.h"
#include "Model/CommImp/TimeSet.h"
#include "Model/Utils/DateTime.h"


namespace OpenOasis::SystFluids::Hydrologics
{
using namespace CommImp;
using namespace Utils;

/// @brief Runoff module accepts rainfall and provides runoff data.
class RunoffModule : public LinkableComponent
{
private:
    std::unordered_map<std::string, std::shared_ptr<IValueSet>> mCompStates;

    std::shared_ptr<ElementSet> mElements;
    std::shared_ptr<ValueSet2D> mValues;
    std::shared_ptr<TimeSet>    mTimes;

    DateTime mCurrent;
    TimeSpan mRunningStep;
    double   mInflow;

public:
    virtual ~RunoffModule()
    {}

    RunoffModule(const RunoffModule &obj);
    RunoffModule(const std::string &id, const std::string &taskFile);

    std::shared_ptr<IQuantity> GetQuantity();

private:
    void InitializeArguments() override;

    void InitializeSpace() override;

    void InitializeTime() override;

    void InitializeInputs() override;

    void InitializeOutputs() override;

    std::vector<std::string> OnValidate() override;

    void PrepareInputs() override;

    void PrepareOutputs() override;

    void ApplyInputData(const std::shared_ptr<IValueSet> &values) override;

    void UpdateOutputs(
        const std::vector<std::shared_ptr<IOutput>> &requiredOutputs) override;

    void PerformTimestep(
        const std::vector<std::shared_ptr<IOutput>> &requiredOutputs) override;
};


class RunoffInput : public Input
{
public:
    virtual ~RunoffInput()
    {}

    RunoffInput(const std::string &id, const std::shared_ptr<RunoffModule> &comp);
};


class RunoffOutput : public Output
{
public:
    virtual ~RunoffOutput()
    {}

    RunoffOutput(const std::string &id, const std::shared_ptr<RunoffModule> &comp);
};

}  // namespace OpenOasis::SystFluids::Hydrologics