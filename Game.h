#pragma once
#include "Engine.h"

class Game : public olc::PixelGameEngine
{
public:
	Game();

	virtual bool OnUserCreate() override;

	virtual bool OnUserUpdate(float fElapsedTime) override;
};
