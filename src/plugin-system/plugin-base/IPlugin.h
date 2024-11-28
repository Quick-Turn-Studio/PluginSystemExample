#pragma once

#include <memory>

#include "PluginInfo.h"

namespace qts::plugin
{

class IPlugin
{
public:
    virtual ~IPlugin() = default;

    virtual PluginInfo getPluginInfo() = 0;
};

using IPluginPtr = std::shared_ptr<IPlugin>;

} // namespace qts::plugin
