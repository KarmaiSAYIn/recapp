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

template<typename T>
Rect<T>::Rect(const Vec2d<T>& midPoint, T width, T height)
{
    const T halfWidth = width / 2;
    const T halfHeight = height / 2;
    topLeft = Vec2d<T>(midPoint.x - halfWidth, midPoint.y + halfHeight);
    bottomRight = Vec2d<T>(midPoint.x + halfWidth, midPoint.y - halfHeight);
}

template <typename T>
Rect<T>::Rect(Rect<T>&& other)
    :
    Rect(other)
{
}

template <typename T>
Rect<T>& Rect<T>::operator =(const Rect<T>& other)
{
    topLeft = other.topLeft;
    bottomRight = other.bottomRight;
    return *this;
}

template <typename T>
Rect<T>& Rect<T>::operator =(const Rect<T>&& other)
{
    return *this = other;
}

template<typename T>
Rect<T>::Rect(const Rect& other)
    :
    Rect(other.GetLeft(), other.GetRight(), other.GetTop(), other.GetBottom())
{
}

template <typename T>
template <typename E>
Rect<T>::Rect(const Rect<E>& other)
    :
    Rect((T)other.GetLeft(), (T)other.GetRight(), (T)other.GetTop(), (T)other.GetBottom())
{
}

template <typename T>
Vec2d<T> Rect<T>::GetTopLeft() const
{
    return topLeft;
}

template <typename T>
Vec2d<T> Rect<T>::GetBottomRight() const
{
    return bottomRight;
}

template <typename T>
Vec2d<T> Rect<T>::GetMiddle() const
{
    return Vec2d<T>(topLeft.x + GetWidth() / 2, bottomRight.y + GetHeight() / 2);
}

template<typename T>
T Rect<T>::GetWidth() const
{
    return bottomRight.x - topLeft.x;
}

template<typename T>
T Rect<T>::GetHeight() const
{
    return topLeft.y - bottomRight.y;
}


template <typename T>
T Rect<T>::GetLeft() const
{
    return topLeft.x;
}

template <typename T>
T Rect<T>::GetRight() const
{
    return bottomRight.x;
}

template <typename T>
T Rect<T>::GetTop() const
{
    return topLeft.y;
}

template <typename T>
T Rect<T>::GetBottom() const
{
    return bottomRight.y;
}

template<typename T>
void Rect<T>::Translate(const Vec2d<T>& offset)
{
    topLeft += offset;
    bottomRight += offset;
}

template<typename T>
void Rect<T>::Scale(T scale)
{
    topLeft *= scale;
    bottomRight*= scale;
}

template<typename T>
void Rect<T>::SetMiddle(const Vec2d<T>& middle)
{
    Vec2d<T> normalizedMidPoint(GetWidth() / 2, GetHeight() / 2 * -1);

    topLeft = middle - normalizedMidPoint;
    bottomRight = middle + normalizedMidPoint;
}

template <typename T>
void Rect<T>::SetTopLeft(const Vec2d<T>& topLeft)
{
    this->topLeft = topLeft;
}

template <typename T>
void Rect<T>::SetBottomRight(const Vec2d<T>& bottomRight)
{
    this->bottomRight = bottomRight;
}

template <typename T>
template <typename E>
bool Rect<T>::CollideRect(const Rect<E>& other) const
{
    return (GetLeft() <= other.GetRight() && GetTop() >= other.GetBottom() && GetRight() >= other.GetLeft() && GetBottom() <= other.GetTop());
}

template <typename T>
template <typename E>
bool Rect<T>::CollidePoint(const Vec2d<E>& point) const
{
    return ((T)point.x >= GetLeft() && (T)point.x <= GetRight() && (T)point.y <= GetTop() && (T)point.y >= GetBottom());
}

template <typename T>
template <typename E>
bool Rect<T>::IsContainedBy(const Rect<E>& other) const
{
    return (GetRight() <= other.GetRight() && GetBottom() >= other.GetBottom() && GetLeft() >= other.GetLeft() && GetTop() <= other.GetTop());
}


