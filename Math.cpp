#include "Math.h"
#include <cmath>

template <typename T>
T sq(T n)
{
    return n * n;
}

template <typename T>
T DistancePointLine(const Vec2d<T>& point, const Vec2d<T>& p0, const Vec2d<T>& p1)
{
    const T a = (p1.y - p0.y);
    const T b = (p1.x - p0.x);
    const T c = p1.x * p0.y - p1.y * p0.x;

    return std::abs(a * point.x + b * point.y + c) / std::sqrt(sq(a) + sq(b));
}
