#pragma once
#include "CoordinateTransformer.h"
#include "Vec.h"
#include "Rect.h"
#include "Drawable.h"

class Camera final
{
public:
    Camera(CoordinateTransformer& transformer);
    Camera(CoordinateTransformer& transformer, float initScale, float fScaleRate);

    Vec2 GetPos() const;
    float GetScale() const;
    Rectf GetRect() const;
    void SetPos(const Vec2& pos);
    void SetScale(float scale);
    void Translate(const Vec2& offset);
    
    void Update(const float fElapsedTime, const class Mouse& mouse, const class Keyboard& keyboard);

    void Draw(Drawable& draw) const;
    void DrawRect(Rectf rect, Color c = Colors::Red) const;

private:
    float scale = 1.0f;
    float fScaleRate = 25.0f;

    Vec2 pos = {0.0f, 0.0f};
    Vec2 lastMousePos = {0.0f, 0.0f};

    CoordinateTransformer& transformer;
};
