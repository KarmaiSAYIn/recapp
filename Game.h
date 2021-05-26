#pragma once
#include "Engine.h"
#include "Color.h"
#include "Vec.h"

class Game : public olc::PixelGameEngine
{
public:
    Game() = delete;
    Game(const Game&) = delete;
    Game(class Graphics& gfx, class MainWindow& wnd);

    void SetGraphicsObject(class Graphics& gfx);

	virtual bool OnUserCreate() override;
	virtual bool OnUserUpdate(float fElapsedTime) override;

private:
    class Graphics& gfx;
    class MainWindow& wnd;

    Color c = {255, 255, 255};

    Vec2 pos;
    Vec2 vel;
    float speed = 150.0f;

    bool bIsClicked = false;
};
