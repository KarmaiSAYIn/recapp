#include "Camera.h"
#include "Graphics.h"

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

Rectf Camera::GetRect() const
{
    const float zoom = 1.0f / scale;
    return Rectf(pos, Graphics::ScreenWidth * zoom, Graphics::ScreenHeight * zoom);
}

void Camera::SetPos(const Vec2& pos)
{
    this->pos = pos;
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

void Camera::DrawRect(Rectf rect, Color c) const
{
    rect.Translate(Vec2(pos.x * -1.0f, pos.y));
    rect.Scale(scale);
    transformer.DrawRect(rect, c);
}

