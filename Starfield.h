#pragma once
#include "Vec.h"
#include "CoordinateTransformer.h"
#include "Rect.h"
#include "Entity.h"
#include <vector>

class Starfield final
{
public:
    Starfield(Rectf area, float minRadius, float maxRadius, int minFlares, int maxFlares, int nStarCount = 10);

    void Update(float fElapsedTime);
    void Draw(CoordinateTransformer& transformer) const;

private:
    float minRadius;
    float maxRadius;

    std::vector<Entity> field;
};
