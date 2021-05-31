#pragma once
#include "Vec.h"
#include <vector>

class Entity
{
public:
    Entity(std::vector<Vec2> model);

    Vec2 GetPos() const;
    void SetPos(Vec2 pos);

    void SetScale(float scale);
    float GetScale() const;

    void Translate(Vec2 offset);

    std::vector<Vec2> GetModel() const;

private:
    float scale = 1.0f;;
    Vec2 pos = { 0.0f, 0.0f };
    std::vector<Vec2> model;
};
