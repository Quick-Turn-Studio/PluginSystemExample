#pragma once

#include <ICanvas2D.h>

namespace qts::graphics
{

class OpenGLCanvas2D final : public ICanvas2D
{
public:
    ~OpenGLCanvas2D() override = default;

    void flush() override;
    void drawCircle(float x, float y, float radius) override;
    void drawRectangle(float x, float y, float width, float height) override;
};

} // namespace qts::graphics
