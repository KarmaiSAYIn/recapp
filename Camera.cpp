#include "Camera.h"
#include "Graphics.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "Math.h"

Camera::Camera(CoordinateTransformer& transformer)
    :
    transformer(transformer)
{
}

Camera::Camera(CoordinateTransformer& transformer, float initScale, float fScaleRate)
    :
    scale(initScale),
    fScaleRate(fScaleRate),
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
    //This commented area would be the way to get the rect of the camera, but it requires a proper arbitrary rotation Rect implementation which is hard asf; put that shit off until later.
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

void Camera::Update(const float fElapsedTime, const Mouse& mouse, const Keyboard& keyboard)
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
        SetScale(GetScale() + fScaleRate * fElapsedTime);
    if (mouse.WheelDown() || keyboard.KeyIsPressed(Keyboard::Key::DOWN))
        SetScale(std::max(0.01f, GetScale() - fScaleRate * fElapsedTime));

    if (keyboard.KeyIsPressed(Keyboard::Key::Q))
        Rotate(PI / 4 * fElapsedTime);
    if (keyboard.KeyIsPressed(Keyboard::Key::E))
        Rotate(-PI / 4 * fElapsedTime);
}

void Camera::Draw(Drawable& draw) const
{
    draw.Transform(
            Mat3::Rotate(rotation) *
            Mat3::Scale(scale) *
            Mat3::Translate((Vec3)-pos)
            );
    transformer.Draw(draw);
}

void Camera::DrawRect(Rectf rect, Color c) const
{
    rect.Translate(-pos);
    rect.Scale(scale);
    transformer.DrawRect(rect, c);
}

