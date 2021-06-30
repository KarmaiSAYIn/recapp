#pragma once
#include "CoordinateTransformer.h"
#include "MainWindow.h"

class Scene
{
public:
    virtual ~Scene() = default;

    virtual void Update(MainWindow& wnd, float fElapsedTime) = 0;
    virtual void Draw(Graphics& gfx, CoordinateTransformer& transformer) const = 0;
};
