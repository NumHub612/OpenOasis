/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  RainfallModule.cpp
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  Rainfall module.
 *
 ** ***********************************************************************************/
#pragma once
#include "Cores/CommImpl/LinkableComponent.h"
#include "Cores/CommImpl/Output.h"
#include "Cores/CommImpl/ElementSet.h"
#include "Cores/CommImpl/ValueSet2D.h"
#include "Cores/CommImpl/TimeSet.h"


namespace OpenOasis::SystFluids
{
using namespace CommImpl;

/// @brief Rainfall module provides rainfall data.
class RainfallModule : public LinkableComponent
{
private:
    std::unordered_map<std::string, std::shared_ptr<IValueSet>> mCompStates;

    std::shared_ptr<ElementSet> mElements;
    std::shared_ptr<ValueSet2D> mValues;
    std::shared_ptr<TimeSet>    mTimes;

    int mCurrentIdx = 0;

public:
    virtual ~RainfallModule()
    {}

    RainfallModule(const RainfallModule &obj);
    RainfallModule(
        const std::string &id, std::shared_ptr<IElementSet> elements,
        std::shared_ptr<ITimeSet> times, std::shared_ptr<IValueSet> values);
    RainfallModule(
        const std::string &id, const std::string &coorFile,
        const std::string &dataFile);

    std::shared_ptr<IQuantity> GetQuantity();

private:
    void InitializeArguments() override;

    void InitializeSpace() override;

    void InitializeTime() override;

    void InitializeInputs() override
    {}

    void InitializeOutputs() override;

    std::vector<std::string> OnValidate() override;

    void PrepareInputs() override
    {}

    void PrepareOutputs() override;

    void ApplyInputData(const std::shared_ptr<IValueSet> &values) override
    {}

    void UpdateOutputs(
        const std::vector<std::shared_ptr<IOutput>> &requiredOutputs) override;

    void PerformTimestep(
        const std::vector<std::shared_ptr<IOutput>> &requiredOutputs) override;
};


class RainfallOutput : public Output
{
public:
    virtual ~RainfallOutput()
    {}

    RainfallOutput(const std::string &id, const std::shared_ptr<RainfallModule> &comp);
};

}  // namespace OpenOasis