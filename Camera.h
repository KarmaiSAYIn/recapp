#pragma once
#include "CoordinateTransformer.h"
#include "Vec.h"
#include "Rect.h"

class Camera final
{
public:
    Camera(CoordinateTransformer& transformer);

    Vec2 GetPos() const;
    float GetScale() const;
    Rectf GetRect() const;
    void SetPos(const Vec2& pos);
    void SetScale(float scale);
    void Translate(const Vec2& offset);
    void Update(float fElapsedTime, class Keyboard& keyboard, class Mouse& mouse);
    void Draw(Drawable& draw) const;
    void DrawRect(Rectf rect, Color c = Colors::RED) const;

private:
    float scale = 1.0f;
    Vec2 pos = {0.0f, 0.0f};
    Vec2 lastPos = {0.0f, 0.0f};
    CoordinateTransformer& transformer;
};
