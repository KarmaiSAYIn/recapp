#pragma once
#include "Engine.h"
#include "Color.h"
#include "Vec.h"
#include "CoordinateTransformer.h"
#include "Entity.h"

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

    CoordinateTransformer transformer;
    Entity entity;
};
