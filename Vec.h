#pragma once

template <typename T>
class Vec2d
{
public:
    Vec2d(T x, T y) : x(x), y(y) {}

    T x = 0;
    T y = 0;
};

using Vei2 = Vec2d<int>;
using Vec2 = Vec2d<float>;
