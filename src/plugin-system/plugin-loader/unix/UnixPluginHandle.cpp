#include "UnixPluginHandle.h"

#include <dlfcn.h>
#include <IPlugin.h>

#include <filesystem>
#include <stdexcept>

namespace qts::plugin
{

UnixPluginHandle::~UnixPluginHandle()
{
    releaseHandle();
}

UnixPluginHandle::UnixPluginHandle(UnixPluginHandle&& moveFrom) noexcept
    : pluginHandle(moveFrom.pluginHandle)
{
    moveFrom.pluginHandle = nullptr;
}

UnixPluginHandle& UnixPluginHandle::operator=(UnixPluginHandle&& moveFrom) noexcept
{
    if (&moveFrom == this) {
        return *this;
    }
    releaseHandle();
    pluginHandle = moveFrom.pluginHandle;
    moveFrom.pluginHandle = nullptr;
    return *this;
}

UnixPluginHandle::UnixPluginHandle(const std::string& path)
{
    const auto pluginPath = std::filesystem::path(path);

    pluginHandle = dlopen(pluginPath.c_str(), RTLD_LAZY | RTLD_GLOBAL);

    if (nullptr == pluginHandle) {
        std::stringstream stream;
        stream << "Cannot open library " << path << ". Error: " << dlerror() << std::endl;
        throw std::runtime_error(stream.str());
    }

    typedef IPluginPtr (*func_type)();
    auto getPluginInstanceFunction = getFunction<func_type>(createInstancePluginFunction);

    if (nullptr == getPluginInstanceFunction) {
        std::stringstream stream;
        stream << "Cannot find function \"getPluginInstance()\" in " << path << " library. ";
        stream << "Did you remember about preventing mangling for it? (extern \"C\")?";
        throw std::runtime_error(stream.str());
    }

    plugin = getPluginInstanceFunction();

    if (!plugin) {
        std::stringstream stream;
        stream << "getPluginInstance() from library " << path << " returns empty object" << '\n';
        stream << "Error: " << dlerror();
        throw std::runtime_error(stream.str());
    }

    const auto pluginInfo = plugin->getPluginInfo();

    if (pluginInfo.name.empty()) {
        std::stringstream stream;
        stream << "Plugin " << path << " has no name";
        throw std::runtime_error(stream.str());
    }

    if (pluginInfo.vendor.empty()) {
        std::stringstream stream;
        stream << "Plugin " << path << " has no vendor";
        throw std::runtime_error(stream.str());
    }
}

IPluginPtr UnixPluginHandle::getPlugin() const noexcept
{
    return plugin;
}

bool UnixPluginHandle::hasFunction(const std::string& functionName)
{
    return getFunctionPointer(functionName) != nullptr;
}

void* UnixPluginHandle::getFunctionPointer(const std::string& functionName)
{
    dlerror(); // cleaning previous errors
    return dlsym(pluginHandle, functionName.c_str());
}

void UnixPluginHandle::releaseHandle()
{
    plugin.reset();
    if (nullptr == pluginHandle) {
        return;
    }
    dlclose(pluginHandle);
}

} // namespace qts::plugin
