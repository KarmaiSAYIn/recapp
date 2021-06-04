#include "Starfield.h"
#include "Star.h"
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
    std::uniform_int_distribution<int> colorDist(0, 11);
    std::uniform_real_distribution<float> radiusDist(minRadius, std::nextafterf(maxRadius, std::numeric_limits<float>::max()));

    Color colors[10] = {
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

    field.reserve(nStarCount);
    for (int i = 0; i < nStarCount; i++)
    {
        field.emplace_back(Star::Make(radiusDist(rng), radiusDist(rng), flareDist(rng)), Vec2((float)xDist(rng), (float)yDist(rng)), colors[colorDist(rng)]);
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
