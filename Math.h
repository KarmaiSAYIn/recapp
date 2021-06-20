#pragma once
#include "Vec.h"

static constexpr double PI_D = 3.141592653589793238462643383279;
static constexpr float PI = (float)PI_D;

template <typename T>
T sq(T n)
{
    return n * n;
}
 
template <typename T>
T DistancePointLine(const Vec2d<T>& point, const Vec2d<T>& p0, const Vec2d<T>& p1)
{
    const T a = (p0.y - p1.y);
    const T b = (p1.x - p0.x);
    const T c = p0.x * p1.y - p1.x * p0.y;

    return std::abs(a * point.x + b * point.y + c) / std::sqrt(sq(a) + sq(b));
}

template <typename T>
T wrap_angle(T theta)
{
    theta = std::fmod(theta, (T)2 * (T)PI_D);
    return theta > (T)PI_D ? theta - (T)2 * (T)PI_D : theta;
}
