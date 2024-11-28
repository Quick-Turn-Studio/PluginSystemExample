#pragma once

#include <IGraphicsModule.h>

extern "C" OpenGLGraphics_API qts::graphics::IGraphicsModulePtr getGraphicsModuleInstance();

namespace qts::graphics
{

class OpenGLGraphicsModule : public IGraphicsModule
{
public:
    ~OpenGLGraphicsModule() override = default;

    [[nodiscard]] base::SharedPtr<ICanvas2D> createCanvas2D() const override;
};

} // namespace qts::graphics
