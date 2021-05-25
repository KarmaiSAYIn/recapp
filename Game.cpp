#include "Game.h"
#include "Graphics.h"

Game::Game(Graphics& gfx)
    :
    gfx(gfx)
{
    sAppName = "Recapp";
}

bool Game::OnUserCreate()
{
    return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
    gfx.DrawCircle(Vei2(gfx.GetScreenWidth() / 2, gfx.GetScreenHeight() / 2), 50, Color(255, 255, 255));
    return true;
}
