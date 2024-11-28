#pragma once

#include <Vector.h>
#include <Array.h>

#include "Vector2.h"
#include "Vector3.h"

namespace qts::meshLoaders
{

struct FaceVertex
{
    int vertexIndex = -1;
    int normalIndex = -1;
    int uvIndex = -1;
};

struct Triangle
{
    base::Array<FaceVertex, 3> faces;
};

struct Mesh
{
    base::Vector<Vector3> vertices;
    base::Vector<Vector3> normals;
    base::Vector<Vector2> uv;

    base::Vector<Triangle> triangles;
};

}
