#include "StandardMeshLoadersPlugin.h"

#include <IMeshLoadersModule.h>

qts::plugin::IPluginPtr getPluginInstance()
{
    return qts::base::makeShared<qts::meshLoaders::StandardMeshLoadersPlugin>();
}

namespace qts::meshLoaders
{

plugin::PluginInfo StandardMeshLoadersPlugin::getPluginInfo()
{
    return {
        .name = "StandardMeshLoadersPlugin",
        .vendor = "Quick Turn Studio",
        .pluginVersion = Version("0.1.0"),
        .engineVersion = Version("1.0.0"),
        // .supportedModules = {meshLoaders::IMeshLoadersModule::moduleName},
    };
}

} // namespace qts::graphics
