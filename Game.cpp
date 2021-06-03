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
    entities.reserve(7);
    entities.emplace_back(Star::Make(100.0f, 50.0f), Vec2(460.0f,0.0f));
    entities.emplace_back(Star::Make(150.0f, 50.0f), Vec2(150.f,300.0f));
    entities.emplace_back(Star::Make(100.0f, 50.0f), Vec2(250.0f, -200.0f));
    entities.emplace_back(Star::Make(150.0f, 50.0f), Vec2(-250.0f, 200.0f));
    entities.emplace_back(Star::Make(100.0f, 50.0f), Vec2(0.0f, 0.0f));
    entities.emplace_back(Star::Make(200.0f, 50.0f), Vec2(-150.0f, -300.0f));
    entities.emplace_back(Star::Make(100.0f, 50.0f), Vec2(400.0f, 600.0f));
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
}

void Game::UpdateModel(float fElapsedTime)
{
    gfx.Clear();

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
    for (const auto& entity : entities)
    {
        auto d = entity.GetDrawable();
        camera.Draw(d);
    }
}
