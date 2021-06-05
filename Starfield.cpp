#include "Starfield.h"
#include <random>

Starfield::Starfield(int nWidth, int nHeight, float minRadius, float maxRadius, int minFlares, int maxFlares, int nStarCount)
    :
    minRadius(minRadius),
    maxRadius(maxRadius)
{
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> xDist(-nWidth / 2, nWidth / 2 + 1);
    std::uniform_int_distribution<int> yDist(-nHeight / 2, nHeight / 2 + 1);
    std::uniform_int_distribution<int> flareDist(minFlares, maxFlares + 1);
    std::uniform_int_distribution<int> colorDist(0, 10);
    std::uniform_real_distribution<float> littleRadiusDist(minRadius, std::nextafterf(maxRadius, std::numeric_limits<float>::max()));
    std::uniform_real_distribution<float> bigRadiusDist(minRadius, std::nextafterf(maxRadius, std::numeric_limits<float>::max()));

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
        Colors::INGIDGO,
    };

    float littleRadius;
    float bigRadius;
    int nFlareCount;
    Vec2 pos;
    Color color;

    field.reserve(nStarCount);
    while (field.size() < nStarCount)
    {
        littleRadius = littleRadiusDist(rng);
        bigRadius = bigRadiusDist(rng);
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
    for (auto& star : field)
    {
        auto d = star.GetDrawable();
        camera.Draw(d);
    }
}
