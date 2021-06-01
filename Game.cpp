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
    camera(transformer)
{
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
    gfx.Clear(Color(0, 0, 0));

    if (wnd.mouse.LeftIsPressed())
        gfx.DrawLine({(float)gfx.GetScreenWidth() / 2, (float)gfx.GetScreenHeight() / 2}, (Vec2)wnd.mouse.GetPos(), Color(255, 255, 0));

    Vec2 delta = { 0.0f, 0.0f };
    if (wnd.keyboard.KeyIsPressed(Keyboard::Key::LEFT) || wnd.keyboard.KeyIsPressed(Keyboard::Key::A))
        delta.x = -1.0f;
    if (wnd.keyboard.KeyIsPressed(Keyboard::Key::RIGHT) || wnd.keyboard.KeyIsPressed(Keyboard::Key::D))
        delta.x = 1.0f;
    if (wnd.keyboard.KeyIsPressed(Keyboard::Key::UP) || wnd.keyboard.KeyIsPressed(Keyboard::Key::W))
        delta.y = 1.0f;
    if (wnd.keyboard.KeyIsPressed(Keyboard::Key::DOWN) || wnd.keyboard.KeyIsPressed(Keyboard::Key::S))
        delta.y = -1.0f;

    if (wnd.mouse.WheelUp())
        camera.SetScale(camera.GetScale() * 1.05f);
    if (wnd.mouse.WheelDown())
        camera.SetScale(camera.GetScale() * 0.95f);

    camera.Translate(delta.GetNormalized() * 150.0f * fElapsedTime);
    for (auto& entity : entities)
        camera.DrawClosedPolyline(entity.GetModel(), Color(255, 0, 255));

    return true;
}
