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
    camera(transformer),
    starfield(Graphics::ScreenWidth * 10, Graphics::ScreenHeight * 10, 5.0f, 100.0f, -2.0f, 2.0f, 3, 9, 1000)
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
    camera.Update(fElapsedTime, wnd.keyboard, wnd.mouse);
    starfield.Update(fElapsedTime);
}

void Game::ComposeFrame()
{
    starfield.Draw(camera);
}
