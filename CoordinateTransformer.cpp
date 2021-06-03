#include "CoordinateTransformer.h"
#include "Graphics.h"

CoordinateTransformer::CoordinateTransformer(Graphics& gfx)
    :
    gfx(gfx)
{}

void CoordinateTransformer::Draw(Drawable& draw) const
{
    auto offset = Vec2((float)gfx.GetScreenWidth() / 2, (float)gfx.GetScreenHeight() / 2);
    draw.ScaleY(-1.0f);
    draw.Translate(offset);
    draw.Draw(gfx);
}
