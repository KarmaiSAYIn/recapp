#include "Graphics.h"
#include "Game.h"
#include <assert.h>
#include <iostream>

Graphics::Graphics(Game *engine)
    :
    engine(engine)
{
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
    engine->Draw(x, y, static_cast<olc::Pixel>(c));
}

void Graphics::PutPixel(Vei2 pos, Color c)
{
        assert(pos.x < GetScreenWidth() && pos.y < GetScreenHeight());
        PutPixel(pos.x, pos.y, c);
}

Color Graphics::GetPixel(int x, int y) const
{
        assert(x < GetScreenWidth() && y < GetScreenHeight());
            return static_cast<Color>(engine->GetPixelAt(x, y));
}

Color Graphics::GetPixel(Vei2 pos) const
{
        assert(pos.x < GetScreenWidth() && pos.y < GetScreenHeight());
            return static_cast<Color>(GetPixel(pos.x, pos.y));
}
