#pragma once
#include "Engine.h"
#include "Color.h"
#include "Vec.h"
#include "CoordinateTransformer.h"
#include "Camera.h"
#include "Entity.h"
#include "Cube.h"
#include "Time.h"
#include "Math.h"

class Game : public olc::PixelGameEngine
{
public:
    Game() = delete;
    Game(const Game&) = delete;
    Game(class Graphics& gfx, class MainWindow& wnd);

    void SetGraphicsObject(class Graphics& gfx);

	bool OnUserCreate() override;
	bool OnUserUpdate() override;

    void UpdateModel(float fElapsedTime);
    void ComposeFrame();

private:
    class Graphics& gfx;
    class MainWindow& wnd;
    Time time;

    unsigned int nFrameCount = 0;
    unsigned int nFPS = 0;
    float fTime = 0.0f;
    
    CoordinateTransformer transformer;
    Camera camera;

    Cube cube;

    float zOffset = 2.0f;
    static constexpr float deltaTheta = PI;
    float rot_x = 0.0f;
    float rot_y = 0.0f;
    float rot_z = 0.0f;

    static constexpr float fUpdateSpeed = 0.000025f;
};
