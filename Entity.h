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

    float GetRotation() const;
    void SetRotation(const float rotation);

    void SetScale(float scale);
    float GetScale() const;

    void Translate(const Vec2& offset);

    void UpdateRotation();

    Drawable GetDrawable() const;

protected:
    Entity() = default;

    Color GetColor() const;
    void SetColor(Color c);

    const std::vector<Vec2>& GetModel() const;
    std::vector<Vec2> MoveModel();
    void SetModel(std::vector<Vec2> model);

private:
    Color c;
    float scale = 1.0f;
    float rotation = 0.0f;
    Vec2 pos;
    mutable std::vector<Vec2> model;
};
