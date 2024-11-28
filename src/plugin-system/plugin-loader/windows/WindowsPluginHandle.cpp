#include "WindowsPluginHandle.h"

#include <filesystem>
#include <stdexcept>

#include <IPlugin.h>

namespace qts::plugin
{

WindowsPluginHandle::~WindowsPluginHandle()
{
    releaseHandle();
}

WindowsPluginHandle::WindowsPluginHandle(WindowsPluginHandle&& moveFrom)
  : pluginHandle(moveFrom.pluginHandle)
{
    moveFrom.pluginHandle = nullptr;
}

WindowsPluginHandle& WindowsPluginHandle::operator=(WindowsPluginHandle&& moveFrom)
{
    if (&moveFrom == this) {
        return *this;
    }
    releaseHandle();
    pluginHandle = moveFrom.pluginHandle;
    moveFrom.pluginHandle = nullptr;
    return *this;
}

WindowsPluginHandle::WindowsPluginHandle(const std::string& path)
{
    const auto pluginPath = std::filesystem::path(path);

    pluginHandle = LoadLibrary(pluginPath.c_str());

    if (nullptr == pluginHandle) {
        std::stringstream stream;
        stream << "Cannot open library " << path;
        throw std::runtime_error(stream.str());
    }

    typedef IPluginPtr (*func_type)();

    typedef IPluginPtr (*func_type)();
    auto getPluginInstanceFunction = getFunction<func_type>(createInstancePluginFunction);

    if (!getPluginInstanceFunction) {
        std::stringstream stream;
        stream << "Cannot find function \"getPluginInstance()\" in " << path << " library. ";
        stream << "Did you remember about preventing mangling for it? (extern \"C\")?";
        throw std::runtime_error(stream.str());
    }

    plugin = getPluginInstanceFunction();

    if (!plugin) {
        std::stringstream stream;
        stream << "getPluginInstance() from library " << path << " returns empty object";
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
    return GetProcAddress(pluginHandle, functionName.c_str());
}

void WindowsPluginHandle::releaseHandle()
{
    if (nullptr == pluginHandle) {
        return;
    }
    FreeLibrary(pluginHandle);
}

} // namespace qts::plugin
