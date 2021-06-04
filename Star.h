#pragma once
#include <vector>
#include "Entity.h"
#include "Vec.h"
#include "Drawable.h"

class Star final
{
public:
    Star() = default;
    Star(const Star& other);
    Star& operator =(const Star& other);
    Star(Star&& other);
    Star& operator =(Star&& other);
    Star(const Vec2& pos, float outerRadius, float innerRadius, int nFlares = 5);

    Vec2 GetPos() const;
    float GetInnterRadius() const;
    float GetOuterRadius() const;
    Color GetColor() const;

    Drawable GetDrawable() const;

private:
    Color c = Colors::YELLOW;
    float innerRadius = 0.0f;
    float outerRadius = 0.0f;
    Vec2 pos = {0.0f, 0.0f};
    std::vector<Vec2> star;
};
