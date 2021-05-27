#include "Graphics.h"
#include "Game.h"
#include <assert.h>

void Graphics::SetGameObject(Game *game)
{
    this->game = game;
}

int Graphics::GetScreenHeight() const
{
    return game->ScreenHeight();
}

int Graphics::GetScreenWidth() const
{
    return game->ScreenWidth();
}

void Graphics::PutPixel(int x, int y, Color c)
{
    assert(x >= 0);
    assert(x < GetScreenWidth());
    assert(y >= 0);
    assert(y < GetScreenHeight());
    game->Draw(x, y, c);
}

void Graphics::PutPixel(Vei2 pos, Color c)
{
    PutPixel(pos.x, pos.y, c);
}

Color Graphics::GetPixel(int x, int y) const
{
    assert(x < GetScreenWidth() && y < GetScreenHeight());
        return Color((game->GetPixelAt(x, y)));
}

Color Graphics::GetPixel(Vei2 pos) const
{
    assert(pos.x < GetScreenWidth() && pos.y < GetScreenHeight());
        return Color(GetPixel(pos.x, pos.y));
}

void Graphics::Clear(Color c)
{
    game->Clear(c);
}

void Graphics::DrawLine(Vec2 p0, Vec2 p1, Color c)
{
    float m = 0.0f;
    if (p0 != p1)
        m = (p1.y - p0.y) / (p1.x - p0.x);

    if (p0 != p1 && std::abs(m) <= 1.0f)
    {
        if (p0.x > p1.x)
            std::swap(p0, p1);

        const float b = p0.y - m * p0.x;

        for (int x = (int)p0.x; x <= int(p1.x + 0.5f); ++x)
        {
            const float y = m * (float)x + b;
            PutPixel(x, (int)y, c);
        }
    }
    else
    {
        if (p0.y > p1.y)
            std::swap(p0, p1);

        const float w = (p1.x - p0.x) / (p1.y - p0.y);
        const float p = p0.x - w * p0.y;

        for (int y = (int)p0.y; y <= int(p1.y + 0.5f); ++y)
        {
            const float x = w * (float)y + p;
            PutPixel((int)x, y, c);
        }
    }
}

void Graphics::DrawCircle(Vei2 center, int radius, Color c)
{
    Vei2 topLeft = center - Vei2(radius, radius) + Vei2(1 , 1);
    Vei2 bottomRight = center + Vei2(radius, radius) - Vei2(1, 1);

    for (int y = topLeft.y; y <= bottomRight.y; ++y)
        for (int x = topLeft.x; x <= bottomRight.x; ++x)
            if ((Vei2(x, y) - center).GetDistanceSq() <= radius * radius)
                PutPixel(x, y, c);
}
