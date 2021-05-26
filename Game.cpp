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

    bIsClicked = wnd.mouse.LeftIsPressed();

    if (!bIsClicked)
    {
        c = { 255, 255, 255 };
        if (wnd.keyboard.KeyIsPressed(Keyboard::Key::LEFT))
            vel.x = -1.0f;
        else
            vel.x = 0.0f;
        if (wnd.keyboard.KeyIsPressed(Keyboard::Key::RIGHT))
            vel.x = 1.0f;
        else
            vel.x = std::min(0.0f, vel.x);
        if (wnd.keyboard.KeyIsPressed(Keyboard::Key::UP))
            vel.y = -1.0f;
        else
            vel.y = 0.0f;
        if (wnd.keyboard.KeyIsPressed(Keyboard::Key::DOWN))
            vel.y = 1.0f;
        else
            vel.y = std::min(0.0f, vel.y);
    }
    else
    {
        vel = (wnd.mouse.GetPos() - pos);
        c = { 255, 0, 0 } ;
    }
    
    pos += vel.GetNormalized() * speed * fElapsedTime;
    gfx.DrawCircle(Vei2(pos), 50, c);
    return true;
}
