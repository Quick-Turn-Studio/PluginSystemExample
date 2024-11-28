#pragma once

#include "Version.h"

#include <BaseString.h>
#include <Vector.h>

namespace qts::plugin
{

struct PluginInfo
{
    base::String name;
    base::String vendor;
    Version pluginVersion;
    Version engineVersion;
    base::Vector<base::String> supportedModules;
};

} // namespace qts::plugin
