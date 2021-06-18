#include "Starfield.h"
#include "Math.h"
#include <random>

Starfield::Starfield(int nWidth, int nHeight, float minRadius, float maxRadius, float minRotation, float maxRotation, unsigned minFlares, unsigned maxFlares, unsigned nStarCount)
{
    if (minFlares > maxFlares)
        std::swap(minFlares, maxFlares);

    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> xDist(-nWidth / 2, nWidth / 2 + 1);
    std::uniform_int_distribution<int> yDist(-nHeight / 2, nHeight / 2 + 1);
    std::uniform_int_distribution<int> flareDist(minFlares, maxFlares + 1);
    std::uniform_int_distribution<int> colorDist(0, 10);
    std::uniform_real_distribution<float> radiusDist(minRadius, std::nextafterf(maxRadius, std::numeric_limits<float>::max()));
    std::uniform_real_distribution<float> rotationDist(minRotation, std::nextafterf(maxRotation, std::numeric_limits<float>::max()));

    Color colors[] = {
        Colors::Blue,
        Colors::Red,
        Colors::Yellow,
        Colors::Green,
        Colors::Cyan,
        Colors::Purple,
        Colors::Magenta,
        Colors::Orange,
        Colors::Plum,
        Colors::Indigo,
    };

    float littleRadius;
    float bigRadius;
    int nFlareCount;
    Vec2 pos;
    Color color;

    field.reserve(nStarCount);
    while (field.size() < nStarCount)
    {
        littleRadius = radiusDist(rng);
        bigRadius = radiusDist(rng);
        pos = Vec2((float)xDist(rng), (float)yDist(rng));
        
        if (bigRadius < littleRadius)
            std::swap(bigRadius, littleRadius);

        if (std::any_of(field.begin(), field.end(), [&](const Star& star){ return ((star.GetPos() - pos).GetDistanceSq() < sq(bigRadius + star.GetOuterRadius())); }))
            continue;

        nFlareCount = flareDist(rng);
        color = colors[colorDist(rng)];
        
        field.emplace_back(pos, bigRadius, littleRadius, rotationDist(rng), nFlareCount, color);
    }
}


void Starfield::Update(float fElapsedTime)
{
    for (auto& star : field)
    {
        star.Update(fElapsedTime);
    }
}

void Starfield::Draw(Camera& camera) const
{
    const auto cameraRect = camera.GetRect();
    const Vec2 cameraViewDiag = {cameraRect.GetWidth(), cameraRect.GetHeight()};
    const float cameraViewRadiusSq = sq(cameraViewDiag.x) + sq(cameraViewDiag.y);

    for (auto& star : field)
    {
        if ((camera.GetPos() - star.GetPos()).GetDistanceSq() < cameraViewRadiusSq + sq(star.GetOuterRadius()))
        {
            auto d = star.GetDrawable();
            camera.Draw(d);
        }
    }
}
