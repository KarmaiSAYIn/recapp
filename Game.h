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

class Game : public olc::PixelGameEngine
{
public:
    Game() = delete;
    Game(const Game&) = delete;
    Game(class Graphics& gfx, class MainWindow& wnd);

    void SetGraphicsObject(class Graphics& gfx);

	bool OnUserCreate() override;
	bool OnUserUpdate(float fElapsedTime) override;

    void UpdateModel(float fElapsedTime);
    void ComposeFrame();

private:
    class Graphics& gfx;
    class MainWindow& wnd;

    CoordinateTransformer transformer;
    Camera camera;

    Plank plank;
    BallLauncher launcher;
};
