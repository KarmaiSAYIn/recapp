#include "Starfield.h"
#include "Star.h"
#include <random>

Starfield::Starfield(Rectf area, float minRadius, float maxRadius, int minFlares, int maxFlares, int nStarCount)
    :
    minRadius(minRadius),
    maxRadius(maxRadius)
{
    std::random_device rd;    
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> xDist(area.GetLeft(), area.GetRight() + 1);
    std::uniform_int_distribution<int> yDist(area.GetBottom(), area.GetTop() + 1);
    std::uniform_int_distribution<int> flareDist(minFlares, maxFlares + 1);
    std::uniform_int_distribution<int> colorDist(0, 256);
    std::uniform_real_distribution<float> radiusDist(minRadius, std::nextafterf(maxRadius, std::numeric_limits<float>::max()));

    field.reserve(nStarCount);
    for (int i = 0; i < nStarCount; i++)
    {
        Entity newEntity(Star::Make(radiusDist(rng), radiusDist(rng), flareDist(rng)), Vec2(xDist(rng), yDist(rng)), colorDist(rng));
        if (i > 0)
        {
            //Make sure the new Entity isn't colliding with previous ones.
        }

        field.push_back(newEntity);
    }
}

void Starfield::Update(float fElapsedTime)
{
}

void Starfield::Draw(CoordinateTransformer& transformer) const
{
    for (auto& star : field)
    {
        auto d = star.GetDrawable();
        transformer.Draw(d);
    }
}
