#pragma once
#include "Vec.h"
#include "Color.h"
#include "Game.h"

class Graphics final
{
public:
    Graphics() = delete;
    Graphics(Game *engine);
    ~Graphics() = default;

    Graphics(const Graphics&) = delete;
    Graphics& operator=(const Graphics&) = delete;

    int GetScreenHeight() const;
    int GetScreenWidth() const;

    void PutPixel(int x, int y, Color c);  //In principal, this function modifies the Graphics object; however at this stage it could be a const declarator.
    void PutPixel(Vei2 pos, Color c);
    Color GetPixel(int x, int y) const;
    Color GetPixel(Vei2 pos) const;

private:

    Game *engine;
};


