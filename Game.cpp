#include "Game.h"
#include "Graphics.h"
#include "MainWindow.h"
#include "Keyboard.h"
#include "Star.h"
#include "Drawable.h"

Game::Game(Graphics& gfx, MainWindow& wnd)
    :
    gfx(gfx),
    wnd(wnd),
    transformer(gfx),
    camera(transformer, 0.5f),
    plank({0.0f, 0.0f}, -1000.0f, -500, 500, 10, 500.0f)
{
    sAppName = "Recapp";
}

bool Game::OnUserCreate()
{
    return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
    gfx.Clear();
    UpdateModel(fElapsedTime);
    ComposeFrame();
    return true;
}

void Game::UpdateModel(float fElapsedTime)
{
    camera.Update(wnd.mouse, wnd.keyboard);
    plank.Update(fElapsedTime, wnd.keyboard);
}

void Game::ComposeFrame()
{
    Drawable d = plank.GetDrawable();
    camera.Draw(d);
}
