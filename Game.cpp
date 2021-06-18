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
    camera(transformer, 0.5f, 25.0f),
    plank({0.0f, 0.0f}, -1000.0f, -500, 500, 10, 250.0f),
    launcher({-150.0f, -400.0f}, -10.0f, -50.0f, 50.0f, {{-1000.0f, 600.0f}, {200, -500}})
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
    const auto tform = Mat3::Rotate(0.3f);
    const auto tform2 = Mat3::Scale(2.0f);
    const auto tform3 = Mat3::FlipY();
    const auto tform4 = Mat3::Translate({100.0f, 100.0f});

    const auto transformations = tform3 * tform * tform2 * tform4;

    star = Star::Make(100.0f, 50.0f);
    for (auto& v : star)
    {
      v *= transformations;
    }

    camera.Update(fElapsedTime, wnd.mouse, wnd.keyboard);
}

void Game::ComposeFrame()
{
    auto d = Drawable(star, Colors::Red);
    camera.Draw(d);
}
