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
Vec2d<T> Vec2d<T>::GetRotated(T theta) const
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
        x = x * norm;
        y = y * norm;
    }
    return *this;
}

template <typename T>
Vec2d<T> Vec2d<T>::GetNormalized() const
{
    return Vec2d<T>(*this).Normalize();
}

// O------------------------------------------------------------------------------O
// | Vec3d Definitions                                                            |
// O------------------------------------------------------------------------------O

template <typename T>
template <typename B>
Vec3d<T>::Vec3d(const Vec3d<B>& other)
    :
    x(T(other.x)),
    y(T(other.y)),
    z(T(other.z))
{
}

template <typename T>
Vec3d<T>::Vec3d(T x, T y, T z)
     :
     x(x),
     y(y),
     z(z)
{
}

template <typename T>
Vec3d<T>::Vec3d(const Vec3d<T>& other)
    :
    Vec3d(other.x, other.y, other.z)
{
}  

template <typename T>
Vec3d<T>::Vec3d(const Vec2d<T>& other)
    :
    x(other.x),
    y(other.y)
{
}

template <typename T>
Vec3d<T>::operator Vec2d<T>()
{
    return Vec2d<T>(x, y);
}

template <typename T>
Vec3d<T>& Vec3d<T>::operator =(const Vec3d<T>& rhs)
{
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
}

template <typename T>
Vec3d<T>& Vec3d<T>::operator =(const Vec3d&& rhs)
{
    return *this = rhs;
}

template <typename T>
Vec3d<T>::Vec3d(const Vec3d<T>&& other)
    : 
    Vec3d(other)
{
}

template <typename T>
Vec3d<T> Vec3d<T>::operator -(const Vec3d<T>& rhs) const
{
    return Vec3d<T>(x - rhs.x, y - rhs.y, z - rhs.z);
}

template <typename T>
Vec3d<T> Vec3d<T>::operator -() const
{
    return Vec3d<T>(-x, -y, -z);
}

template <typename T>
Vec3d<T>& Vec3d<T>::operator -=(const Vec3d<T>& rhs)
{
    return *this = *this - rhs;
}

template <typename T>
Vec3d<T> Vec3d<T>::operator +(const Vec3d<T>& rhs) const
{
    return Vec3d<T>(x + rhs.x, y + rhs.y, z + rhs.z);
}

template <typename T>
Vec3d<T>& Vec3d<T>::operator +=(const Vec3d<T>& rhs)
{
    return *this = *this + rhs;
}

template <typename T>
Vec3d<T> Vec3d<T>::operator *(const T& rhs) const
{
    return Vec3d<T>(x * rhs, y * rhs, z * rhs);
}

template <typename T>
T Vec3d<T>::operator *(const Vec3d<T>& other) const
{
    return (x * other.x + y * other.y + z * other.z);
}

template <typename T>
Vec3d<T>& Vec3d<T>::operator *=(const T& rhs)
{
    return *this = *this * rhs;
}

template <typename T>
Vec3d<T> Vec3d<T>::operator /(const T& rhs) const
{
    return Vec3d<T>(x / rhs, y / rhs, z / rhs);
}

template <typename T>
Vec3d<T>& Vec3d<T>::operator /=(const T& rhs)
{
    return *this = *this / rhs;
}

template <typename T>
bool Vec3d<T>::operator ==(const Vec3d<T>& rhs) const
{
    return (x == rhs.x && y == rhs.y && z == rhs.z);
}

template <typename T>
bool Vec3d<T>::operator !=(const Vec3d<T>& rhs) const
{
    return !(*this == rhs);
}

template <typename T>
bool Vec3d<T>::operator <(const Vec3d<T>& rhs) const
{
    return (x < rhs.x && y < rhs.y && z < rhs.z);
}

template <typename T>
bool Vec3d<T>::operator <=(const Vec3d<T>& rhs) const
{
    return (*this < rhs || *this == rhs);
}

template <typename T>
bool Vec3d<T>::operator >(const Vec3d<T>& rhs) const
{
    return !(*this <= rhs);
}

template <typename T>
bool Vec3d<T>::operator >=(const Vec3d<T>& rhs) const
{
    return (*this > rhs || *this == rhs);
}

template <typename T>
Vec3d<T>& Vec3d<T>::Rotate(T theta) // Don't know how to rotate in 3D yet.
{
    //const auto cosTheta = cos(theta);
    //const auto sinTheta = sin(theta);

    //const auto new_x = x * cosTheta - y * sinTheta;
    //y = x * sinTheta + y * cosTheta;
    //x = new_x;

    return *this;
}

//template <typename T>
//Vec3d<T> Vec3d<T>::GetRotated(T theta) const
//{
    //return Vec3d<T>(*this).Rotate(theta);
//}

template <typename T>
T Vec3d<T>::GetDistanceSq() const
{
    return T(x * x + y * y + z * z);
}

template <typename T>
T Vec3d<T>::GetDistance() const
{
    return std::sqrt(GetDistanceSq());
}

template <typename T>
Vec3d<T>& Vec3d<T>::Normalize()
{
    T norm = GetDistance();
    if( norm != 0 )
    {
        norm = 1 / norm;
        x = x * norm;
        y = y * norm;
        z = z * norm;
    }
    return *this;
}

template <typename T>
Vec3d<T> Vec3d<T>::GetNormalized() const
{
    return Vec3d<T>(*this).Normalize();
}
