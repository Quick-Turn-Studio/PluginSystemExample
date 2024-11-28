#include "InfoOnlyPlugin.h"

#include <stdexcept>

qts::plugin::IPluginPtr getPluginInstance()
{
    return std::make_shared<qts::plugin::InfoOnlyPlugin>();
}

namespace qts::plugin
{

PluginInfo InfoOnlyPlugin::getPluginInfo()
{
    // throw std::logic_error("Some exception");

    return {
        .name = "SamplePlugin",
        .vendor = "Quick Turn Studio",
        .pluginVersion = Version("0.1.0"),
        .engineVersion = Version("1.0.0"),
    };
}

} // namespace qts::plugin
