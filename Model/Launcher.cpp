/** ***********************************************************************************
 *    Copyright (C) 2022~2024, All OpenOasis Contributors. Join us on this journey!
 *
 *    @File      :  Launcher.cpp
 *    @License   :  Apache-2.0
 *
 *    @Desc      :  OpenOasis component launcher.
 *
 ** ***********************************************************************************/
#include "Model/CommImp/DevSupports/IterationController.h"
#include "Model/CommImp/IO/Logger.h"
#include "Model/CommImp/IO/LinkLoader.h"
#include "Model/Utils/LibraryLoader.h"
#include "ThirdPart/Args/args.hxx"
#include <iostream>
#include <thread>
#include <iomanip>


using namespace OpenOasis;
using namespace CommImp;
using namespace Utils;
using namespace std;


int main(int argc, const char *argv[])
{
    args::ArgumentParser parser("OpenOasis component launcher");
    args::HelpFlag       help(parser, "", "OpenOasis help menu", {'h', "help"});

    args::Positional<std::string> configFile(
        parser, "conf", "Path to the link configuration json file");

    args::ValueFlag<string> logLevel(
        parser, "", "Log level (debug, info, warn, err)", {"log"});

    try
    {
        parser.ParseCLI(argc, argv);
    }
    catch (const args::Error &e)
    {
        cerr << e.what() << endl;
        cerr << parser;
        return 1;
    }

    string logLevelStr = "info";
    if (logLevel)
    {
        auto logger = IO::GetLogger();
        logger->set_level(spdlog::level::from_str(logLevelStr));
    }

    string configFilePath;
    if (configFile)
    {
        configFilePath = configFile.Get();
    }
    else
    {
        configFilePath = "config.json";
    }

    IO::LinkLoader linkLoader(configFilePath);
    linkLoader.Load();

    return 0;
}
