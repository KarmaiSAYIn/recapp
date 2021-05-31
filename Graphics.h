#pragma once
#include "Vec.h"
#include "Color.h"
#include "Game.h"

class Graphics final
{
public:
    Graphics() = default;
    ~Graphics() = default;

    Graphics(const Graphics&) = delete;
    Graphics& operator=(const Graphics&) = delete;

    void SetGameObject(Game *game);

    int GetScreenHeight() const;
    int GetScreenWidth() const;

    void PutPixel(int x, int y, Color c);  //In principal, this function modifies the Graphics object; however at this stage it could be a const declarator.
    void PutPixel(Vei2 pos, Color c);
    Color GetPixel(int x, int y) const;
    Color GetPixel(Vei2 pos) const;
    void Clear(Color c);

    // Shape draw functions
    void DrawLine(Vec2 p0, Vec2 p1, Color c);
    void DrawClosedPolyline(const std::vector<Vec2>& vertices, Color c);
    void DrawCircle(Vei2 center, int radius, Color c);

private:

    Game *game = nullptr;
};


