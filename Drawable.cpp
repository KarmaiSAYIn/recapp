#include "Drawable.h"
#include "Graphics.h"

Drawable::Drawable(std::vector<Vec2> model, Color c)
    :
    c(c),
    model(std::move(model))
{
}

void Drawable::Scale(float scale)
{
    scale_x *= scale;
    scale_y *= scale;
    translation *= scale;
}

void Drawable::ScaleX(float scale_x)
{
    this->scale_x *= scale_x;
    translation.x *= scale_x;
}

void Drawable::ScaleY(float scale_y)
{
    this->scale_y *= scale_y;
    translation.y *= scale_y;
}

void Drawable::Translate(const Vec2& offset)
{
    translation += offset;
}

void Drawable::Draw(Graphics& gfx) const
{
    for (auto& v : model)
    {
        v.x *= scale_x;
        v.y *= scale_y;
        v += translation;
    }

    gfx.DrawClosedPolyline(model, c);
}

