#pragma once
#include <cmath>

template <typename T>
class Vec2d
{
public:
    Vec2d(T x, T y) : x(x), y(y) {}

    T x = 0;
    T y = 0;

    Vec2d operator -(const Vec2d& rhs) const;
    Vec2d& operator -=(const Vec2d& rhs);
    Vec2d operator +(const Vec2d& rhs) const;
    Vec2d& operator +=(const Vec2d& rhs);
    Vec2d operator *(const Vec2d& rhs) const;
    Vec2d& operator *=(const Vec2d& rhs);
    Vec2d operator /(const Vec2d& rhs) const;
    Vec2d& operator /=(const Vec2d& rhs);
    bool operator <(const Vec2d& rhs) const;
    bool operator <=(const Vec2d& rhs) const;
    bool operator >(const Vec2d& rhs) const;
    T GetDistanceSq() const;
    T GetDistance() const;
    Vec2d GetNormailzed() const;
};

#include "Vec.cpp"

using Vei2 = Vec2d<int>;
using Vec2 = Vec2d<float>;
