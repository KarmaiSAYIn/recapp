#include "Drawable.h"
#include "Graphics.h"

Drawable::Drawable(const std::vector<Vec2>& model, Color c)
    :
    c(c),
    model(&model)
{
}

void Drawable::Transform(const Mat3& transformations)
{
    this->transformations = transformations; 
}

void Drawable::Draw(Graphics& gfx) const
{
    gfx.DrawClosedPolyline(*model, transformations, c);
}

