#pragma once
#include "Vec.h"

template <typename T>
struct Matrix3d
{
    Matrix3d() = default;
    Vec3d<T> operator *(const Vec3d<T>& v) const;
    Vec2d<T> operator *(const Vec2d<T>& v) const;
    Matrix3d operator *(const Matrix3d& rhs) const;
    static Matrix3d Identity();
    static Matrix3d Rotate(const T& theta);
    static Matrix3d FlipX();
    static Matrix3d FlipY();
    static Matrix3d FlipZ();
    static Matrix3d Scale(const T& scale);
    static Matrix3d Translate(const Vec3d<T>& offset);

    T m[3][3] {(T)0};
};

using Mat3 = Matrix3d<float>;
using Mad3 = Matrix3d<double>;

template <typename T>
Vec3d<T> operator *(const Vec3d<T>& v, const Matrix3d<T>& mat);
template <typename T>
Vec3d<T>& operator *=(Vec3d<T>& v, const Matrix3d<T>& mat);
template <typename T>
Vec2d<T> operator *(const Vec2d<T>& v, const Matrix3d<T>& mat);
template <typename T>
Vec2d<T>& operator *=(Vec2d<T>& v, const Matrix3d<T>& mat);

#include "Matrix.cpp"
