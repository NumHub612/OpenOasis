/** ***********************************************************************************
 *    Copyright (C) 2022, All OpenOasis Contributors. Join us on this journey!
 *
 *    @File      :  launcher.cpp
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  OpenOasis project entry.
 *
 ** ***********************************************************************************/
#include "Cores/Utils/LibraryLoader.h"
#include "Cores/Utils/CommMacros.h"
#include "Cores/Utils/DateTime.h"
#include "Cores/SystFluids/export/OasisFluidsModule.h"
#include "Cores/CommImpl/Time.h"
#include "Cores/CommImpl/DevSupports/IterationController.h"
#include "Tools/spdlog/spdlog.h"
#include <string>
#include <vector>
#include <iostream>
#include <thread>
#include <iomanip>

using namespace OpenOasis;
using namespace CommImpl;
using namespace DevSupports;
using namespace Utils;
using namespace std;


void RoutineFlowTest(
    const std::string &dllPath, const std::string &raingageId,
    const std::string &runoffId)
{
    std::string CoorFile = "D:\\4_resource\\raingage-data\\coordinate.csv";
    std::string RainFile = "D:\\4_resource\\raingage-data\\rainfall.csv";
    std::string TaskFile = "D:\\4_resource\\raingage-data\\task.txt";

    LibraryLoader dll;
    if (!dll.Load(dllPath))
    {
        spdlog::info("dll not loaded, path: {}.", dllPath);
        return;
    }

    cout << "\n----------------------------------------------------\n";

    auto raingage_raw =
        dll.RunFunction<void *(const char *, const char *, const char *)>(
            "GetRainfallModule",
            raingageId.c_str(),
            CoorFile.c_str(),
            RainFile.c_str());
    auto raingage = static_cast<ILinkableComponent *>(raingage_raw);


    if (!raingage)
    {
        spdlog::error("GetRainfallModule api failed.");
        return;
    }
    spdlog::info("rainfall {} created.", raingageId.c_str());

    raingage->Initialize();
    spdlog::info("rainfall {} Initialized.", raingageId.c_str());

    raingage->Validate();
    spdlog::info("rainfall {} Validated.", raingageId.c_str());

    const auto &outputs = raingage->GetOutputs();
    auto iter = find_if(begin(outputs), end(outputs), [&raingageId](const auto &item) {
        return item->GetId() == raingageId;
    });
    if (iter == outputs.end())
    {
        spdlog::error("Rainfall output {} not found.", raingageId);
        return;
    }
    const auto output = *iter;

    const auto factories = raingage->GetAdaptedOutputFactories();
    auto       iter2 =
        find_if(begin(factories), end(factories), [&raingageId](const auto &item) {
            return item->GetId() == raingageId + "-Time";
        });
    const auto tFactory = *iter2;

    auto iter3 =
        find_if(begin(factories), end(factories), [&raingageId](const auto &item) {
            return item->GetId() == raingageId + "-Space";
        });
    const auto sFactory = *iter3;

    cout << "\n----------------------------------------------------\n";

    auto runoff_raw = dll.RunFunction<void *(const char *, const char *)>(
        "GetRunoffModule", runoffId.c_str(), TaskFile.c_str());
    auto runoff = static_cast<ILinkableComponent *>(runoff_raw);

    if (!runoff)
    {
        spdlog::error("GetRunoffModule api failed.");
        return;
    }
    spdlog::info("model {} created.", runoffId.c_str());

    runoff->Initialize();
    spdlog::info("model {} Initialized.", runoffId.c_str());

    runoff->Validate();
    spdlog::info("model {} Validated.", runoffId.c_str());

    const auto &inputs = runoff->GetInputs();
    for (auto &input : inputs)
    {
        auto timeAdaptors = tFactory->GetAvailableAdaptedOutputIds(output, input);
        auto tAdaptorId   = timeAdaptors.front();
        auto tAdaptor     = tFactory->CreateAdaptedOutput(tAdaptorId, output, input);

        auto spaceAdators = sFactory->GetAvailableAdaptedOutputIds(output, input);
        auto sAdaptorId   = spaceAdators.front();
        auto sAdaptor     = sFactory->CreateAdaptedOutput(sAdaptorId, tAdaptor, input);

        input->AddProvider(sAdaptor);
    }

    cout << "\n----------------------------------------------------\n";

    raingage->Prepare();
    spdlog::info("model {} Prepared.", raingageId);

    runoff->Prepare();
    spdlog::info("model {} Prepared.", runoffId);

    cout << "\n----------------------------------------------------\n";

    while (runoff->GetStatus() != LinkableComponentStatus::Done
           && runoff->GetStatus() != LinkableComponentStatus::Failed)
    {
        runoff->Update({});

        for (auto &output : runoff->GetOutputs())
        {
            auto values = output->GetValues({});
            auto times  = output->GetTimeSet();

            cout << "\ntime size: " << times->GetTimes().size();
            cout << ", -- time: " << setw(20)
                 << CommImpl::Time::ToString(times->GetTimes().back());
            cout << "; value size: " << values->GetIndexCount({0});
            cout << ", -- value: " << any_cast<double>(values->GetValue({0, 0}));
        }
    }

    cout << endl;
    spdlog::info("model {} done.", runoff->GetId());

    cout << "-----------------------\n";

    runoff->Finish();
    spdlog::info("model {} Finished.", runoff->GetId());

    raingage->Finish();
    spdlog::info("model {} Finished.", raingage->GetId());

    cout << "\n----------------------------------------------------\n";
}

void IterationTest(const std::string &dllPath)
{
    LibraryLoader dll;
    if (!dll.Load(dllPath))
    {
        spdlog::info("dll not loaded, path: {}.", dllPath);
        return;
    }

    cout << "\n----------------------------------------------------\n";

    auto river_raw = dll.RunFunction<void *(const char *)>("GetRiverModule", "river1");
    auto river     = static_cast<ILinkableComponent *>(river_raw);

    if (!river)
    {
        spdlog::error("GetriverModule api failed.");
        return;
    }
    spdlog::info("model {} created.", river->GetId());

    river->Initialize();
    spdlog::info("model {} Initialized.", river->GetId());

    river->Validate();
    spdlog::info("model {} Validated.", river->GetId());

    river->Prepare();
    spdlog::info("model {} Prepared.", river->GetId());

    cout << "\n----------------------------------------------------\n";

    auto river2_raw = dll.RunFunction<void *(const char *)>("GetRiverModule", "river2");
    auto river2     = static_cast<ILinkableComponent *>(river2_raw);

    if (!river2)
    {
        spdlog::error("GetriverModule api failed.");
        return;
    }
    spdlog::info("model {} created.", river2->GetId());

    river2->Initialize();
    spdlog::info("model {} Initialized.", river2->GetId());

    river2->Validate();
    spdlog::info("model {} Validated.", river2->GetId());

    river2->Prepare();
    spdlog::info("model {} Prepared.", river2->GetId());

    cout << "\n----------------------------------------------------\n";

    auto river3_raw = dll.RunFunction<void *(const char *)>("GetRiverModule", "river3");
    auto river3     = static_cast<ILinkableComponent *>(river3_raw);

    if (!river3)
    {
        spdlog::error("GetriverModule api failed.");
        return;
    }
    spdlog::info("model {} created.", river3->GetId());

    river3->Initialize();
    spdlog::info("model {} Initialized.", river3->GetId());

    river3->Validate();
    spdlog::info("model {} Validated.", river3->GetId());

    river3->Prepare();
    spdlog::info("model {} Prepared.", river3->GetId());

    cout << "\n----------------------------------------------------\n";

    auto outputs = river->GetOutputs();
    auto inputs  = river->GetInputs();

    auto outputs2 = river2->GetOutputs();
    auto inputs2  = river2->GetInputs();

    auto outputs3 = river3->GetOutputs();
    auto inputs3  = river3->GetInputs();

    inputs[0]->AddProvider(outputs2[0]);   // river_input_q_0 -> river2_output_q_0
    inputs3[2]->AddProvider(outputs2[2]);  // river3_input_q_1 -> river2_output_q_1
    inputs2[5]->AddProvider(outputs3[5]);  // river2_input_z_2 -> river3_output_z_2

    spdlog::info("components linked.");

    cout << "\n----------------------------------------------------\n";

    auto controller = make_shared<IterationController>("iterationer");
    auto r2         = dynamic_cast<LinkableComponent *>(river2);
    auto r3         = dynamic_cast<LinkableComponent *>(river2);

    controller->AddComponent(r2->shared_from_this());
    controller->AddComponent(r3->shared_from_this());

    controller->Initialize();
    spdlog::info("model {} Initialized.", controller->GetId());

    controller->Validate();
    spdlog::info("model {} Validated.", controller->GetId());

    controller->Prepare();
    spdlog::info("model {} Prepared.", controller->GetId());

    cout << "\n----------------------------------------------------\n";

    while (river->GetStatus() != LinkableComponentStatus::Done
           && river->GetStatus() != LinkableComponentStatus::Failed)
    {
        river->Update({});

        for (auto &output : outputs2)
        {
            auto values = output->GetValues({});
            auto times  = output->GetTimeSet();

            int tCount = times->GetTimes().size();
            int vCount = values->GetIndexCount({tCount - 1});
            cout << "\nid: " << output->GetId() << ", time size: " << tCount;
            cout << ", -- time: " << setw(20)
                 << CommImpl::Time::ToString(times->GetTimes().back());
            cout << "; value size: " << vCount;
            cout << ", -- value: "
                 << any_cast<double>(values->GetValue({tCount - 1, 0}));
        }
    }
    cout << endl;

    cout << "\n----------------------------------------------------\n";

    river->Finish();
    spdlog::info("model {} Finished.", river->GetId());

    river2->Finish();
    spdlog::info("model {} Finished.", river2->GetId());

    river3->Finish();
    spdlog::info("model {} Finished.", river3->GetId());
}


int main(int argc, const char *argv[])
{
    if (argc < 2)
    {
        spdlog::error("No enough({0:d}) inputs.", argc);
        return -1;
    }

    std::string dllPath(argv[1]);

    cout << "\n====================================\n";
    cout << "            RoutineFlowTest";
    cout << "\n====================================\n";

    RoutineFlowTest(dllPath, "gage1", "runoff1");

    cout << "\n====================================\n";
    cout << "            IterationTest";
    cout << "\n====================================\n";

    IterationTest(dllPath);

    return 0;
}
