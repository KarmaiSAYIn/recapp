#include "Game.h"
#include "Graphics.h"
#include "MainWindow.h"
#include "Keyboard.h"
#include "Drawable.h"
#include "Math.h"
#include "Matrix.h"
#include "SceneCube.h"
#include "SceneDoubleCube.h" 

Game::Game(Graphics& gfx, MainWindow& wnd)
    :
    gfx(gfx),
    wnd(wnd),
    transformer(gfx)
{
}

bool Game::OnUserCreate()
{
    scenes.push_back(std::make_unique<SceneCube>());
    scenes.push_back(std::make_unique<SceneDoubleCube>());

    currScene = scenes.begin();

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

    for (; fElapsedTime > 0.0f; fElapsedTime -= fUpdateSpeed)
    {
        UpdateModel(fUpdateSpeed);
    }

    ComposeFrame();
    wnd.SetWindowTitle(std::string(WINDOWNAME) + " FPS: " + std::to_string(nFPS));
    return true;
}

void Game::UpdateModel(float fElapsedTime)
{
    if (wnd.kbd.KeyDownEvent(Key::TAB))
    {
        if (wnd.kbd.KeyIsPressed(Key::SHIFT))
        {
            AdvanceScene(-1);
        }
        else
        {
            AdvanceScene(1);
        }
    }

    (*currScene)->Update(wnd, fElapsedTime);
}

void Game::ComposeFrame()
{
    (*currScene)->Draw(gfx, transformer);
}

void Game::AdvanceScene(int direction)
{
    if (direction >= 0)
        direction = 1;
    else
        direction = -1;
    
    currScene += direction;
    if (currScene >= scenes.end())
        currScene = scenes.begin();
    else if (currScene < scenes.begin())
        currScene = scenes.end() - 1;
}
