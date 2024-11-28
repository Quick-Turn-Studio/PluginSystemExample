#include "OpenGLGraphicsPlugin.h"

#include <IGraphicsModule.h>

qts::plugin::IPluginPtr getPluginInstance()
{
    return std::make_shared<qts::graphics::OpenGLGraphicsPlugin>();
}

namespace qts::graphics
{

plugin::PluginInfo OpenGLGraphicsPlugin::getPluginInfo()
{
    return {
        .name = "OpenGLGraphicsPlugin",
        .vendor = "Quick Turn Studio",
        .pluginVersion = Version("0.1.0"),
        .engineVersion = Version("1.0.0"),
        .supportedModules = {IGraphicsModule::moduleName},
    };
}

} // namespace qts::graphics
