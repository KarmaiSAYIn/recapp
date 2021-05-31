#pragma once
#include "Vec.h"
#include <vector>
#include "Color.h"

class CoordinateTransformer final
{
public:
    CoordinateTransformer(class Graphics& gfx);

    void DrawClosedPolyline(std::vector<Vec2> vertices, Color c);

private:
    class Graphics& gfx;
};

