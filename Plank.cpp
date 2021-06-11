#include "Plank.h"
#include "Keyboard.h"
#include <algorithm>

Plank::Plank(const Vec2& anchorPos, float freeX, int nMinY, int nMaxY, int nThickness, float fSpeed, Color c)
    :
    Entity({}, anchorPos, c),
    nMinY(nMinY - anchorPos.y),
    nMaxY(nMaxY - anchorPos.y),
    nThickness(nThickness),
    fSpeed(fSpeed),
    freePos(freeX - anchorPos.x, nMinY)
{
}

std::pair<Vec2, Vec2> Plank::GetPoints() const
{
    return std::make_pair(freePos, GetPos());
}

void Plank::Update(float fElapsedTime, Keyboard& keyboard)
{
    float delta = 0.0f;
    if (keyboard.KeyIsPressed(Keyboard::Key::W))
        delta += 1.0f;

    if (keyboard.KeyIsPressed(Keyboard::Key::S))
        delta -= 1.0f;

    freePos.y = std::clamp(freePos.y + delta * fSpeed * fElapsedTime - GetPos().y, (float)nMinY, (float)nMaxY);
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

