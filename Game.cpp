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
    static const Color colors[] =
    {
        Colors::Red,
        Colors::Orange,
        Colors::Yellow,
        Colors::Green,
        Colors::Blue,
        Colors::Indigo,
        Colors::Violet,
        Colors::Lavender,
        Colors::Thistle,
        Colors::Purple,
        Colors::Cyan,
        Colors::Maya
    };

    auto triangles = cube.GetTriangles();
    const Mat3 rotation =
        Mat3::RotateX(rot_x) *
        Mat3::RotateY(rot_y) *
        Mat3::RotateZ(rot_z);

    for (auto& v : triangles.vertices)
    {
        v *= rotation;
        v += {0.0f, 0.0f, zOffset};
    }

    for (size_t i = 0, end = triangles.indices.size() / 3; i < end; i++)
    {
        const auto v0 = triangles.vertices[triangles.indices[i * 3]];
        const auto v1 = triangles.vertices[triangles.indices[i * 3 + 1]];
        const auto v2 = triangles.vertices[triangles.indices[i * 3 + 2]];
        triangles.cullFlags[i] = (v1 - v0).cross(v2 - v0).dot(v0) >= 0.0f;
    }

    for (auto& v : triangles.vertices)
        transformer.Translate(v);

    for (size_t i = 0, end = triangles.indices.size() / 3; i < end; i++)
    {
        if (!triangles.cullFlags[i])
            gfx.DrawTriangle(triangles.vertices[triangles.indices[i * 3]], triangles.vertices[triangles.indices[i * 3 + 1]], triangles.vertices[triangles.indices[i * 3 + 2]], colors[i]);
    }
}
