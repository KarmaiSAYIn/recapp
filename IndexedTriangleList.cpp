#include "IndexedTriangleList.h"

IndexedTriangleList::IndexedTriangleList(std::vector<Vec3> verts_in, std::vector<size_t> indices_in)
    :
    vertices(std::move(verts_in)),
    indices(std::move(indices_in))
{
    assert(vertices.size() > 2);
    assert(indices.size() % 3 == 0);
    cullFlags.resize(vertices.size(), false);
}
