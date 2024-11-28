#pragma once

#include <memory>

namespace qts::plugin
{
class IPlugin;
using IPluginPtr = std::shared_ptr<IPlugin>;

class IPluginHandle
{
public:
    virtual ~IPluginHandle() = default;
    [[nodiscard]] virtual IPluginPtr getPlugin() const noexcept = 0;
    [[nodiscard]] virtual bool hasFunction(const std::string& functionName) = 0;
    [[nodiscard]] virtual void* getFunctionPointer(const std::string& functionName) = 0;

    constexpr static auto createInstancePluginFunction = "getPluginInstance";

    template<typename FunctionType>
    FunctionType getFunction(const std::string& functionName)
    {
        return reinterpret_cast<FunctionType>(getFunctionPointer(functionName));
    }
};

} // namespace qts::plugin
