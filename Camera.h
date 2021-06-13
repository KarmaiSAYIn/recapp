#pragma once
#include "CoordinateTransformer.h"
#include "Vec.h"
#include "Rect.h"

class Camera final
{
public:
    Camera(CoordinateTransformer& transformer, float fSpeed = 10.0f, float scale = 1.0f);

    Rectf GetRect() const;

    Vec2 GetPos() const;
    void SetPos(const Vec2& pos);

    float GetScale() const;
    void SetScale(float scale);

    void Rotate(float theta);    

    void Translate(const Vec2& offset);

    void Update(float fElapsedTime, class Keyboard& keyboard, class Mouse& mouse);

    void Draw(Drawable& draw) const;
    void DrawRect(Rectf rect, Color c = Colors::RED) const;

private:
    float scale;
    float fSpeed;
    float rotation = 0.0f;
    Vec2 pos = {0.0f, 0.0f};
    Vec2 lastPos = {0.0f, 0.0f};
    CoordinateTransformer& transformer;
};
