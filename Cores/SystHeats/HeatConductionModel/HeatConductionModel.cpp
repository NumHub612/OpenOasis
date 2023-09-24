/** ***********************************************************************************
 *    @File      :  HeatConductionModel.cpp
 *    @Brief     :  Heat conduction model.
 *
 ** ***********************************************************************************/
#include "HeatConductionModel.h"
#include "Cores/CommImpl/Arguments.h"
#include "Cores/CommImpl/Dimension.h"
#include "Cores/CommImpl/Unit.h"
#include "Cores/CommImpl/Time.h"
#include "Cores/CommImpl/TimeSet.h"
#include "Cores/CommImpl/Quantity.h"
#include "Cores/CommImpl/ElementSet.h"
#include "Cores/CommImpl/ValueSet2D.h"
#include "Cores/CommImpl/IO/logging.h"
#include "Cores/CommImpl/Spatial/Grid2D.h"
#include "Cores/Utils/YamlHandler.h"
#include "Cores/Utils/Exception.h"
#include "Cores/Utils/StringHelper.h"
#include "Cores/Utils/FilePathHelper.h"
#include "Cores/Utils/VectorHelper.h"
#include "Cores/Utils/CsvHandler.h"
#include "Tools/Eigen/IterativeLinearSolvers"
#include <set>


namespace OpenOasis::SystHeats
{
using namespace CommImpl;
using namespace Spatial;
using namespace Utils;
using namespace std;

HeatConductionModel::HeatConductionModel(const string &id, const string &taskFile) :
    LinkableComponent(id)
{
    mCaption     = "2D steady heat conduction module";
    mDescription = "(more details)";

    mTaskFile = FilePathHelper::GetFullPath(taskFile);

    mRequiredArguments.push_back("TaskFile");
    mArguments["TaskFile"] = make_shared<ArgumentString>("TaskFile", mTaskFile);
}

void HeatConductionModel::InitializeArguments()
{
    YamlLoader yml;
    yml.LoadByFile(mTaskFile);

    auto   taskDir = FilePathHelper::GetDirectoryName(mTaskFile);
    string ErrMsg  = "HeatConductionModel {} section [{}] lack of configurations.";

    // Global options.
    string seg = "OPTION";

    // Mesh.
    seg = "MESH";

    auto meshDir = "D:\\4_resource\\oasis_examples\\heat_conduction_model\\geom";

    mGrid = make_shared<Grid2D>(meshDir);

    // Initialization.
    seg = "INITIALIZATION";
    mT0 = 0.0;

    // Boundaries.
    seg      = "BOUNDARY";
    mBoundT1 = 100, mBoundT2 = 20;  // T1 in right and left, T2 in top and bottom.

    // Sovler.
    seg = "SOVLER";
    mK  = 81;  // W / m*K	Conductivity

    // Output.
    seg = "OUTPUT";

    mOutputDir = "D:\\4_resource\\oasis_examples\\heat_conduction_model\\results";
}

void HeatConductionModel::InitializeSpace()
{
    mGrid->Activate();

    auto size   = mGrid->GetNumCells();
    mTempValues = make_shared<ScalarFieldDbl>(size, mT0);
}

void HeatConductionModel::InitializeTime()
{
    // To give a time point.
    mCurrentTime = make_shared<Time>(DateTime::FromString("2023/1/1 00:00:00"));

    mTimeExtent = make_shared<TimeSet>();
    mTimeExtent->AddTime(mCurrentTime);
}

void HeatConductionModel::InitializeInputs()
{
    // Don't accept input currently.
}

void HeatConductionModel::InitializeOutputs()
{
    static const vector<string> validType = {"NODE", "FACE", "CELL"};
    static const vector<string> validVar  = {"T"};

    const auto &outputters =
        any_cast<vector<array<string, 3>>>(mArguments["OUTPUTTERS"]->GetValue());

    for (const auto &output : outputters)
    {
        if (output[0] != "CELL" || output[2] != "T") continue;

        mOutputs.push_back(CreateCellOutput(stoi(output[1]), "T"));
    }
}

shared_ptr<IOutput> HeatConductionModel::CreateCellOutput(int idx, const string &var)
{
    if (idx < 0 || idx > mGrid->GetNumCells())
    {
        throw invalid_argument("Cell output item out of range.");
    }

    auto comp = dynamic_pointer_cast<HeatConductionModel>(shared_from_this());

    auto cellId = mId + "_cell_" + to_string(idx);

    vector<Coordinate> nodes = NodesInCell(idx);

    Element cell(cellId, "cell", "", nodes);

    auto element = make_shared<ElementSet>(
        "HeatConductionModel face", "", ElementType::Polygon, vector<Element>{cell});

    auto outputId = StringHelper::FormatSimple("{}_output_cell_{}_{}", mId, var, idx);
    mCellOutputs[outputId] = idx;

    auto output = make_shared<Output>(outputId, comp);
    output->SetCaption("HeatConductionModel output item");
    output->SetDescription("Output exchange item providing temperature data.");
    output->SetElementSet(element);
    mOutputs.push_back(output);

    return output;
}

vector<Coordinate> HeatConductionModel::NodesInCell(int idx)
{
    set<int> nodeIdxs;

    for (int faceIdx : mGrid->GetCell(idx).faceIndexes)
    {
        for (int nodeIdx : mGrid->GetFace(faceIdx).nodeIndexes)
        {
            nodeIdxs.emplace(nodeIdx);
        }
    }

    vector<Coordinate> nodes;
    for (int i : nodeIdxs) nodes.push_back(mGrid->GetNode(i).coor);

    return nodes;
}

vector<string> HeatConductionModel::OnValidate()
{
    // No validation check currently.
    return {};
}

void HeatConductionModel::PrepareInputs()
{
    // pass.
}

void HeatConductionModel::PrepareOutputs()
{
    for (auto &output : mOutputs)
    {
        output->SetValues(
            make_shared<ValueSet2D>(vector<vector<double>>{{mT0}}, GetTempQuantity()));
    }
}

shared_ptr<IQuantity> HeatConductionModel::GetTempQuantity()
{
    auto dime = make_shared<Dimension>();
    dime->SetPower(DimensionBase::Temperature, 1);

    auto unit = make_shared<Unit>(dime, "temperature", "centigrade(℃)", 1., 273.15);
    auto quan = make_unique<Quantity>(unit, "temperature", "centigrade(℃)", -9999.);
    return quan;
}

void HeatConductionModel::UpdateInputs()
{
    // pass.
}

void HeatConductionModel::ApplyInputData(const shared_ptr<IValueSet> &values)
{
    // pass.
}

void HeatConductionModel::UpdateOutputs(const vector<shared_ptr<IOutput>> &outputs)
{
    for (auto &output : outputs)
    {
        const auto &values = output->GetValues(output);

        double temp = (*mTempValues)(mCellOutputs[output->GetId()]);
        values->SetTimeSeriesValuesForElement(0, {temp});
    }
}

void HeatConductionModel::PerformTimestep(const vector<shared_ptr<IOutput>> &outputs)
{
    vector<double> matrix, source;
    tie(matrix, source) = GenerateCoeAndSrcMatrix();

    int size = sqrt(matrix.size());

    // Solve Ax=b by Eigen.
    Eigen::Map<Eigen::MatrixXd> A(matrix.data(), size, size);
    // 填充A
    Eigen::Map<Eigen::VectorXd> b(source.data(), size);
    // // 填充b
    Eigen::ConjugateGradient<Eigen::MatrixXd> solver;
    solver.compute(A);
    if (solver.info() != Eigen::Success)
    {
        // 分解失败
        throw runtime_error("compute failed.");
    }
    Eigen::VectorXd x = solver.solve(b);
    if (solver.info() != Eigen::Success)
    {
        // 解决失败
        throw runtime_error("Solve failed.");
    }

    vector<double> solution(&x[0], x.data() + x.cols() * x.rows());
    for (int i = 0; i < size; i++) mTempValues->SetAt(i, solution[i]);

    SaveResult();
}

tuple<vector<double>, vector<double>> HeatConductionModel::GenerateCoeAndSrcMatrix()
{
    // -Calculate coefficients.

    double xCoe, yCoe;
    tie(xCoe, yCoe) = CalculateUniformCoef();

    // -All DIRICHLET boundary conditions, use 1-st precision.

    int size = mGrid->GetNumCells();

    vector<double> matrix(size * size, 0);
    vector<double> source(size, 0);

    for (int i = 0; i < size; i++)
    {
        matrix[i * size + i] = -2. * (xCoe + yCoe);

        const auto &cell = mGrid->GetCell(i);
        for (int j : cell.faceIndexes)
        {
            const auto &face   = mGrid->GetFace(j);
            const auto &normal = face.normal;
            const auto &cells  = face.cellIndexes;

            // Face location.
            bool isEast  = (abs(normal[0] - 1.0) < 1.e-9) ? true : false;
            bool isWest  = (abs(normal[0] + 1.0) < 1.e-9) ? true : false;
            bool isNorth = (abs(normal[1] - 1.0) < 1.e-9) ? true : false;
            bool isSouth = (abs(normal[1] + 1.0) < 1.e-9) ? true : false;
            bool isBound = (cells.size() == 1) ? true : false;

            // Boundary conditions.
            if (isBound)
            {
                if (isEast || isWest)
                {
                    matrix[i * size + i] -= xCoe;
                    source[i] -= 2. * xCoe * mBoundT1;
                }
                else if (isNorth || isSouth)
                {
                    matrix[i * size + i] -= yCoe;
                    source[i] -= 2. * yCoe * mBoundT2;
                }
            }
            // interial cell.
            else
            {
                int cellIdx = (cells[0] == i) ? cells[1] : cells[0];

                matrix[i * size + cellIdx] = (isEast || isWest) ? xCoe : yCoe;
            }
        }
    }

    return {matrix, source};
}

tuple<double, double> HeatConductionModel::CalculateUniformCoef()
{
    // A uniform rectangular 2d grid has same cell centroid distance at each
    // direction.
    double dx = 0, dy = 0;

    const auto &cell = mGrid->GetCell(0);
    const auto &coor = cell.centroid;
    for (int i : cell.neighbors)
    {
        const auto &_coor = mGrid->GetCell(i).centroid;

        double _dx = abs(_coor.x - coor.x);
        double _dy = abs(_coor.y - coor.y);

        dx = max(dx, _dx);
        dy = max(dy, _dy);

        if (dx > 1.e-10 && dy > 1.e-10) break;
    }

    double xCoe = -mK * dy / dx;
    double yCoe = -mK * dx / dy;
    return {xCoe, yCoe};
}

void HeatConductionModel::SaveResult()
{
    auto file = FilePathHelper::Combine(mOutputDir, "heat_conduction_result.csv");

    CsvWriter writer(file);
    writer.InsertColumn<double>(0, "temp", mTempValues->Data());

    writer.SetRowLabel(-1, "id");
    for (int i = 0; i < mTempValues->Size(); i++) writer.SetRowLabel(i, to_string(i));

    writer.Save();
}

bool HeatConductionModel::IsIterationConverged() const
{
    return true;
}

}  // namespace OpenOasis::SystHeats