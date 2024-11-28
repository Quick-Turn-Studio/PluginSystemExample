#include "StandardMeshLoadersModule.h"

#include <iostream>

#include "OBJParser.h"

qts::meshLoaders::IMeshLoadersModulePtr getMeshLoaderModuleInstance()
{
    // std::cout << "Creating StandardMeshLoadersModule" << std::endl;
    return qts::base::makeShared<qts::meshLoaders::StandardMeshLoadersModule>();
}

namespace qts::meshLoaders
{

base::Vector<base::SharedPtr<IMeshLoader>> StandardMeshLoadersModule::getMeshLoaders() const
{
    return {};
    // return {base::makeShared<ObjParser>()};
}

} // namespace qts::meshLoaders
