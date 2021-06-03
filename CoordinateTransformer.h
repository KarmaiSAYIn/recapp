#pragma once
#include "Vec.h"
#include <vector>
#include "Drawable.h"
#include "Color.h"

class CoordinateTransformer final
{
public:
    CoordinateTransformer(class Graphics& gfx);

    void Draw(Drawable& draw) const;

private:
    class Graphics& gfx;
};

