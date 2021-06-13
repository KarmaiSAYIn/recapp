#include "Star.h"

Star::Star(const Star& other)
{
    *this = other;
}

Star& Star::operator =(const Star& other)
{
    SetColor(other.GetColor());
    innerRadius = other.innerRadius;
    outerRadius = other.outerRadius;
    SetModel(other.GetModel());
    return *this;
}

Star::Star(Star&& other)
{
    *this = other;
}

Star& Star::operator =(Star&& other)
{
    SetColor(other.GetColor());
    innerRadius = other.innerRadius;
    outerRadius = other.outerRadius;
    SetModel(other.MoveModel());
    return *this;
}

Star::Star(const Vec2& pos, float outerRadius, float innerRadius, float rotationSpeed, int nFlares, Color c)
    :
    Entity(Make(outerRadius, innerRadius, nFlares), pos, c),
    innerRadius(innerRadius),
    outerRadius(outerRadius),
    rotationSpeed(rotationSpeed)
{
}

std::vector<Vec2> Star::Make(float outerRadius, float innerRadius, int nFlares)
{
    std::vector<Vec2> star;
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
    return star;
}

Rectf Star::GetRect() const
{
    const float fWidth = outerRadius * 2;
    return Rectf(GetPos(), fWidth, fWidth);
}

float Star::GetInnerRadius() const
{
    return innerRadius;
}

float Star::GetOuterRadius() const
{
    return outerRadius;
}

//Color Star::GetColor() const
//{
    //return GetColor();
//}

void Star::Update(float fElapsedTime)
{
    time += fElapsedTime;
    UpdateRotation();
}

Drawable Star::GetDrawable() const
{
    Drawable d(GetModel(), GetColor());
    d.Rotate(GetRotation());
    d.Translate(GetPos());
    return d;
}

void Star::UpdateRotation()
{
    SetRotation(rotationSpeed * time);
}
