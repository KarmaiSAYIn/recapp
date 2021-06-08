#pragma once
#include "Entity.h"
#include "Vec.h"

class Plank : public Entity
{
public:
    Plank(const Vec2& anchorPos, float freeX, int nMinY, int nMaxY, int nThickness, float fSpeed, Color c = Colors::YELLOW);
    ~Plank() = default;
    
    Vec2 GetPos() const override;
    void SetPos(const Vec2 &pos) override;

    void SetScale(float scale) override;
    float GetScale() const override;

    void Translate(const Vec2& offset) override;

    void Update(float fElapsedTime, class Keyboard& keyboard);

    Drawable GetDrawable() const override;

private:

private:
    int nMinY;
    int nMaxY;
    int nThickness;
    float fSpeed;

    Vec2 freePos;
};
