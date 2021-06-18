#pragma once
#include "Engine.h"
#include "Color.h"
#include "Vec.h"
#include "CoordinateTransformer.h"
#include "Camera.h"
#include "Entity.h"
#include "Plank.h"
#include "BallLauncher.h"
#include <vector>
#include "Time.h"

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

    float rotation = 0.0f;
    float scale = 0.0f;

    CoordinateTransformer transformer;
    Camera camera;

    std::vector<Ball> balls;
    std::vector<Vec2> star;

    Plank plank;
    BallLauncher launcher;

    static constexpr float fUpdateSpeed = 0.000025f;
};
