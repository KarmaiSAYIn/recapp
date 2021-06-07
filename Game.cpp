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
    camera(transformer)
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
}

void Game::ComposeFrame()
{
}
