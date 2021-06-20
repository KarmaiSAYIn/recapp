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
   r.Transform(
           Mat3::Translate((Vec3)pos) *
           Mat3::Scale(scale)
           );
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

void Entity::SetModel(std::vector<Vec2> model) const
{
    this->model = std::move(model);
}

