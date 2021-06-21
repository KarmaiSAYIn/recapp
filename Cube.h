#pragma once
#include "Vec.h"
#include "IndexedLineList.h"
#include "IndexedTriangleList.h"
#include <vector>

class Cube
{
public:
    Cube(float size)
    {
        const float side = size / 2.0f;
        model.emplace_back(-side, -side, -side);
        model.emplace_back(side, -side, -side);
        model.emplace_back(-side, side, -side);
        model.emplace_back(side, side, -side);

        model.emplace_back(-side, -side, side);
        model.emplace_back(side, -side, side);
        model.emplace_back(-side, side, side);
        model.emplace_back(side, side, side);
    }

    IndexedLineList GetLines()
    {
        return {
            model,
            {
                0,1, 1,3, 3,2, 2,0,
                0,4, 1,5, 2,6, 3,7,
                4,5, 5,7, 7,6, 6,4
            }
        };
    }

    IndexedTriangleList GetTriangles()
    {
        return
        {
            model,
            {
                0,2,1, 2,3,1,
                1,3,5, 3,7,5,
                2,6,3, 3,6,7,
                4,5,7, 4,7,6,
                0,4,2, 2,4,6,
                0,1,4, 1,5,4
            }
        };
    }

private:
    std::vector<Vec3> model;
};
