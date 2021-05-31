#include "CoordinateTransformer.h"
#include "Graphics.h"

CoordinateTransformer::CoordinateTransformer(Graphics& gfx)
    :
    gfx(gfx)
{}

void CoordinateTransformer::DrawClosedPolyline(std::vector<Vec2> vertices, Color c)
{
    auto offset = Vec2((float)gfx.GetScreenWidth() / 2, (float)gfx.GetScreenHeight() / 2);
    for (auto& v : vertices)
    {
        v.y *= -1.0f;
        v += offset;
    }
    gfx.DrawClosedPolyline(vertices, c);
}
