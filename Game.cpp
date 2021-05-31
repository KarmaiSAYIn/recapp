#include "Game.h"
#include "Graphics.h"
#include "MainWindow.h"
#include "Keyboard.h"
#include "Star.h"

Game::Game(Graphics& gfx, MainWindow& wnd)
    :
    gfx(gfx),
    wnd(wnd),
    transformer(gfx),
    entity(Star::Make(150.0f, 75.0f, 8))
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

    Vec2 delta = { 0.0f, 0.0f };
    if (wnd.keyboard.KeyIsPressed(Keyboard::Key::LEFT) || wnd.keyboard.KeyIsPressed(Keyboard::Key::H))
        delta.x = -1.0f;
    if (wnd.keyboard.KeyIsPressed(Keyboard::Key::RIGHT) || wnd.keyboard.KeyIsPressed(Keyboard::Key::L))
        delta.x = 1.0f;
    if (wnd.keyboard.KeyIsPressed(Keyboard::Key::UP) || wnd.keyboard.KeyIsPressed(Keyboard::Key::K))
        delta.y = 1.0f;
    if (wnd.keyboard.KeyIsPressed(Keyboard::Key::DOWN) || wnd.keyboard.KeyIsPressed(Keyboard::Key::J))
        delta.y = -1.0f;

    if (wnd.mouse.WheelUp())
    {
        if (wnd.keyboard.KeyIsPressed(Keyboard::Key::SHIFT))
            entity.SetScale(entity.GetScale() * 1.5f);
        else
            entity.SetScale(entity.GetScale() * 1.05f);
    }

    if (wnd.mouse.WheelDown())
    {
        if (wnd.keyboard.KeyIsPressed(Keyboard::Key::SHIFT))
            entity.SetScale(entity.GetScale() * 0.5f);
        else
            entity.SetScale(entity.GetScale() * 0.95f);
    }

    entity.Translate(delta.GetNormalized() * 500.0f * fElapsedTime);
    transformer.DrawClosedPolyline(entity.GetModel(), Color(255, 0, 0));

    return true;
}
