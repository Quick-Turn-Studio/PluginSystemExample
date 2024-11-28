#include <filesystem>
#include <iostream>
#include <string>

#include <IPlugin.h>
#include <PluginLoader.h>
#include <IPluginHandle.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cout << "Provide plugin path to verify" << std::endl;
        return 1;
    }

    const std::string pluginPath = argv[1];

    std::cout << "Starting verification of plugin file: " << pluginPath << "..." << std::endl;
    std::cout << "Verification app can crash if getPluginInstance() function returns invalid type "
                 "or invalid value"
              << pluginPath << std::endl;
    qts::plugin::IPluginPtr plugin;

    try {
        plugin = qts::plugin::loader::LoadPlugin(pluginPath)->getPlugin();
    }

    catch (const std::runtime_error& error) {
        std::cerr << error.what() << std::endl;
        return 2;
    }

    const auto pluginInfo = plugin->getPluginInfo();
    if (pluginInfo.name.empty()) {
        std::cerr << "Plugin name cannot be empty" << std::endl;
        return 3;
    }
    if (pluginInfo.vendor.empty()) {
        std::cerr << "Plugin vendor cannot be empty" << std::endl;
        return 4;
    }

    std::cout << "Plugin \"" << plugin->getPluginInfo().name << "\" verified successfully"
              << std::endl;

    return 0;
}