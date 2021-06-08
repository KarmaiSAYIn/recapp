#include "Camera.h"
#include "Graphics.h"
#include "Mouse.h"
#include "Keyboard.h"

Camera::Camera(CoordinateTransformer& transformer)
    :
    transformer(transformer)
{
}

Camera::Camera(CoordinateTransformer& transformer, float scale)
    :
    scale(scale),
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

void Camera::Update(const Mouse& mouse, const Keyboard& keyboard)
{
    if (mouse.LeftDownEvent())
    {
        lastMousePos = mouse.GetPos();
        lastMousePos.y = -lastMousePos.y;
    }

    if (mouse.LeftIsPressed())
    {
        Vec2 currMousePos = mouse.GetPos();
        currMousePos.y = -currMousePos.y;
        Translate((lastMousePos - currMousePos) / GetScale());
        lastMousePos = currMousePos;
    }

    if (mouse.WheelUp() || keyboard.KeyIsPressed(Keyboard::Key::UP))
        SetScale(GetScale() * 1.05f);
    if (mouse.WheelDown() || keyboard.KeyIsPressed(Keyboard::Key::DOWN))
        SetScale(GetScale() * 0.95f);
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

