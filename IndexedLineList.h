#pragma once
#include "Vec.h"
#include <vector>

struct IndexedLineList
{
    std::vector<Vec3> vertices;
    std::vector<size_t> indices;
};
