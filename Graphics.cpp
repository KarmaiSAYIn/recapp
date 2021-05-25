#include "Graphics.h"
#include "Game.h"
#include <assert.h>

void Graphics::SetGameObject(Game *engine)
{
    this->engine = engine;
}

int Graphics::GetScreenHeight() const
{
    return engine->ScreenHeight();
}

int Graphics::GetScreenWidth() const
{
    return engine->ScreenWidth();
}

void Graphics::PutPixel(int x, int y, Color c)
{
    assert(x < GetScreenWidth() && y < GetScreenHeight());
    engine->Draw(x, y, c);
}

void Graphics::PutPixel(Vei2 pos, Color c)
{
        assert(pos.x < GetScreenWidth() && pos.y < GetScreenHeight());
        PutPixel(pos.x, pos.y, c);
}

Color Graphics::GetPixel(int x, int y) const
{
        assert(x < GetScreenWidth() && y < GetScreenHeight());
            return Color((engine->GetPixelAt(x, y)));
}

Color Graphics::GetPixel(Vei2 pos) const
{
        assert(pos.x < GetScreenWidth() && pos.y < GetScreenHeight());
            return Color(GetPixel(pos.x, pos.y));
}


void Graphics::DrawLine(Vei2 p0, Vei2 p1, Color c)
{

}

void Graphics::DrawCircle(Vei2 center, int radius, Color c)
{
    Vei2 topLeft = center - Vei2(radius, radius);
    Vei2 bottomRight = center + Vei2(radius, radius);

    for (int y = 0; y <= bottomRight.y; ++y)
        for (int x = 0; x <= bottomRight.x; ++x)
            if ((Vei2(x, y) - center).GetDistanceSq() <= radius * radius )
                PutPixel(x, y, c);
}
