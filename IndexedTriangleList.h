#pragma once
#include "Vec.h"
#include <vector>

struct IndexedTriangleList
{
    std::vector<Vec3> vertices;
    std::vector<size_t> indices;
};
