#pragma once
#include "Vec.h"
#include "CoordinateTransformer.h"
#include "Rect.h"
#include "Entity.h"
#include "Camera.h"
#include "Star.h"
#include <vector>

class Starfield final
{
public:
    Starfield() = delete;
    Starfield(const Starfield&) = delete;
    Starfield(Starfield&&) = delete;
    Starfield(int nWidth, int nHeight, float minRadius, float maxRadius, int minFlares, int maxFlares, int nStarCount = 10);

    void Update(float fElapsedTime);
    void Draw(Camera& camera) const;

private:
    float minRadius;
    float maxRadius;

    std::vector<Star> field;
};
