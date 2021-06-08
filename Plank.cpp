#include "Plank.h"
#include "Keyboard.h"
#include <algorithm>

Plank::Plank(const Vec2& anchorPos, float freeX, int nMinY, int nMaxY, int nThickness, float fSpeed, Color c)
    :
    Entity({}, anchorPos, c),
    nMinY(nMinY - anchorPos.y),
    nMaxY(nMaxY - anchorPos.y),
    freePos(freeX - anchorPos.x, nMinY),
    nThickness(nThickness),
    fSpeed(fSpeed)
{
}

Vec2 Plank::GetPos() const
{
    return Entity::GetPos();
}

void Plank::SetPos(const Vec2 &pos)
{
    Entity::SetPos(pos);
}

void Plank::SetScale(float scale)
{
    Entity::SetScale(scale);
}

float Plank::GetScale() const
{
    return Entity::GetScale();
}
void Plank::Translate(const Vec2& offset)
{
    Entity::Translate(offset);
}

void Plank::Update(float fElapsedTime, Keyboard& keyboard)
{
    float delta = 0.0f;
    if (keyboard.KeyIsPressed(Keyboard::Key::W))
        delta = 1.0f;

    if (keyboard.KeyIsPressed(Keyboard::Key::S))
        delta = -1.0f;

    freePos.y = std::clamp(freePos.y + delta * fSpeed *fElapsedTime - GetPos().y, (float)nMinY, (float)nMaxY);
}

Drawable Plank::GetDrawable() const
{
    std::vector<Vec2> model;
    model.reserve(4);
    model.emplace_back(0.0f, 0.0f);
    model.push_back(freePos);
    model.push_back(freePos + Vec2(0.0f, (float)nThickness));
    model.emplace_back(0.0f, (float)nThickness);
    Entity::SetModel(std::move(model));
    return Entity::GetDrawable();
}

