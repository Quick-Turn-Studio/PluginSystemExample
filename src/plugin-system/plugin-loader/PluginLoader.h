#pragma once

#include <memory>
#include <string>

namespace qts::plugin
{
class IPluginHandle;
using IPluginHandlePtr = std::shared_ptr<IPluginHandle>;

namespace loader
{
IPluginHandlePtr LoadPlugin(const std::string& path);
}
}; // namespace qts::plugin
