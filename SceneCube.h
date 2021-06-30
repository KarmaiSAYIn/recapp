#pragma once
#include "Scene.h"
#include "Cube.h"
#include "Graphics.h"
#include "MainWindow.h"
#include "Math.h"

class SceneCube : public Scene
{
public:
    SceneCube();

    void Update(MainWindow& wnd, float fElapsedTime) override;
    void Draw(Graphics& gfx, CoordinateTransformer& transformer) const override;

private:
    Cube cube;

    float zOffset = 2.0f;
    static constexpr float deltaTheta = PI;
    float rot_x = 0.0f;
    float rot_y = 0.0f;
    float rot_z = 0.0f;
};
