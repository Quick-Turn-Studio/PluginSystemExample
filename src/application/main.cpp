#include <IGraphicsModule.h>
#include <IMeshLoadersModule.h>
#include <IPlugin.h>
#include <IPluginHandle.h>
#include <PluginLoader.h>

#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

using namespace qts;

std::vector<plugin::IPluginHandlePtr> loadPlugins(const std::string& directory) noexcept
{
    const auto directoryPath = std::filesystem::path(directory);
    if (!std::filesystem::exists(directoryPath)) {
        std::cerr << "Directory " << directory << " does not exists" << std::endl;
        return {};
    }

    std::vector<plugin::IPluginHandlePtr> loadedPlugins;

    for (const auto& file : std::filesystem::directory_iterator(directoryPath)) {
        std::cout << "Considering " << file << std::endl;
        if (!file.is_regular_file()) {
            std::cout << file << " is not regular file" << std::endl;
            continue;
        }
        try {
            auto pluginHandle = plugin::loader::LoadPlugin(std::string(file.path()));
            loadedPlugins.emplace_back(std::move(pluginHandle));
        }
        catch (const std::runtime_error& error) {
            std::cerr << error.what() << std::endl;
        }
    }

    return loadedPlugins;
}

int main(int argc, char* argv[])
{
    std::string pluginsDir = argv[0];

    const auto applicationPath = std::filesystem::path(argv[0]);
    const auto applicationDirectory = applicationPath.parent_path();
    const auto pluginsDirectory = applicationDirectory / "plugins";

    auto plugins = loadPlugins(pluginsDirectory);

    std::vector<graphics::IGraphicsModulePtr> graphicsModules;
    std::vector<meshLoaders::IMeshLoadersModulePtr> meshParserModule;

    for (const auto& plugin : plugins) {
        const auto pluginInfo = plugin->getPlugin()->getPluginInfo();
        for (const auto& module : pluginInfo.supportedModules) {
            if (module == graphics::IGraphicsModule::moduleName) {
                auto moduleInstance = plugin->getFunction<graphics::IGraphicsModule::functionType>(
                    graphics::IGraphicsModule::moduleInstanceFunctionName)();
                graphicsModules.emplace_back(std::move(moduleInstance));
            }
            else if (module == meshLoaders::IMeshLoadersModule::moduleName) {
                auto moduleInstance = plugin->getFunction<meshLoaders::IMeshLoadersModule::functionType>(
                    graphics::IGraphicsModule::moduleInstanceFunctionName)();
                meshParserModule.emplace_back(std::move(moduleInstance));
            }
        }
    }

    if (!graphicsModules.empty()) {
        if (graphicsModules.front() != nullptr) {
        auto canvas = graphicsModules.front()->createCanvas2D();
        }
    }


    graphicsModules.clear();
    meshParserModule.clear();


    std::cout << "Hello World" << std::endl;
    std::cout << pluginsDir << std::endl;

    return 0;
}
