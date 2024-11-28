#pragma once

namespace qts::graphics
{

class ICanvas2D
{
public:
    virtual ~ICanvas2D() = default;
    virtual void flush() = 0;
    virtual void drawCircle(float x, float y, float radius) = 0;
    virtual void drawRectangle(float x, float y, float width, float height) = 0;
};

}