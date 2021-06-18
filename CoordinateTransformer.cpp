#include "CoordinateTransformer.h"
#include "Graphics.h"

CoordinateTransformer::CoordinateTransformer(Graphics& gfx)
    :
    gfx(gfx)
{}

void CoordinateTransformer::Draw(Drawable& draw) const
{
    auto offset = Vec2((float)Graphics::ScreenWidth / 2, (float)Graphics::ScreenHeight / 2);
    draw.Transform(
            Mat3::Translate((Vec3)offset) *
            Mat3::FlipY()
            );
    draw.Draw(gfx);
}

void CoordinateTransformer::DrawRect(Rectf& rect, Color c) const
{
    auto offset = Vec2((float)Graphics::ScreenWidth / 2, (float)Graphics::ScreenHeight / 2);
    rect.Translate({0.0f, -rect.GetMiddle().y * 2});
    rect.Translate(offset);
    gfx.DrawRect(Recti(rect), c);
}
