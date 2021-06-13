#include "Drawable.h"
#include "Graphics.h"

Drawable::Drawable(const std::vector<Vec2>& model, Color c)
    :
    c(c),
    model(&model)
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

void Drawable::Rotate(float theta)
{
    rotation += theta;
    translation.Rotate(theta);
}

void Drawable::Translate(const Vec2& offset)
{
    translation += offset;
}

void Drawable::Draw(Graphics& gfx) const
{
    gfx.DrawClosedPolyline(*model, translation, scale_x, scale_y, rotation, c);
}

