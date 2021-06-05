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
    starfield(10000, 10000, 5.0f, 100.0f, 3, 9, 1000)
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
    if (wnd.mouse.LeftDownEvent())
    {
        lastMousePos = wnd.mouse.GetPos();
        lastMousePos.y = -lastMousePos.y;
    }

    if (wnd.mouse.LeftIsPressed())
    {
        Vec2 currMousePos = wnd.mouse.GetPos();
        currMousePos.y = -currMousePos.y;
        camera.Translate((lastMousePos - currMousePos) / camera.GetScale());
        lastMousePos = currMousePos;
    }

    if (wnd.mouse.WheelUp() || wnd.keyboard.KeyIsPressed(Keyboard::Key::UP))
        camera.SetScale(camera.GetScale() * 1.05f);
    if (wnd.mouse.WheelDown() || wnd.keyboard.KeyIsPressed(Keyboard::Key::DOWN))
        camera.SetScale(camera.GetScale() * 0.95f);
}

void Game::ComposeFrame()
{
    starfield.Draw(camera);
}
