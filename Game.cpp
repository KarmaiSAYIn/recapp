#include "Game.h"
#include "Graphics.h"
#include "MainWindow.h"
#include "Keyboard.h"
#include "Star.h"
#include "Drawable.h"
#include "Math.h"
#include "Matrix.h"

Game::Game(Graphics& gfx, MainWindow& wnd)
    :
    gfx(gfx),
    wnd(wnd), transformer(gfx),
    camera(transformer, 1.0f, 25.0f),
    field(Graphics::ScreenWidth * 10, Graphics::ScreenHeight * 10, 10.0f, 150.0f, -2.0f, 2.0f, 3, 9, 1000)
{
}

bool Game::OnUserCreate()
{
    return true;
}

bool Game::OnUserUpdate()
{
    float fElapsedTime = time.Mark();
    fTime += fElapsedTime;
    if (fTime >= 1.0f)
    {
        nFPS = nFrameCount / fTime;
        nFrameCount = 0;
        fTime = 0.0f; 
    }
    nFrameCount++;

    gfx.Clear();
    for (float time = fUpdateSpeed; fElapsedTime > 0.0f; fElapsedTime -= fUpdateSpeed)
    {
        UpdateModel(time);
    }

    ComposeFrame();
    wnd.SetWindowTitle(std::string(WINDOWNAME) + " FPS: " + std::to_string(nFPS));
    return true;
}

void Game::UpdateModel(float fElapsedTime)
{
    camera.Update(fElapsedTime, wnd.mouse, wnd.keyboard);
    field.Update(fElapsedTime);
}

void Game::ComposeFrame()
{
    field.Draw(camera);
}
