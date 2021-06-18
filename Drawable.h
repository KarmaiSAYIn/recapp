#pragma once
#include "Vec.h"
#include "Color.h"
#include "Matrix.h"
#include <vector>

class Drawable
{
public: 
    Drawable(const std::vector<Vec2>& model, Color c);

    void Transform(const Mat3& transformations);
    void Draw(class Graphics& gfx) const;

private:
    Color c;
    const std::vector<Vec2> *model;
    Mat3 transformations = Mat3::Identity();
};
