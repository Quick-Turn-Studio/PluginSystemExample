#pragma once

#include <memory>
#include <string>

#include "UnixPluginHandle.h"
#include <IPluginHandle.h>

namespace qts::plugin
{

class IPlugin;
using IPluginPtr = std::shared_ptr<IPlugin>;

class UnixPluginHandle : public IPluginHandle
{
public:
    ~UnixPluginHandle() override;
    explicit UnixPluginHandle(const std::string& path);

    UnixPluginHandle(const UnixPluginHandle&) = delete;
    UnixPluginHandle& operator = (const UnixPluginHandle&) = delete;

    UnixPluginHandle(UnixPluginHandle&& moveFrom) noexcept ;
    UnixPluginHandle& operator = (UnixPluginHandle&& moveFrom) noexcept ;

    [[nodiscard]] IPluginPtr getPlugin() const noexcept override;
    [[nodiscard]] bool hasFunction(const std::string& functionName) override;
    [[nodiscard]] void* getFunctionPointer(const std::string& functionName) override;

private:
    void releaseHandle();

private:
    void* pluginHandle = nullptr;
    IPluginPtr plugin;
};

} // namespace qts::plugin
