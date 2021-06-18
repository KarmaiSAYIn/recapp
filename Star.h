#pragma once
#include <vector>
#include "Entity.h"
#include "Vec.h"
#include "Drawable.h"
#include "Rect.h"

class Star : public Entity
{
public:
    Star() = default;
    Star(const Star& other);
    Star& operator =(const Star& other);
    Star(Star&& other);
    Star& operator =(Star&& other);
    Star(const Vec2& pos, float outerRadius, float innerRadius, float rotationSpeed, int nFlares = 5, Color c = Colors::Yellow);

    static std::vector<Vec2> Make(float outerRadius, float innerRadius, int nFlares = 5);

    Rectf GetRect() const;
    float GetInnerRadius() const;
    float GetOuterRadius() const;
    //Color GetColor() const;

    void Update(float fElapsedTime);

    Drawable GetDrawable() const;

private:
    void UpdateRotation();

private:
    float innerRadius = 0.0f;
    float outerRadius = 0.0f;
    float rotation = 0.0f;
    const float rotationSpeed = 0.0f;
    float time = 0.0f;
};
