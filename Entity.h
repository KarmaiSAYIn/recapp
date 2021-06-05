#pragma once
#include "Vec.h"
#include "Drawable.h"
#include <vector>

class Entity
{
public:
    Entity(std::vector<Vec2> model, const Vec2& pos = {0.0f, 0.0f}, Color c = Colors::YELLOW);

    Vec2 GetPos() const;
    void SetPos(const Vec2& pos);

    void SetScale(float scale);
    float GetScale() const;

    void Translate(const Vec2& offset);

    Drawable GetDrawable() const;

private:
    Color c;
    float scale = 1.0f;
    Vec2 pos;
    std::vector<Vec2> model;
};
