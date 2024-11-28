#pragma once

#include <IMeshParser.h>

namespace qts::meshLoaders
{

class ObjParser final : public IMeshLoader
{
public:
    ~ObjParser() override = default;

    [[nodiscard]] base::Vector<base::String> getSupportedFormats() const override;
    [[nodiscard]] Mesh importMesh(const std::string* path) override;
    [[nodiscard]] bool exportMesh(const Mesh& mesh, const std::string* path) override;
};

} // namespace qts::meshLoaders
