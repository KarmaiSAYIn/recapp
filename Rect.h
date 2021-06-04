#pragma once
#include "Vec.h"

/* Class representing a Rectangle; all of the methods assume that the standard
 * coordinate system is used e.g. y is positive leading upwards,
 * as opposed to screen coordinates.
 */
template <typename T>
class Rect
{
public:
    Rect() = default;
    Rect(const Vec2d<T>& topLeft, const Vec2d<T>& bottomRight);
    Rect(T left, T right, T top, T bottom);
    Rect(const Vec2d<T>& topLeft, T width, T height);
    Rect(Rect&& other);

    Rect(const Rect& other);
    template <typename E>
    Rect(const Rect<E>& other);

    Rect& operator =(const Rect& other);
    Rect& operator =(const Rect&& other);


    Vec2d<T> GetTopLeft() const;
    Vec2d<T> GetBottomRight() const;
    Vec2d<T> GetMiddle() const;
    T GetWidth() const;
    T GetHeight() const;
    T GetLeft() const;
    T GetRight() const;
    T GetTop() const;
    T GetBottom() const;

    void Translate(const Vec2d<T>& offset);
    void Scale(float scale);
    void SetMiddle(const Vec2d<T>& middle);
    void SetTopLeft(const Vec2d<T>& topLeft);
    void SetBottomRight(const Vec2d<T>& bottomRight);

    template <typename E>
    bool CollideRect(const Rect<E>& other) const;
    template <typename E>
    bool IsContainedBy(const Rect<E>& other) const;

private:
    Vec2d<T> topLeft = {0, 0};
    Vec2d<T> bottomRight = {0, 0};
};

#include "Rect.cpp"

using Rectf = Rect<float>;
using Recti = Rect<int>;
