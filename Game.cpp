#include "Game.h"
#include "Graphics.h"
#include "MainWindow.h"
#include "Keyboard.h"
#include "Star.h"
#include "Drawable.h"
#include "Math.h"

Game::Game(Graphics& gfx, MainWindow& wnd)
    :
    gfx(gfx),
    wnd(wnd), transformer(gfx),
    camera(transformer, 0.5f, 25.0f),
    plank({0.0f, 0.0f}, -1000.0f, -500, 500, 10, 250.0f),
    launcher({-150.0f, -400.0f}, -10.0f, -50.0f, 50.0f, {{-1000.0f, 600.0f}, {200, -500}})
{
    sAppName = "Recapp";
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
    wnd.SetWindowTitle(sAppName + " FPS: " + std::to_string(nFPS));
    return true;
}

void Game::UpdateModel(float fElapsedTime)
{
    camera.Update(fElapsedTime, wnd.mouse, wnd.keyboard);
    launcher.Update(fElapsedTime, balls);
    plank.Update(fElapsedTime, wnd.keyboard);

    const auto points = plank.GetPoints();
    for (auto& ball : balls)
    {
        const auto dy = points.second.y - points.first.y;
        const auto dx = points.second.x - points.first.x;
        const auto ballPos = ball.GetPos();
        Vec2 plankPerp;

        if (dy == 0.0f)
        {
            plankPerp = {0.0f, ballPos.y > points.first.y ? 1.0f : -1.0f};
        }
        else if (dx == 0.0f)
        {
            plankPerp = {ballPos.x > points.first.x ? 1.0f : -1.0f, 0.0f};
        }
        else
        {
            const auto m = dy / dx;
            const auto w = -dx / dy;
            const auto b = points.first.y - m * points.first.x;
            const auto p = ballPos.y - w * ballPos.x;
            const auto x = (p - b) / (m - w);
            const auto y = m * x + b;
            plankPerp = (ballPos - Vec2{x, y}).GetNormalized();
        }

        if (plankPerp * ball.GetVelocity() < 0.0f)
        {
            if (DistancePointLine(ballPos, points.first, points.second) <= ball.GetRadius()) 
            {
                const Vec2 w = (-points.first).GetNormalized();
                const Vec2 v = ball.GetVelocity();
                ball.SetVelocity(w * (v * w) * 2.0f - v);
            }
        }
    }
}

void Game::ComposeFrame()
{
    Drawable d = plank.GetDrawable();
    camera.Draw(d);

    for (const auto& ball : balls)
    {
        Drawable d = ball.GetDrawable();
        camera.Draw(d);
    }
}
