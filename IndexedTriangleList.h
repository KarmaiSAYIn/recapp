#pragma once
#include "Vec.h"
#include <vector>

struct IndexedTriangleList
{
    IndexedTriangleList(std::vector<Vec3> vertices, std::vector<size_t> indices);

    std::vector<Vec3> vertices;
    std::vector<size_t> indices;
    std::vector<bool> cullFlags;
};
