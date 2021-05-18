#pragma once
#include "Engine.h"
#include "Color.h"
#include "Vec.h"

class Game : public olc::PixelGameEngine
{
public:
    Game();
    Game(const Game&) = delete;

    void SetGraphicsObject(class Graphics *gfx);

	virtual bool OnUserCreate() override;

	virtual bool OnUserUpdate(float fElapsedTime) override;

private:
    class Graphics *gfx = nullptr;
};
