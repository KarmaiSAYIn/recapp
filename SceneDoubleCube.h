#pragma once
#include "Scene.h"
#include "Cube.h"
#include "Math.h"
#include "Graphics.h"

class SceneDoubleCube : public Scene
{
public:
    SceneDoubleCube();

    void Update(MainWindow& wnd, float fElapsedTime) override;
    void Draw(Graphics& gfx, CoordinateTransformer& transformer) const override;

private:
    Cube cube0;
    Cube cube1;

    float zOffset = 2.0f;
    static constexpr float deltaTheta = PI;
    float rot_x = 0.0f;
    float rot_y = 0.0f;
    float rot_z = 0.0f;
};
