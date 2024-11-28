#pragma once

#include <SharedPtr.h>

namespace qts::graphics
{

class ICanvas2D;

class IGraphicsModule;
using IGraphicsModulePtr = base::SharedPtr<IGraphicsModule>;

class IGraphicsModule
{
public:
    typedef IGraphicsModulePtr(*functionType)();
    constexpr static auto moduleInstanceFunctionName = "getGraphicsModuleInstance";
    constexpr static auto moduleName = "Graphics";

    virtual ~IGraphicsModule() = default;
    [[nodiscard]] virtual base::SharedPtr<ICanvas2D> createCanvas2D() const = 0;
};


} // namespace qts::graphics
