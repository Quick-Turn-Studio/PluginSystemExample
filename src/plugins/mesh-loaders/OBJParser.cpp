#include "OBJParser.h"

namespace qts::meshLoaders
{

base::Vector<base::String> ObjParser::getSupportedFormats() const
{
    return {"obj"};
}

Mesh ObjParser::importMesh(const std::string* path)
{
    return {};
}

bool ObjParser::exportMesh(const Mesh& mesh, const std::string* path)
{
    return true;
}

} // namespace qts::meshLoaders
