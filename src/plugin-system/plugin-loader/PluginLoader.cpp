#include "PluginLoader.h"

#include <IPlugin.h>

#include <iostream>

#ifdef SEVENIDE_UNIX
    #include <UnixPluginHandle.h>
#elif defined(SEVENIDE_WINDOWS) // Check if SEVENIDE_WINDOWS is defined
    #include <WindowsPluginHandle.h>
#else
    #error "Either SEVENIDE_LINUX or SEVENIDE_WINDOWS must be defined."
#endif

namespace qts::plugin::loader
{

IPluginHandlePtr LoadPlugin(const std::string& path)
{
    if (path.empty()) {
        return {};
    }
    auto pluginHandle =
#ifdef SEVENIDE_UNIX
        plugin::IPluginHandlePtr(new plugin::UnixPluginHandle(path));
#elif defined SEVENIDE_WINDOWS
        IPluginHandlePtr(new plugin::WindowsPluginHandle(path));
#endif

    auto plugin = pluginHandle->getPlugin();

    try {
        const auto pluginInfo = plugin->getPluginInfo();

        std::cout << "Loaded plugin " << pluginInfo.name << "\n";
        std::cout << "Plugin Version " << pluginInfo.pluginVersion.toString() << "\n";
        std::cout << "For for QuickTurnStudio Version " << pluginInfo.engineVersion.toString() << "\n";
        std::cout << "Provider: " << pluginInfo.vendor << std::endl;
    }
    catch (...) {
        std::cerr << "Exception thrown from plugin" << std::endl;
        return nullptr;
    }

    return pluginHandle;
}

} // namespace qts::plugin::loader
