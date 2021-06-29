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
};
