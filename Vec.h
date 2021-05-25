#pragma once
#include <cmath>

template <typename T>
class Vec2d
{
public:
    Vec2d(T x, T y) : x(x), y(y) {}

    T x = 0;
    T y = 0;

    Vec2d operator -(const Vec2d& rhs) const
    {
        return Vec2d(x - rhs.x, y -rhs.y);
    }
    
    Vec2d& operator -=(const Vec2d& rhs)
    {
        return *this = *this - rhs;
    }

    Vec2d operator +(const Vec2d& rhs) const
    {
        return Vec2d(x + rhs.x, y + rhs.y);
    }

    Vec2d& operator +=(const Vec2d& rhs)
    {
        return *this = *this + rhs;
    }

    Vec2d operator *(const Vec2d& rhs) const
    {
        return Vec2d(x * rhs.x, y * rhs.y);
    }

    Vec2d& operator *=(const Vec2d& rhs)
    {
        return *this = *this * rhs;
    }

    Vec2d operator /(const Vec2d& rhs) const
    {
        return Vec2d(x / rhs.x, y / rhs.y);
    }

    Vec2d& operator /=(const Vec2d& rhs)
    {
        return *this = *this / rhs;
    }

    T GetDistanceSq() const
    {
        return T(x * x + y * y);
    }

    T GetDistance() const
    {
        return std::sqrt(GetDistanceSq());
    }

    Vec2d GetNormailzed() const
    {
        T norm = 1 / GetDistanceSq();
        return Vec2d(x * norm, y * norm);
    }

};

using Vei2 = Vec2d<int>;
using Vec2 = Vec2d<float>;
