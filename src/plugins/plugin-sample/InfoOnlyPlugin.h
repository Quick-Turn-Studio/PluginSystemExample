#pragma once

#include <IPlugin.h>

extern "C"
PluginSample_API qts::plugin::IPluginPtr getPluginInstance();

namespace qts::plugin
{
class InfoOnlyPlugin : public IPlugin
{
public:
    ~InfoOnlyPlugin() override = default;
    PluginInfo getPluginInfo() override;
};

} // namespace qts::plugin
