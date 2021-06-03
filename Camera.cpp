#include "Camera.h"

Camera::Camera(CoordinateTransformer& transformer)
    :
    transformer(transformer)
{
}

Vec2 Camera::GetPos() const
{
    return pos;
}

float Camera::GetScale() const
{
    return scale;
}

void Camera::SetScale(float scale)
{
    this->scale = scale; 
}

void Camera::Translate(const Vec2& offset)
{
    pos += offset;
}

void Camera::Draw(Drawable& draw) const
{
    draw.Translate(-pos);
    draw.Scale(scale);
    transformer.Draw(draw);
}
