#include "ThirdPart/Catch2/catch.hpp"
#include "FolderConfig.h"
#include "Model/Utils/FilePathHelper.h"
#include "Model/Utils/CsvHandler.h"
#include "Model/Utils/JsonHandler.h"
#include "Model/CommImpl/Time.h"
#include "ThirdPart/spdlog/spdlog.h"
#include "Model/CommImpl/DevSupports/IterationController.h"
#include "Model/SystFluids/Hydrologics/RainfallModule.h"
#include "Model/SystFluids/Hydrologics/RunoffModule.h"
#include "Model/SystFluids/Hydrologics/RiverModule.h"
#include <iostream>

using namespace std;
using namespace OpenOasis;
using namespace OpenOasis::SystFluids::Hydrologics;
using namespace OpenOasis::Utils;
using namespace OpenOasis::CommImpl::DevSupports;


void run_pull_mode(string configs, string parent);
void run_loop_mode(string configs, string parent);

TEST_CASE("OpenOasis framework tests")
{
    string path = FilePathHelper::Combine(PROJECT_SRC_DIR, "Model/tests/examples/");

    SECTION("pull mode test")
    {
        string configs = FilePathHelper::Combine(path, "run_modes/pull_configs.json");

        // run_pull_mode(configs, path);
    }

    SECTION("loop mode test")
    {
        string configs = FilePathHelper::Combine(path, "run_modes/loop_configs.json");

        // run_loop_mode(configs, path);
    }
}

shared_ptr<ILinkableComponent>
create_rainfall_model(const string &id, const string &parent)
{
    string coorFile = FilePathHelper::Combine(parent, "rainfall_model/coordinates.csv");
    string rainFile = FilePathHelper::Combine(parent, "rainfall_model/rainfall.csv");

    auto raingage = make_shared<RainfallModule>(id, coorFile, rainFile);
    if (!raingage)
    {
        //spdlog::error("Create RainfallModule failed.");
        throw exception();
    }

    //spdlog::info("rainfall model {} created.", id);
    return raingage;
}

shared_ptr<ILinkableComponent>
create_runoff_model(const string &id, const string &parent, const string &tFile)
{
    auto taskFile = FilePathHelper::Combine(parent, tFile);

    auto runoff = make_shared<RunoffModule>(id, taskFile);
    if (!runoff)
    {
        //spdlog::error("Create RunoffModule failed.");
        throw exception();
    }

    //spdlog::info("runoff model {} created.", id);
    return runoff;
}

shared_ptr<ILinkableComponent> create_river_model(const string &id)
{
    auto river = make_shared<RiverModule>(id);
    if (!river)
    {
        //spdlog::error("Create RiverModule failed.");
        throw exception();
    }

    //spdlog::info("river model {} created.", id);
    return river;
}

void run_pull_mode(string configs, string parent)
{
    JsonLoader jLoader(configs);

    // build models ----------------------------------------------------

    auto mIds = jLoader.GetKeys({"models"});

    unordered_map<string, shared_ptr<ILinkableComponent>> models;
    for (auto &id : mIds)
    {
        auto confs = jLoader.GetMap({"models", id});

        if (confs["model_type"] == "RainfallModel")
        {
            models[id] = create_rainfall_model(id, parent);
        }

        if (confs["model_type"] == "RunoffModel")
        {
            models[id] = create_runoff_model(id, parent, confs["task_file"]);
        }
    }

    // set inputs and outputs ------------------------------------------

    auto lIds = jLoader.GetKeys({"links"});

    vector<unordered_map<string, string>> links;
    for (auto &id : lIds)
    {
        auto src_id = jLoader.GetValue<string>({"links", id}, "source_model").value();
        auto tar_id = jLoader.GetValue<string>({"links", id}, "target_model").value();

        if (models.count(src_id) == 0 || models.count(tar_id) == 0)
        {
            throw exception();
        }

        // collect source confs.
        auto src_model = models[src_id];
        auto src_args  = src_model->GetArguments();
        auto output_arg =
            *(find_if(begin(src_args), end(src_args), [](const auto &item) {
                return item->GetId() == "OUTPUTTERS";
            }));

        int src_element_size = jLoader.GetArraySize({"links", id, "source_elementset"});
        unordered_map<string, string> src_elements;
        for (int i = 0; i < src_element_size; i++)
        {
            auto eId =
                jLoader.GetValue<string>({"links", id, "source_elementset"}, i, "id");
            auto type =
                jLoader.GetValue<string>({"links", id, "source_elementset"}, i, "type");

            src_elements.insert({eId.value(), type.value()});
        }

        // collect target confs.
        auto tar_model = models[tar_id];
        auto tar_args  = tar_model->GetArguments();
        auto input_arg =
            *(find_if(begin(tar_args), end(tar_args), [](const auto &item) {
                return item->GetId() == "INPUTTERS";
            }));

        int tar_element_size = jLoader.GetArraySize({"links", id, "target_elementset"});
        unordered_map<string, string> tar_elements;
        for (int i = 0; i < tar_element_size; i++)
        {
            auto eId =
                jLoader.GetValue<string>({"links", id, "target_elementset"}, i, "id");
            auto type =
                jLoader.GetValue<string>({"links", id, "target_elementset"}, i, "type");

            tar_elements.insert({eId.value(), type.value()});
        }

        // build link.
        int link_size = jLoader.GetArraySize({"links", id, "data_exchanged"});
        vector<array<string, 3>> src_outputs, tar_inputs;
        for (int i = 0; i < link_size; i++)
        {
            // output data.
            auto src_state =
                jLoader
                    .GetValue<string>({"links", id, "data_exchanged"}, i, "src_state")
                    .value();
            auto src_element =
                jLoader
                    .GetValue<string>(
                        {"links", id, "data_exchanged"}, i, "src_elementset")
                    .value();
            auto src_type = src_elements[src_element];

            src_outputs.push_back({src_type, src_element, src_state});

            // input data.
            auto tar_state =
                jLoader
                    .GetValue<string>({"links", id, "data_exchanged"}, i, "tar_state")
                    .value();
            auto tar_element =
                jLoader
                    .GetValue<string>(
                        {"links", id, "data_exchanged"}, i, "tar_elementset")
                    .value();
            auto tar_type = tar_elements[tar_element];

            tar_inputs.push_back({tar_type, tar_element, tar_state});

            // data operations.
            auto temp_ops = jLoader
                                .GetValue<string>(
                                    {"links", id, "data_exchanged"}, i, "temporal_ops")
                                .value();
            auto spatial_ops =
                jLoader
                    .GetValue<string>({"links", id, "data_exchanged"}, i, "spatial_ops")
                    .value();

            unordered_map<string, string> ops;
            ops.insert({"src_id", src_id});
            ops.insert({"tar_id", tar_id});
            ops.insert({"temp_ops", temp_ops});
            ops.insert({"spatial_ops", spatial_ops});

            links.push_back(ops);
        }

        // set arguments.
        output_arg->SetValue(src_outputs);
        input_arg->SetValue(tar_inputs);
    }

    // init source model -----------------------------------------------

    string src_model_id = "gage1";
    auto   raingage     = models[src_model_id];

    raingage->Initialize();
    //spdlog::info("model {} Initialized.", src_model_id);

    raingage->Validate();
    //spdlog::info("model {} Validated.", src_model_id);

    // init target model -----------------------------------------------

    string tar_model_id = "runoff1";
    auto   runoff       = models[tar_model_id];

    runoff->Initialize();
    //spdlog::info("model {} Initialized.", tar_model_id);

    runoff->Validate();
    //spdlog::info("model {} Validated.", tar_model_id);

    // set time and space output adaptor -------------------------------

    const auto &outputs = raingage->GetOutputs();
    auto        iter =
        find_if(begin(outputs), end(outputs), [&src_model_id](const auto &item) {
            return item->GetId() == src_model_id;
        });

    if (iter == outputs.end())
    {
        //spdlog::error("Rainfall output {} not found.", src_model_id);
        return;
    }
    const auto output = *iter;

    const auto factories = raingage->GetAdaptedOutputFactories();
    auto       iter2 =
        find_if(begin(factories), end(factories), [&src_model_id](const auto &item) {
            return item->GetId() == src_model_id + "-Time";
        });
    const auto tFactory = *iter2;

    auto iter3 =
        find_if(begin(factories), end(factories), [&src_model_id](const auto &item) {
            return item->GetId() == src_model_id + "-Space";
        });
    const auto sFactory = *iter3;

    // set input ----------------------------------------------------

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

    // prepare models --------------------------------------------------

    raingage->Prepare();
    //spdlog::info("model {} Prepared.", src_model_id);

    runoff->Prepare();
    //spdlog::info("model {} Prepared.", tar_model_id);

    // run models ------------------------------------------------------

    while (runoff->GetStatus() != LinkableComponentStatus::Done
           && runoff->GetStatus() != LinkableComponentStatus::Failed)
    {
        runoff->Update({});

        for (auto &output : runoff->GetOutputs())
        {
            auto values = output->GetValues({});
            auto times  = output->GetTimeSet();

            // cout << "\ntime size: " << times->GetTimes().size();
            // cout << ", -- time: " << setw(20)
            //      << CommImpl::Time::ToString(times->GetTimes().back());
            // cout << "; value size: " << values->GetIndexCount({0});
            // cout << ", -- value: " << any_cast<double>(values->GetValue({0, 0}));

            
        }
    }

    cout << endl;
    //spdlog::info("model {} done.", runoff->GetId());

    // finish models ---------------------------------------------------

    runoff->Finish();
    //spdlog::info("model {} Finished.", runoff->GetId());

    raingage->Finish();
    //spdlog::info("model {} Finished.", raingage->GetId());
}

void run_loop_mode(string configs, string parent)
{
    JsonLoader jLoader(configs);

    // build models ----------------------------------------------------

    auto mIds = jLoader.GetKeys({"models"});

    unordered_map<string, shared_ptr<ILinkableComponent>> models;
    for (auto &id : mIds)
    {
        auto confs = jLoader.GetMap({"models", id});

        if (confs["model_type"] == "RiverModel")
        {
            models[id] = create_river_model(id);
        }
    }

    // ----------------------------------------------------

    auto river = models["river1"];
    river->Initialize();
    //spdlog::info("model {} Initialized.", river->GetId());

    river->Validate();
    //spdlog::info("model {} Validated.", river->GetId());

    river->Prepare();
    //spdlog::info("model {} Prepared.", river->GetId());

    cout << "\n----------------------------------------------------\n";

    auto river2 = models["river2"];
    river2->Initialize();
    //spdlog::info("model {} Initialized.", river2->GetId());

    river2->Validate();
    //spdlog::info("model {} Validated.", river2->GetId());

    river2->Prepare();
    //spdlog::info("model {} Prepared.", river2->GetId());

    cout << "\n----------------------------------------------------\n";

    auto river3 = models["river3"];
    river3->Initialize();
    //spdlog::info("model {} Initialized.", river3->GetId());

    river3->Validate();
    //spdlog::info("model {} Validated.", river3->GetId());

    river3->Prepare();
    //spdlog::info("model {} Prepared.", river3->GetId());

    cout << "\n----------------------------------------------------\n";

    auto outputs = river->GetOutputs();
    auto inputs  = river->GetInputs();

    auto outputs2 = river2->GetOutputs();
    auto inputs2  = river2->GetInputs();

    auto outputs3 = river3->GetOutputs();
    auto inputs3  = river3->GetInputs();

    inputs[0]->AddProvider(outputs2[0]);   // river_input_q_0 ->river2_output_q_0
    inputs3[2]->AddProvider(outputs2[2]);  // river3_input_q_1->river2_output_q_1
    inputs2[5]->AddProvider(outputs3[5]);  // river2_input_z_2->river3_output_z_2

    //spdlog::info("components linked.");

    cout << "\n----------------------------------------------------\n";

    auto controller = make_shared<IterationController>("iterationer");
    auto r2         = dynamic_pointer_cast<LinkableComponent>(river2);
    auto r3         = dynamic_pointer_cast<LinkableComponent>(river2);

    controller->AddComponent(r2->shared_from_this());
    controller->AddComponent(r3->shared_from_this());

    controller->Initialize();
    //spdlog::info("model {} Initialized.", controller->GetId());

    controller->Validate();
    //spdlog::info("model {} Validated.", controller->GetId());

    controller->Prepare();
    //spdlog::info("model {} Prepared.", controller->GetId());

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
    //spdlog::info("model {} Finished.", river->GetId());

    river2->Finish();
    //spdlog::info("model {} Finished.", river2->GetId());

    river3->Finish();
    //spdlog::info("model {} Finished.", river3->GetId());
}
