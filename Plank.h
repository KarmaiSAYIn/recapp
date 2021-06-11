#pragma once
#include "Entity.h"
#include "Vec.h"

class Plank : public Entity
{
public:
    Plank(const Vec2& anchorPos, float freeX, int nMinY, int nMaxY, int nThickness, float fSpeed, Color c = Colors::YELLOW);
    ~Plank() = default;
    
    std::pair<Vec2, Vec2> GetPoints() const;

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
