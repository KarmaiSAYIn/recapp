#pragma once
#include "Entity.h"
#include "Star.h"
#include <iostream>

class Ball : public Entity
{
public:
    Ball() = delete;
    Ball(Vec2 pos, Vec2 velocity, float radius, Color c = Colors::RED);
    Ball(const Ball& other);
    Ball& operator =(const Ball& other);
    Ball(Ball&& other);
    Ball& operator =(Ball&& other);

    float GetRadius() const;

    Vec2 GetVelocity() const;
    void SetVelocity(const Vec2& velocity);

    void Update(float fElapsedTime);

private:
    Vec2 velocity = {0.0f, 0.0f};
    float radius;
};
