#include "Starfield.h"
#include <random>

Starfield::Starfield(int nWidth, int nHeight, float minRadius, float maxRadius, unsigned minFlares, unsigned maxFlares, unsigned nStarCount)
    :
    minRadius(minRadius),
    maxRadius(maxRadius)
{
    if (minFlares > maxFlares)
        std::swap(minFlares, maxFlares);

    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> xDist(-nWidth / 2, nWidth / 2 + 1);
    std::uniform_int_distribution<int> yDist(-nHeight / 2, nHeight / 2 + 1);
    std::uniform_int_distribution<int> flareDist(minFlares, maxFlares + 1);
    std::uniform_int_distribution<int> colorDist(0, 10);
    std::uniform_real_distribution<float> radiusDist(minRadius, std::nextafterf(maxRadius, std::numeric_limits<float>::max()));

    Color colors[] = {
        Colors::BLUE,
        Colors::RED,
        Colors::YELLOW,
        Colors::GREEN,
        Colors::CYAN,
        Colors::PURPLE,
        Colors::MAGENTA,
        Colors::ORANGE,
        Colors::PLUM,
        Colors::INDIGO,
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

        if (std::any_of(field.begin(), field.end(), [&](const Star& star){ return ((star.GetPos() - pos).GetDistance() < (bigRadius + star.GetOuterRadius())); }))
            continue;

        nFlareCount = flareDist(rng);
        color = colors[colorDist(rng)];
        
        field.emplace_back(pos, bigRadius, littleRadius, nFlareCount, color);
    }
}


void Starfield::Update(float fElapsedTime)
{
}

void Starfield::Draw(Camera& camera) const
{
    Rectf viewPort = camera.GetRect();

    for (auto& star : field)
    {
        if (viewPort.CollideRect(star.GetRect()))
        {
            auto d = star.GetDrawable();
            camera.Draw(d);
        }
    }
}
