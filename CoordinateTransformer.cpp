#include "CoordinateTransformer.h"
#include "Graphics.h"

CoordinateTransformer::CoordinateTransformer(Graphics& gfx)
    :
    gfx(gfx),
    screenOffset((float)Graphics::ScreenWidth / 2, (float)Graphics::ScreenHeight / 2)
{
}

Vec3& CoordinateTransformer::Translate(Vec3& v) const
{
    const float zInverse = 1.0f / v.z;
    v.x = (v.x * zInverse + 1.0f) * screenOffset.x;
    v.y = (-v.y * zInverse + 1.0f) * screenOffset.y;
    return v;
}

Vec3 CoordinateTransformer::GetTranslated(const Vec3& v) const
{
    auto p = Vec3(v);
    return Translate(p);
}

void CoordinateTransformer::Draw(Drawable& draw) const
{
    draw.Transform(
            Mat3::Translate((Vec3)screenOffset) *
            Mat3::FlipY()
            );
    draw.Draw(gfx);
}
