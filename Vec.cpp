#include "Vec.h"
#include <cmath>

template <typename T>
template <typename B>
Vec2d<T>::Vec2d(const Vec2d<B>& other)
    :
    x(T(other.x)),
    y(T(other.y))
{
}

template <typename T>
Vec2d<T>::Vec2d(T x, T y)
     :
     x(x),
     y(y) 
{
}

template <typename T>
Vec2d<T>::Vec2d(const Vec2d<T>& other)
    :
    Vec2d(other.x, other.y)
{
}

template <typename T>
Vec2d<T>& Vec2d<T>::operator =(const Vec2d<T>& rhs)
{
    x = rhs.x;
    y = rhs.y;
    return *this;
}

template <typename T>
Vec2d<T>& Vec2d<T>::operator =(const Vec2d&& rhs)
{
    return *this = rhs;
}

template <typename T>
Vec2d<T>::Vec2d(const Vec2d<T>&& other)
    : 
    Vec2d(other)
{
}

template <typename T>
Vec2d<T> Vec2d<T>::operator -(const Vec2d<T>& rhs) const
{
    return Vec2d<T>(x - rhs.x, y - rhs.y);
}

template <typename T>
Vec2d<T> Vec2d<T>::operator -() const
{
    return Vec2d<T>(-x, -y);
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
Vec2d<T> Vec2d<T>::operator *(const T& rhs) const
{
    return Vec2d<T>(x * rhs, y * rhs);
}

template <typename T>
T Vec2d<T>::operator *(const Vec2d<T>& other) const
{
    return (x * other.x + y * other.y);
}

template <typename T>
Vec2d<T>& Vec2d<T>::operator *=(const T& rhs)
{
    return *this = *this * rhs;
}

template <typename T>
Vec2d<T> Vec2d<T>::operator /(const T& rhs) const
{
    return Vec2d<T>(x / rhs, y / rhs);
}

template <typename T>
Vec2d<T>& Vec2d<T>::operator /=(const T& rhs)
{
    return *this = *this / rhs;
}

template <typename T>
bool Vec2d<T>::operator ==(const Vec2d<T>& rhs) const
{
    return (x == rhs.x && y == rhs.y);
}

template <typename T>
bool Vec2d<T>::operator !=(const Vec2d<T>& rhs) const
{
    return !(*this == rhs);
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
    return !(*this <= rhs);
}

template <typename T>
bool Vec2d<T>::operator >=(const Vec2d<T>& rhs) const
{
    return (*this > rhs || *this == rhs);
}

template <typename T>
Vec2d<T>& Vec2d<T>::Rotate(T theta)
{
    const auto cosTheta = cos(theta);
    const auto sinTheta = sin(theta);

    const auto new_x = x * cosTheta - y * sinTheta;
    y = x * sinTheta + y * cosTheta;
    x = new_x;

    return *this;
}

template <typename T>
Vec2d<T> Vec2d<T>::GetRotated(T theta)
{
    return Vec2d<T>(*this).Rotate(theta);
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
Vec2d<T>& Vec2d<T>::Normalize()
{
    T norm = GetDistance();
    if( norm != 0 )
    {
        norm = 1 / norm;
        return {x * norm, y * norm};
    }
    return *this;
}

template <typename T>
Vec2d<T> Vec2d<T>::GetNormalized() const
{
    return Vec2d<T>(*this).GetNormalized();
}
