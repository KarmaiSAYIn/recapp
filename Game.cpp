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
    wnd(wnd),
    transformer(gfx),
    camera(transformer, 1.0f, 25.0f),
    cube(1.0f)
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
}

void Game::ComposeFrame()
{
    auto lines = cube.GetLines();
    for (auto& v : lines.vertices)
        transformer.Translate(v);

    for (auto i = std::begin(lines.indices), end = std::end(lines.indices); i != end; std::advance(i, 2))
    {
        gfx.DrawLine(lines.vertices[*i], lines.vertices[*std::next(i)], Colors::White);
    }
}
