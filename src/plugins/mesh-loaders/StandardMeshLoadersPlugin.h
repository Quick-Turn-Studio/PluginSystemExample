#pragma once

#include <IPlugin.h>

extern "C" StandardMeshLoaders_API qts::plugin::IPluginPtr getPluginInstance();

namespace qts::meshLoaders
{

class StandardMeshLoadersPlugin : public plugin::IPlugin
{
public:
    ~StandardMeshLoadersPlugin() override = default;
    plugin::PluginInfo getPluginInfo() override;
};

} // namespace qts::graphics
