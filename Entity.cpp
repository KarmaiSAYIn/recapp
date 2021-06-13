#include "Entity.h"

Entity::Entity(std::vector<Vec2> model, const Vec2& pos, Color c)
    :
    c(c),
    pos(pos),
    model(std::move(model))
{
}

Vec2 Entity::GetPos() const
{
    return pos;
}

void Entity::SetPos(const Vec2& pos)
{
    this->pos = pos;
}

float Entity::GetRotation() const
{
    return rotation;
}

void Entity::SetRotation(const float rotation)
{
    this->rotation = rotation;
}

void Entity::SetScale(float scale)
{
    this->scale = scale;
}

float Entity::GetScale() const
{
    return scale;
}

void Entity::Translate(const Vec2& offset)
{
    pos += offset;
}

Drawable Entity::GetDrawable() const
{
   Drawable r(model, c);
   r.Scale(scale);
   r.Translate(pos);
   return r;
}

Color Entity::GetColor() const
{
    return c;
}

void Entity::SetColor(Color c)
{
    this->c = c;
}

const std::vector<Vec2>& Entity::GetModel() const
{
    return model;
}

std::vector<Vec2> Entity::MoveModel()
{
    return std::move(model);
}

void Entity::SetModel(std::vector<Vec2> model)
{
    this->model = std::move(model);
}

