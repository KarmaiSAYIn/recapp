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

    if (wnd.keyboard.KeyIsPressed(Keyboard::Key::SPACE))
        return false;
    return true;
}

void Game::UpdateModel(float fElapsedTime)
{
    rotation += -PI / 4 * fElapsedTime;
    scale += 1.0f + 0.05 * fElapsedTime;

    Mat3 transformations =  Mat3::Translate({300.0f, 300.0f}) * Mat3::FlipY() * Mat3::Rotate(rotation);

    star = Star::Make(100.0f, 50.0f);
    for (auto& v : star)
    {
      v *= transformations;
    }

    camera.Update(fElapsedTime, wnd.mouse, wnd.keyboard);
    //launcher.Update(fElapsedTime, balls);
    //plank.Update(fElapsedTime, wnd.keyboard);

    //const auto points = plank.GetPoints();
    //for (auto& ball : balls)
    //{
        //const auto plankVec = -points.first;
        //const auto plankPerp = Vec2{plankVec.y, -plankVec.x};
        //const auto ballPos = ball.GetPos();

        //if (plankPerp * ball.GetVelocity() < 0.0f)
        //{
            //if (DistancePointLine(ballPos, points.first, points.second) <= ball.GetRadius()) 
            //{
                //const Vec2 w = (-points.first).GetNormalized();
                //const Vec2 v = ball.GetVelocity();
                //ball.SetVelocity(w * (v * w) * 2.0f - v);
            //}
        //}
    //}
}

void Game::ComposeFrame()
{
    auto d = Drawable(star, Colors::Red);
    camera.Draw(d);
    //d = plank.GetDrawable();
    //camera.Draw(d);

    //for (const auto& ball : balls)
    //{
        //Drawable d = ball.GetDrawable();
        //camera.Draw(d);
    //}
}
