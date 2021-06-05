#include "Star.h"

Star::Star(const Star& other)
{
    *this = other;
}

Star& Star::operator =(const Star& other)
{
    c = other.c;
    innerRadius = other.innerRadius;
    outerRadius = other.outerRadius;
    pos = other.pos;
    star = other.star;
    return *this;
}

Star::Star(Star&& other)
{
    *this = other;
}

Star& Star::operator =(Star&& other)
{
    return *this = other;
}


Star::Star(const Vec2& pos, float outerRadius, float innerRadius, int nFlares, Color c)
    :
    c(c),
    innerRadius(innerRadius),
    outerRadius(outerRadius),
    pos(pos)
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

