#include "Game.h"
#include "Graphics.h"
#include "MainWindow.h"
#include "Keyboard.h"

Game::Game(Graphics& gfx, MainWindow& wnd)
    :
    gfx(gfx),
    wnd(wnd)
{
    sAppName = "Recapp";
}

bool Game::OnUserCreate()
{
    pos = {(float)gfx.GetScreenWidth() / 2, (float)gfx.GetScreenHeight() / 2};
    return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
    gfx.Clear(Color(0, 0, 0));

    gfx.DrawLine(Vec2((float)ScreenWidth() / 2, (float)ScreenHeight() / 2), (Vec2)wnd.mouse.GetPos(), Color(255, 255, 255));

    return true;
}
