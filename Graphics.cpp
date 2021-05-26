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

void Graphics::DrawLine(Vei2 p0, Vei2 p1, Color c)
{

}

void Graphics::DrawCircle(Vei2 center, int radius, Color c)
{
    Vei2 topLeft = center - Vei2(radius, radius) + Vei2(1 , 1);
    Vei2 bottomRight = center + Vei2(radius, radius) - Vei2(1, 1);

    for (int y = topLeft.y; y <= bottomRight.y; ++y)
        for (int x = topLeft.x; x <= bottomRight.x; ++x)
            if ((Vei2(x, y) - center).GetDistanceSq() <= radius * radius && (x >= 0 && x < GetScreenWidth() && y >= 0 && y < GetScreenHeight()))
                PutPixel(x, y, c);
}
