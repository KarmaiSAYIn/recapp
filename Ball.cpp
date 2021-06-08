#include "Ball.h"

Ball::Ball(Vec2 pos, Vec2 velocity, float radius, Color c)
    :
    Entity(Star::Make(radius, radius, 15), pos, c),
    velocity(velocity),
    radius(radius)
{
}

Ball::Ball(const Ball& other)
    :
    Entity(other.GetModel(), other.GetPos(), other.GetColor()),
    velocity(other.velocity)
{
}

Ball& Ball::operator =(const Ball& other)
{
    SetModel(other.GetModel());
    SetPos(other.GetPos());
    SetColor(other.GetColor());
    velocity = other.velocity;
    return *this;
}

Ball::Ball(Ball&& other)
    :
    Entity(other.MoveModel(), other.GetPos(), other.GetColor()),
    velocity(std::move(other.velocity))
{
}

Ball& Ball::operator =(Ball&& other)
{
    SetModel(other.MoveModel());
    SetPos(other.GetPos());
    SetColor(other.GetColor());
    velocity = other.velocity;
    return *this;
}

float Ball::GetRadius() const
{
    return radius;
}

void Ball::Update(float fElapsedTime)
{
    Translate(velocity * fElapsedTime);
}

