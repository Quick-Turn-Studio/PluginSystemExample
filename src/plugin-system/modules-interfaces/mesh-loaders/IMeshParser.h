#pragma once

#include <Vector.h>
#include <BaseString.h>

#include "Mesh.h"

namespace qts::meshLoaders
{

class IMeshLoader
{
public:
    virtual ~IMeshLoader() = default;

    [[nodiscard]] virtual base::Vector<base::String> getSupportedFormats() const = 0;
    [[nodiscard]] virtual Mesh importMesh(const std::string* path) = 0;
    [[nodiscard]] virtual bool exportMesh(const Mesh& mesh, const std::string* path) = 0;
};

}