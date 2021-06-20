#pragma once

template <typename T>
class Vec2d final
{
public:
    Vec2d() = default;
    Vec2d(T x, T y);
    Vec2d(const Vec2d& other);
    Vec2d& operator =(const Vec2d& rhs);
    Vec2d& operator =(const Vec2d&& rhs);
    Vec2d(const Vec2d&& other);
    ~Vec2d() = default;

    template <typename E>
    Vec2d(const Vec2d<E>& other);

    T x = 0;
    T y = 0;

    Vec2d operator -(const Vec2d& rhs) const;
    Vec2d operator -() const;
    Vec2d& operator -=(const Vec2d& rhs);
    Vec2d operator +(const Vec2d& rhs) const;
    Vec2d& operator +=(const Vec2d& rhs);
    Vec2d operator *(const T& rhs) const;
    T operator *(const Vec2d<T>& other) const;
    Vec2d& operator *=(const T& rhs);
    Vec2d operator /(const T& rhs) const;
    Vec2d& operator /=(const T& rhs);
    bool operator ==(const Vec2d<T>& rhs) const;
    bool operator !=(const Vec2d<T>& rhs) const;
    bool operator <(const Vec2d& rhs) const;
    bool operator <=(const Vec2d& rhs) const;
    bool operator >(const Vec2d& rhs) const;
    bool operator >=(const Vec2d<T>& rhs) const;
    Vec2d& Rotate(T theta);
    Vec2d GetRotated(T theta) const;
    T GetDistanceSq() const;
    T GetDistance() const;
    Vec2d& Normalize();
    Vec2d GetNormalized() const;
};

using Vei2 = Vec2d<int>;
using Vec2 = Vec2d<float>;

/* Vec3d class only for the use of translations within using matrix multiplication; where you need a 3x3 matrix and a 3D vector.
 * Later this will become a genuine 3D vector class.
 */
template <typename T>
class Vec3d final
{
public:
    Vec3d() = default;
    Vec3d(T x, T y, T z = 0);
    Vec3d(const Vec3d& other);
    Vec3d& operator =(const Vec3d& rhs);
    Vec3d& operator =(const Vec3d&& rhs);
    Vec3d(const Vec3d&& other);
    ~Vec3d() = default;

    template <typename E>
    Vec3d(const Vec3d<E>& other);

    T x = 0;
    T y = 0;
    T z = 0;

    Vec3d(const Vec2d<T>& other);
    operator Vec2d<T>();

    Vec3d operator -(const Vec3d& rhs) const;
    Vec3d operator -() const;
    Vec3d& operator -=(const Vec3d& rhs);
    Vec3d operator +(const Vec3d& rhs) const;
    Vec3d& operator +=(const Vec3d& rhs);
    Vec3d operator *(const T& rhs) const;
    T operator *(const Vec3d<T>& other) const;
    Vec3d& operator *=(const T& rhs);
    Vec3d operator /(const T& rhs) const;
    Vec3d& operator /=(const T& rhs);
    bool operator ==(const Vec3d<T>& rhs) const;
    bool operator !=(const Vec3d<T>& rhs) const;
    bool operator <(const Vec3d& rhs) const;
    bool operator <=(const Vec3d& rhs) const;
    bool operator >(const Vec3d& rhs) const;
    bool operator >=(const Vec3d<T>& rhs) const;
    T GetDistanceSq() const;
    T GetDistance() const;
    Vec3d& Normalize();
    Vec3d GetNormalized() const;
};

#include "Vec.cpp"

using Vei3 = Vec3d<int>;
using Vec3 = Vec3d<float>;
