#include "Star.h"

Star::Star(const Star& other)
{
    *this = other;
}

Star& Star::operator =(const Star& other)
{
    return *this = Star(other);
}

Star::Star(Star&& other)
{
    *this = std::move(other);
}

Star& Star::operator =(Star&& other)
{
    c = std::move(other.c);
    innerRadius = std::move(other.innerRadius);
    outerRadius = std::move(other.outerRadius);
    pos = std::move(other.pos);
    star = std::move(other.star);
    return *this;
}


Star::Star(const Vec2& pos, float outerRadius, float innerRadius, int nFlares, Color c)
    :
    pos(pos),
    outerRadius(outerRadius),
    innerRadius(innerRadius),
    c(c)
{
    star.reserve(nFlares * 2);
    const float dTheta = 2.0f * 3.14159f / float(nFlares * 2);
    for (int i = 0; i < nFlares * 2; i++)
    {
        const float rad = (i % 2 == 0) ? outerRadius : innerRadius;
        star.emplace_back(
            rad * cos(float(i) * dTheta),
            rad * sin(float(i) * dTheta)
        );
    }
}

Vec2 Star::GetPos() const
{
    return pos;
}


float Star::GetInnerRadius() const
{
    return innerRadius;
}

float Star::GetOuterRadius() const
{
    return outerRadius;
}

Color Star::GetColor() const
{
    return c;
}

Drawable Star::GetDrawable() const
{
    Drawable d(star, c);
    d.Translate(pos);
    return d;
}

