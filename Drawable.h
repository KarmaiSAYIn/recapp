#pragma once
#include "Vec.h"
#include "Color.h"
#include <vector>

class Drawable
{
public: 
    Drawable(const std::vector<Vec2>& model, Color c);

    void Scale(float scale);
    void ScaleX(float scale_x);
    void ScaleY(float scale_y);
    void Rotate(float theta);
    void Translate(const Vec2& offset);
    void Draw(class Graphics& gfx) const;

private:
    Color c;
    const std::vector<Vec2> *model;
    mutable Vec2 translation = {0.0f, 0.0f};
    float rotation = 0.0f;
    float scale_x = 1.0f;
    float scale_y = 1.0f;
};
