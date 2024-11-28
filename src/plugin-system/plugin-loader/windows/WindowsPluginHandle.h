#pragma once

#include <memory>
#include <string>
#include <windows.h>

#include <PluginHandle.h>

namespace qts::plugin
{

class WindowsPluginHandle : public IPluginHandle
{
public:
    ~WindowsPluginHandle() override;
    explicit WindowsPluginHandle(const std::string& path);

    WindowsPluginHandle(const WindowsPluginHandle&) = delete;
    WindowsPluginHandle& operator = (const WindowsPluginHandle&) = delete;

    WindowsPluginHandle(WindowsPluginHandle&& moveFrom);
    WindowsPluginHandle& operator = (WindowsPluginHandle&& moveFrom);

    [[nodiscard]] IPluginPtr getPlugin() const noexcept override;
    [[nodiscard]] bool hasFunction(const std::string& functionName) override;
    [[nodiscard]] void* getFunctionPointer(const std::string& functionName) override;

private:
    void releaseHandle();

private:
    HMODULE pluginHandle = nullptr;
};

} // namespace qts::plugin
