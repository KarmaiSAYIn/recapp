#pragma once
#include "Vec.h"

template <typename T>
class Rect
{
public:
    Rect() = default;
    Rect(const Vec2d<T>& topLeft, const Vec2d<T>& bottomRight);
    Rect(T left, T right, T top, T bottom);

    Vec2d<T> GetTopLeft() const;
    Vec2d<T> GetBottomRight() const;
    Vec2d<T> GetMiddle() const;
    T GetLeft() const;
    T GetRight() const;
    T GetTop() const;
    T GetBottom() const;

    void SetTopLeft(const Vec2d<T>& topLeft);
    void SetBottomRight(const Vec2d<T>& bottomRight);
    void SetMiddle(const Vec2d<T>& middle);

    template <typename E>
    bool CollideRect(Rect<E> other) const;

private:
    Vec2d<T> topLeft = {0, 0};
    Vec2d<T> bottomRight = {0, 0};
};

#include "Rect.cpp"

using Rectf = Rect<float>;
using Recti = Rect<int>;
