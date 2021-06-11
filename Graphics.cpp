#include "Graphics.h"
#include <vector>
#include <assert.h>

void Graphics::SetGameObject(Game *game)
{
    assert(this->game == nullptr);
    this->game = game;
}

void Graphics::PutPixel(int x, int y, Color c)
{
    assert(x >= 0);
    assert(x < ScreenWidth);
    assert(y >= 0);
    assert(y < ScreenHeight);
    game->Draw(x, y, c);
}

void Graphics::PutPixel(const Vei2& pos, Color c)
{
    PutPixel(pos.x, pos.y, c);
}

Color Graphics::GetPixel(int x, int y) const
{
    assert(x >= 0);
    assert(x < ScreenWidth);
    assert(y >= 0);
    assert(y < ScreenHeight);
    return Color((game->GetPixelAt(x, y)));
}

Color Graphics::GetPixel(const Vei2& pos) const
{
    return Color(GetPixel(pos.x, pos.y));
}

Recti Graphics::GetRect() const
{
    return Recti(Vec2(0.0f, 0.0f), ScreenWidth, ScreenHeight);
}

void Graphics::Clear(Color c)
{
    game->Clear(c);
}

void Graphics::DrawLine(Vec2 p0, Vec2 p1, Color c)
{
    if ((Vei2)p0 == (Vei2)p1)
    {
        if (p0.x >= 0 && p0.x < ScreenWidth && p0.y >= 0 && p0.y < ScreenHeight)
            PutPixel(p0, c);
        return;
    }

    float m = 0.0f;
    if (p0 != p1)
        m = (p1.y - p0.y) / (p1.x - p0.x);

    if (p0 != p1 && std::abs(m) <= 1.0f)
    {
        if (p0.x > p1.x)
            std::swap(p0, p1);

        const float b = p0.y - m * p0.x;

        for (int x = (int)p0.x; x <= (int)p1.x; ++x)
        {
            const float y = m * (float)x + b;
            if (x >= 0 && x < ScreenWidth && y >= 0 && y < ScreenHeight)
                PutPixel(x, (int)y, c);
        }
    }
    else
    {
        if (p0.y > p1.y)
            std::swap(p0, p1);

        const float w = (p1.x - p0.x) / (p1.y - p0.y);
        const float p = p0.x - w * p0.y;

        for (int y = (int)p0.y; y < (int)p1.y; ++y)
        {
            const float x = w * (float)y + p;
            if (x >= 0 && x < ScreenWidth && y >= 0 && y < ScreenHeight)
                PutPixel((int)x, y, c);
        }
    }
}

void Graphics::DrawClosedPolyline(const std::vector<Vec2> &vertices, const Vec2 &translation, float scale_x, float scale_y, Color c)
{
    const auto transform = [&](Vec2 v)
    {
        v.x *= scale_x;
        v.y *= scale_y;
        v += translation;
        return v;
    };

    const Vec2 frontPoint = transform(vertices.front());
    Vec2 currPoint = frontPoint;
    for (auto i = vertices.begin(); i != std::prev(vertices.end()); i++) 
    {
        const Vec2 nextPoint = transform(*std::next(i));
        DrawLine(currPoint, nextPoint, c);
        currPoint = nextPoint;
    }
    DrawLine(currPoint, frontPoint, c);
}

void Graphics::DrawCircle(const Vei2& center, int radius, Color c)
{
    Vei2 topLeft = center - Vei2(radius, radius) + Vei2(1 , 1);
    Vei2 bottomRight = center + Vei2(radius, radius) - Vei2(1, 1);

    for (int y = topLeft.y; y <= bottomRight.y; ++y)
        for (int x = topLeft.x; x <= bottomRight.x; ++x)
            if ((Vei2(x, y) - center).GetDistanceSq() <= radius * radius)
                PutPixel(x, y, c);
}

void Graphics::DrawRect(const Recti& rect, Color c)
{
    Vei2 topLeft = rect.GetTopLeft();
    Vei2 bottomRight = rect.GetBottomRight();

    topLeft.x = std::clamp(topLeft.x, 0, ScreenWidth);
    topLeft.y = std::clamp(topLeft.y, 0, ScreenHeight);
    bottomRight.x = std::clamp(bottomRight.x, 0, ScreenWidth);
    bottomRight.y = std::clamp(bottomRight.y, 0, ScreenHeight);

    for (int y = bottomRight.y; y < topLeft.y; y++)
        for (int x = topLeft.x; x < bottomRight.x; x++)
            PutPixel(x, y, c);
}
