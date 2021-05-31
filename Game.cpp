#include "Game.h"
#include "Graphics.h"
#include "MainWindow.h"
#include "Keyboard.h"
#include "Star.h"

Game::Game(Graphics& gfx, MainWindow& wnd)
    :
    gfx(gfx),
    wnd(wnd)
{
    sAppName = "Recapp";
}

bool Game::OnUserCreate()
{
    return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
    gfx.Clear(Color(0, 0, 0));

    if (wnd.mouse.LeftIsPressed())
        gfx.DrawLine({(float)gfx.GetScreenWidth() / 2, (float)gfx.GetScreenHeight() / 2}, (Vec2)wnd.mouse.GetPos(), Color(255, 255, 0));

    auto poly = Star::Make(150.0f, 75.0f, 8);
    for (auto& v : poly)
        v += Vec2((float)gfx.GetScreenWidth() / 2, (float)gfx.GetScreenHeight() / 2);

    gfx.DrawClosedPolyline(poly, Color(255, 0, 0));

    return true;
}
