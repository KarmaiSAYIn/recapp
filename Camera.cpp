#include "Camera.h"
#include "Graphics.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Math.h"

Camera::Camera(CoordinateTransformer& transformer, float fSpeed, float scale)
    :
    scale(scale),
    fSpeed(fSpeed),
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
    //This commented area would be the way to get the rect of the camera, but it requires a proper arbitrary Rect implementation wich is hard asf; put that shit off until later.
    //auto rect = Rectf({0.0f, 0.0f}, Graphics::ScreenWidth * zoom, Graphics::ScreenHeight * zoom).Rotate(rotation);
    //rect.Translate(pos);
    auto rect = Rectf(pos, Graphics::ScreenWidth * zoom, Graphics::ScreenHeight * zoom);
    return rect;
}

void Camera::SetPos(const Vec2& pos)
{
    this->pos = pos;
}

void Camera::SetScale(float scale)
{
    this->scale = scale; 
}

void Camera::Rotate(float theta)
{
    rotation += theta;
    pos.Rotate(theta);
}

void Camera::Translate(const Vec2& offset)
{
    pos += offset;
}

void Camera::Update(float fElapsedTime, Keyboard& keyboard, Mouse& mouse)
{
    if (mouse.LeftDownEvent())
    {
        lastPos = mouse.GetPos();
        lastPos.y = -lastPos.y;
    }

    if (mouse.LeftIsPressed())
    {
        Vec2 currMousePos = mouse.GetPos();
        currMousePos.y = -currMousePos.y;
        Translate((lastPos - currMousePos) / GetScale());
        lastPos = currMousePos;
    }

    if (mouse.WheelUp() || keyboard.KeyIsPressed(Keyboard::Key::UP))
        SetScale(GetScale() + fSpeed * fElapsedTime);
    if (mouse.WheelDown() || keyboard.KeyIsPressed(Keyboard::Key::DOWN))
        SetScale(std::max(0.05f, GetScale() - fSpeed * fElapsedTime));

    if (keyboard.KeyIsPressed(Keyboard::Key::Q))
        Rotate(PI / 4 * fElapsedTime);

    if (keyboard.KeyIsPressed(Keyboard::Key::E))
        Rotate(-PI / 4 * fElapsedTime);
}

void Camera::Draw(Drawable& draw) const
{
    draw.Rotate(rotation);
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

