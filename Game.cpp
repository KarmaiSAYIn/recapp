#include "Game.h"
#include "Graphics.h"
#include "MainWindow.h"
#include "Keyboard.h"
#include "Drawable.h"
#include "Math.h"
#include "Matrix.h"

Game::Game(Graphics& gfx, MainWindow& wnd)
    :
    gfx(gfx),
    wnd(wnd)
{
}

bool Game::OnUserCreate()
{
    return true;
}

bool Game::OnUserUpdate()
{
    gfx.Clear();
    ComposeFrame();
    wnd.SetWindowTitle("Mariah's App :}");
    return true;
}

void Game::UpdateModel(float fElapsedTime)
{
}

void Game::ComposeFrame()
{
}
