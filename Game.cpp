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
    if (wnd.kbd.KeyIsPressed(Key::Q))
        rot_x = wrap_angle(rot_x + deltaTheta * fElapsedTime);
    if (wnd.kbd.KeyIsPressed(Key::A))
        rot_x = wrap_angle(rot_x - deltaTheta * fElapsedTime);

    if (wnd.kbd.KeyIsPressed(Key::W))
        rot_y = wrap_angle(rot_y + deltaTheta * fElapsedTime);
    if (wnd.kbd.KeyIsPressed(Key::S))
        rot_y = wrap_angle(rot_y - deltaTheta * fElapsedTime);

    if (wnd.kbd.KeyIsPressed(Key::E))
        rot_z = wrap_angle(rot_z + deltaTheta * fElapsedTime);
    if (wnd.kbd.KeyIsPressed(Key::D))
        rot_z = wrap_angle(rot_z - deltaTheta * fElapsedTime);

    if (wnd.kbd.KeyIsPressed(Key::R))
        zOffset += 1.0f * fElapsedTime;
    if (wnd.kbd.KeyIsPressed(Key::F))
        zOffset -= 1.0f * fElapsedTime;
}

void Game::ComposeFrame()
{
    auto lines = cube.GetLines();
    const Mat3 rotation =
        Mat3::RotateX(rot_x) *
        Mat3::RotateY(rot_y) *
        Mat3::RotateZ(rot_z);
    for (auto& v : lines.vertices)
    {
        v *= rotation;
        v += {0.0f, 0.0f, zOffset};
        transformer.Translate(v);
    }

    for (auto i = std::begin(lines.indices), end = std::end(lines.indices); i != end; std::advance(i, 2))
    {
        gfx.DrawLine(lines.vertices[*i], lines.vertices[*std::next(i)], Colors::Maya);
    }
}
