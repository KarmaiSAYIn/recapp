#pragma once
#include <vector>
#include "Entity.h"
#include "Vec.h"
#include "Drawable.h"
#include "Rect.h"

class Star final
{
public:
    Star() = default;
    Star(const Star& other);
    Star& operator =(const Star& other);
    Star(Star&& other);
    Star& operator =(Star&& other);
    Star(const Vec2& pos, float outerRadius, float innerRadius, int nFlares = 5, Color c = Colors::YELLOW);

    Vec2 GetPos() const;
    Rectf GetRect() const;
    float GetInnerRadius() const;
    float GetOuterRadius() const;
    Color GetColor() const;

    Drawable GetDrawable() const;

private:
    Color c;
    float innerRadius = 0.0f;
    float outerRadius = 0.0f;
    Vec2 pos = {0.0f, 0.0f};
    mutable std::vector<Vec2> star;
};
