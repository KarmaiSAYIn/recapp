#pragma once
#include "Vec.h"
#include <vector>
#include "Drawable.h"
#include "Color.h"
#include "Rect.h"

class CoordinateTransformer final
{
public:
    CoordinateTransformer(class Graphics& gfx);

    Vec3& Translate(Vec3& v) const;
    Vec3 GetTranslated(const Vec3& v) const;
    void Draw(Drawable& draw) const;

private:
    class Graphics& gfx;
    Vec3 screenOffset;
};
