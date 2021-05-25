#include "Vec.h"

template <typename T>
Vec2d<T> Vec2d<T>::operator -(const Vec2d<T>& rhs) const
{
    return Vec2d<T>(x - rhs.x, y -rhs.y);
}

template <typename T>
Vec2d<T>& Vec2d<T>::operator -=(const Vec2d<T>& rhs)
{
    return *this = *this - rhs;
}

template <typename T>
Vec2d<T> Vec2d<T>::operator +(const Vec2d<T>& rhs) const
{
    return Vec2d<T>(x + rhs.x, y + rhs.y);
}

template <typename T>
Vec2d<T>& Vec2d<T>::operator +=(const Vec2d<T>& rhs)
{
    return *this = *this + rhs;
}

template <typename T>
Vec2d<T> Vec2d<T>::operator *(const Vec2d<T>& rhs) const
{
    return Vec2d<T>(x * rhs.x, y * rhs.y);
}

template <typename T>
Vec2d<T>& Vec2d<T>::operator *=(const Vec2d<T>& rhs)
{
    return *this = *this * rhs;
}

template <typename T>
Vec2d<T> Vec2d<T>::operator /(const Vec2d<T>& rhs) const
{
    return Vec2d<T>(x / rhs.x, y / rhs.y);
}

template <typename T>
Vec2d<T>& Vec2d<T>::operator /=(const Vec2d<T>& rhs)
{
    return *this = *this / rhs;
}

template <typename T>
bool Vec2d<T>::operator <(const Vec2d<T>& rhs) const
{
    return (x < rhs.x && y < rhs.y);
}

template <typename T>
bool Vec2d<T>::operator <=(const Vec2d<T>& rhs) const
{
    return (*this < rhs || *this == rhs);
}

template <typename T>
bool Vec2d<T>::operator >(const Vec2d<T>& rhs) const
{
}

template <typename T>
T Vec2d<T>::GetDistanceSq() const
{
    return T(x * x + y * y);
}

template <typename T>
T Vec2d<T>::GetDistance() const
{
    return std::sqrt(GetDistanceSq());
}

template <typename T>
Vec2d<T> Vec2d<T>::GetNormailzed() const
{
    T norm = 1 / GetDistanceSq();
    return Vec2d<T>(x * norm, y * norm);
}
