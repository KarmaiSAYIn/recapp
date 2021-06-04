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

    void Draw(Drawable& draw) const;
    void DrawRect(Rectf& rect, Color c) const;

private:
    class Graphics& gfx;
};
