#pragma once

#include <SharedPtr.h>
#include <Vector.h>

namespace qts::meshLoaders
{

class IMeshLoader;

class IMeshLoadersModule;
using IMeshLoadersModulePtr = base::SharedPtr<IMeshLoadersModule>;

class IMeshLoadersModule
{
public:
    typedef IMeshLoadersModulePtr(*functionType)();
    constexpr static auto moduleInstanceFunctionName = "getMeshLoaderModuleInstance";
    constexpr static auto moduleName = "MeshParsers";

    virtual ~IMeshLoadersModule() = default;
    [[nodiscard]] virtual base::Vector<base::SharedPtr<IMeshLoader>> getMeshLoaders() const = 0;
};


}