#pragma once

#include <IMeshLoadersModule.h>

extern "C" StandardMeshLoaders_API qts::meshLoaders::IMeshLoadersModulePtr getMeshLoaderModuleInstance();

namespace qts::meshLoaders
{

class StandardMeshLoadersModule : public IMeshLoadersModule
{
public:
    ~StandardMeshLoadersModule() override = default;
    [[nodiscard]] base::Vector<base::SharedPtr<IMeshLoader>> getMeshLoaders() const override;
};

} // namespace qts::graphics
