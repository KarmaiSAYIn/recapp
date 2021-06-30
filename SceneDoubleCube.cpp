#include "SceneDoubleCube.h"

SceneDoubleCube::SceneDoubleCube()
    :
    cube0(1.0f),
    cube1(1.0f)
{
}

void SceneDoubleCube::Update(MainWindow& wnd, float fElapsedTime)
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

void SceneDoubleCube::Draw(Graphics& gfx, CoordinateTransformer& transformer) const
{
    static const Color colors[12] =
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

    auto triangles0 = cube0.GetTriangles();
    const Mat3 rotation0 =
        Mat3::RotateX(rot_x) *
        Mat3::RotateY(rot_y) *
        Mat3::RotateZ(rot_z);

    auto triangles1 = cube1.GetTriangles();
    const Mat3 rotation1 =
        Mat3::RotateX(-rot_x) *
        Mat3::RotateY(rot_y) *
        Mat3::RotateZ(rot_z);

    for (auto& v : triangles0.vertices)
    {
        v *= rotation0;
        v += {0.0f, 0.0f, 2.0f};
    }

    for (auto& v : triangles1.vertices)
    {
        v *= rotation1;
        v += {0.0f, 0.0f, zOffset};
    }

    for (size_t i = 0, end = triangles0.indices.size() / 3; i < end; i++)
    {
        const auto v0 = triangles0.vertices[triangles0.indices[i * 3]];
        const auto v1 = triangles0.vertices[triangles0.indices[i * 3 + 1]];
        const auto v2 = triangles0.vertices[triangles0.indices[i * 3 + 2]];
        triangles0.cullFlags[i] = (v1 - v0).cross(v2 - v0).dot(v0) >= 0.0f;
    }

    for (size_t i = 0, end = triangles1.indices.size() / 3; i < end; i++)
    {
        const auto v0 = triangles1.vertices[triangles1.indices[i * 3]];
        const auto v1 = triangles1.vertices[triangles1.indices[i * 3 + 1]];
        const auto v2 = triangles1.vertices[triangles1.indices[i * 3 + 2]];
        triangles1.cullFlags[i] = (v1 - v0).cross(v2 - v0).dot(v0) >= 0.0f;
    }

    for (auto& v : triangles0.vertices)
        transformer.Translate(v);

    for (auto& v : triangles1.vertices)
        transformer.Translate(v);

    for (size_t i = 0, end = triangles0.indices.size() / 3; i < end; i++)
    {
        if (!triangles0.cullFlags[i])
            gfx.DrawTriangle(triangles0.vertices[triangles0.indices[i * 3]], triangles0.vertices[triangles0.indices[i * 3 + 1]], triangles0.vertices[triangles0.indices[i * 3 + 2]], colors[i]);
    }

    for (size_t i = 0, end = triangles1.indices.size() / 3; i < end; i++)
    {
        if (!triangles1.cullFlags[i])
            gfx.DrawTriangle(triangles1.vertices[triangles1.indices[i * 3]], triangles1.vertices[triangles1.indices[i * 3 + 1]], triangles1.vertices[triangles1.indices[i * 3 + 2]], colors[i]);
    }
}
