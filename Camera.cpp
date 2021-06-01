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

void Camera::Translate(Vec2 offset)
{
    pos += offset;
}

void Camera::DrawClosedPolyline(std::vector<Vec2> vertices, Color c)
{
    for (auto& v : vertices)
    {
        v -= pos;
    }
    transformer.DrawClosedPolyline(std::move(vertices), c);
}
