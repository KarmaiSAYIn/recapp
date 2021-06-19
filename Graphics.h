#pragma once
#include "Vec.h"
#include "Color.h"
#include "Game.h"
#include "Rect.h"
#include "Matrix.h"

class Graphics final
{
public:
    Graphics() = default;
    ~Graphics() = default;

    Graphics(const Graphics&) = delete;
    Graphics(Graphics&&) = delete;

    void SetGameObject(Game *game);

    void PutPixel(int x, int y, Color c);  //In principal, this function modifies the Graphics object; however at this stage it could be a const declarator.
    void PutPixel(const Vei2& pos, Color c);
    Color GetPixel(int x, int y) const;
    Color GetPixel(const Vei2& pos) const;
    Recti GetRect() const;
    void Clear(Color c = Colors::Black);

    // Shape draw functions
    void DrawLine(Vec2 p0, Vec2 p1, Color c);
    void DrawClosedPolyline(const std::vector<Vec2>& vertices, const Mat3& transformations, Color c);
    void DrawCircle(const Vei2& center, int radius, Color c);
    void DrawRect(const Recti& rect, Color c);

private:
    Game *game = nullptr;

public:
    static constexpr int ScreenWidth = 720;
    static constexpr int ScreenHeight = 720;
};


