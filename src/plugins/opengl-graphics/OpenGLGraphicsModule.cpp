#include "OpenGLGraphicsModule.h"

#include "OpenGLCanvas2D.h"

#include <iostream>

qts::graphics::IGraphicsModulePtr getGraphicsModuleInstance()
{
    std::cout << "Creating OpenGLGraphicsModule" << std::endl;
    return qts::base::makeShared<qts::graphics::OpenGLGraphicsModule>();
}

namespace qts::graphics
{

base::SharedPtr<ICanvas2D> OpenGLGraphicsModule::createCanvas2D() const
{
    std::cout << "Creating OpenGL Canvas ..." << std::endl;
    return base::makeShared<OpenGLCanvas2D>();
}

} // namespace qts::graphics
