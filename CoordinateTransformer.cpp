#include "CoordinateTransformer.h"
#include "Graphics.h"

CoordinateTransformer::CoordinateTransformer(Graphics& gfx)
    :
    gfx(gfx)
{}

void CoordinateTransformer::Draw(Drawable& draw) const
{
    auto offset = Vec2((float)Graphics::ScreenWidth / 2, (float)Graphics::ScreenHeight / 2);
    draw.ScaleY(-1.0f);
    draw.Translate(offset);
    draw.Draw(gfx);
}

void CoordinateTransformer::DrawRect(Rectf& rect, Color c) const
{
    auto offset = Vec2((float)Graphics::ScreenWidth / 2, (float)Graphics::ScreenHeight / 2);
    Vec2 topLeft = rect.GetTopLeft();
    Vec2 bottomRight = rect.GetBottomRight();

    topLeft.y *= -1.0f;
    bottomRight.y *= -1.0f;

    rect.Translate(offset);
    gfx.DrawRect(Recti(rect), c);
}
