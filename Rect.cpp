#include "Rect.h"

template <typename T>
Rect<T>::Rect(const Vec2d<T>& topLeft, const Vec2d<T>& bottomRight)
    :
    topLeft(topLeft),
    bottomRight(bottomRight)
{
}

template <typename T>
Rect<T>::Rect(T left, T right, T top, T bottom)
    :
    Rect(Vec2d<T>(left, top), Vec2d<T>(right, bottom))
{
}

template <typename T>
Vec2d<T> Rect<T>::GetTopLeft() const
{
}

template <typename T>
Vec2d<T> Rect<T>::GetBottomRight() const
{
}

template <typename T>
Vec2d<T> Rect<T>::GetMiddle() const
{
}

template <typename T>
T Rect<T>::GetLeft() const
{
}

template <typename T>
T Rect<T>::GetRight() const
{
}

template <typename T>
T Rect<T>::GetTop() const
{
}

template <typename T>
T Rect<T>::GetBottom() const
{
}

template <typename T>
void Rect<T>::SetTopLeft(const Vec2d<T>& topLeft)
{
}

template <typename T>
void Rect<T>::SetBottomRight(const Vec2d<T>& bottomRight)
{
}

template <typename T>
void Rect<T>::SetMiddle(const Vec2d<T>& middle)
{
}

template <typename T>
template <typename E>
bool Rect<T>::CollideRect(Rect<E> other) const
{
}

