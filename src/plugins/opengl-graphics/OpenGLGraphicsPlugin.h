#pragma once

#include <IPlugin.h>

extern "C" OpenGLGraphics_API qts::plugin::IPluginPtr getPluginInstance();

namespace qts::graphics
{

class OpenGLGraphicsPlugin final : public plugin::IPlugin
{
public:
    ~OpenGLGraphicsPlugin() override = default;
    plugin::PluginInfo getPluginInfo() override;
};

} // namespace qts::graphics
