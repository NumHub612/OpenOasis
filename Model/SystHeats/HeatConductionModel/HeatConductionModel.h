/** ***********************************************************************************
 *    Copyright (C) 2022, The OpenOasis Contributors. Join us in the Oasis!
 *
 *    @File      :  HeatConductionModel.h
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  A dummy heat conduction model used for example purposes.
 *
 ** ***********************************************************************************/
#pragma once
#include "Model/CommImp/LinkableComponent.h"
#include "Model/CommImp/Output.h"
#include "Model/CommImp/Input.h"
#include "Model/CommImp/Spatial/Grid.h"
#include "Model/CommImp/Numeric/ScalarField.h"
#include "Model/CommImp/Numeric/Solver.h"


namespace OpenOasis
{
namespace SystHeats
{
using CommImp::LinkableComponent;
using CommImp::Numeric::ScalarFieldDbl;
using CommImp::Numeric::Solver;
using CommImp::Spatial::Grid;
using CommImp::Spatial::Coordinate;


class HeatConductionModel : public LinkableComponent
{
private:
    std::string mTaskFile;
    std::string mOutputDir;

    std::shared_ptr<Grid>           mGrid;
    std::shared_ptr<ScalarFieldDbl> mTempValues;
    std::shared_ptr<Solver>         mSolver;

    double      mT0;
    std::string mT0file;

    double mK;

    std::string mStart, mEnd;

    std::string mEigenSolver;

    std::unordered_map<std::string, std::string> mOutputVars;

    // Each variable boundary conditions defined at the pathes.
    std::unordered_map<std::string, std::unordered_map<std::string, double>>
        mPatchBounds;

    std::vector<std::string> mBoundPatches;

    std::unordered_map<std::string, int> mCellOutputs;

    static const std::vector<std::string> sExchangeableStates;
    static const std::vector<std::string> sExchangeableObj;

public:
    HeatConductionModel(const std::string &id, const std::string &taskFile);
    virtual ~HeatConductionModel() = default;

private:
    void InitializeArguments() override;
    void InitializeSpace() override;
    void InitializeTime() override;
    void InitializeInputs() override;
    void InitializeOutputs() override;

    std::vector<std::string> OnValidate() override;

    void PrepareInputs() override;
    void PrepareOutputs() override;
    void UpdateInputs() override;

    void ApplyInputData(const std::shared_ptr<IValueSet> &values) override;
    void UpdateOutputs(const std::vector<std::shared_ptr<IOutput>> &outputs) override;
    void PerformTimestep(const std::vector<std::shared_ptr<IOutput>> &outputs) override;
    bool IsIterationConverged() const override;

private:
    std::shared_ptr<IQuantity> GetTempQuantity();

    std::shared_ptr<IOutput> CreateCellOutput(int idx, const std::string &var);
    std::vector<Coordinate>  NodesInCell(int idx);

    std::tuple<std::vector<double>, std::vector<double>> GenerateCoeAndSrcMatrix();

    std::tuple<double, double> CalculateUniformCoef();

    void SaveResult();
};

}  // namespace SystHeats
}  // namespace OpenOasis