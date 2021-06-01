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

void Camera::SetPos(Vec2 pos)
{
    this->pos = pos;
}

float Camera::GetScale() const
{
    return scale;
}

void Camera::SetScale(float scale)
{
    this->scale = scale; 
}

void Camera::Translate(Vec2 offset)
{
    pos += offset;
}

void Camera::DrawClosedPolyline(std::vector<Vec2> vertices, Color c)
{
    for (auto& v : vertices)
    {
        v -= pos;
        v *= scale;
    }
    transformer.DrawClosedPolyline(std::move(vertices), c);
}
