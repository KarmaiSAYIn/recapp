#include "Entity.h"

Entity::Entity(std::vector<Vec2> model, Vec2 pos)
    :
    pos(pos),
    model(std::move(model))
{
}

Vec2 Entity::GetPos() const
{
    return pos;
}

void Entity::SetPos(Vec2 pos)
{
    this->pos = pos;
}

void Entity::SetScale(float scale)
{
    this->scale = scale;
}

float Entity::GetScale() const
{
    return scale;
}

void Entity::Translate(Vec2 offset)
{
    pos += offset;
}

std::vector<Vec2> Entity::GetModel() const
{
    auto poly = model;
    for (auto& v : poly)
    {
        v *= scale;
        v += pos;
    }
    return poly;
}
