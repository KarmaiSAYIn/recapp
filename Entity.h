#pragma once
#include "Vec.h"
#include "Drawable.h"
#include <vector>

class Entity
{
public:
    Entity(std::vector<Vec2> model, const Vec2& pos = {0.0f, 0.0f}, Color c = Colors::YELLOW);
    virtual ~Entity() = default;

    virtual Vec2 GetPos() const;
    virtual void SetPos(const Vec2 &pos);

    virtual void SetScale(float scale);
    virtual float GetScale() const;

    virtual void Translate(const Vec2& offset);

    virtual Drawable GetDrawable() const;

protected:
    void SetModel(std::vector<Vec2> model) const;

private:
    Color c;
    float scale = 1.0f;
    Vec2 pos;
    mutable std::vector<Vec2> model;
};
