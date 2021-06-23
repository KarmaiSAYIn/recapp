#include "Matrix.h"

template <typename T>
Vec3d<T> Matrix3d<T>::operator *(const Vec3d<T>& v) const
{
    Vec3d<T> result;
    result.x = m[0][0] * v.x + m[1][0] * v.y + m[2][0] * v.z;
    result.y = m[0][1] * v.x + m[1][1] * v.y + m[2][1] * v.z;
    result.z = m[0][2] * v.x + m[1][2] * v.y + m[2][2] * v.z;
    return result;
}

template <typename T>
Vec2d<T> Matrix3d<T>::operator *(const Vec2d<T>& v) const
{
    return Vec2d<T>(*this * Vec3d<T>(v));
}

template <typename T>
Matrix3d<T> Matrix3d<T>::operator *(const Matrix3d<T>& rhs) const
{
    Matrix3d<T> result;
    for (int row_left = 0; row_left < 3; row_left++)
    {
        for (int col_right = 0; col_right < 3; col_right++)
        {
            for (int i = 0; i < 3; i++)
            {
                result.m[row_left][col_right] += m[row_left][i] * rhs.m[i][col_right];
            }
        }
    }
    return result;
}

template <typename T>
Matrix3d<T> Matrix3d<T>::Identity()
{
    return {
        (T)1, (T)0, (T)0,
        (T)0, (T)1, (T)0,
        (T)0, (T)0, (T)1
    };
}

template <typename T>
Matrix3d<T> Matrix3d<T>::RotateX(const T& theta)
{
    const T cosTheta = cos(theta);
    const T sinTheta = sin(theta);

    return {
        (T)1, (T)0,      (T)0,
        (T)0, cosTheta,  sinTheta,
        (T)0, -sinTheta, cosTheta
    };
}

template <typename T>
Matrix3d<T> Matrix3d<T>::RotateY(const T& theta)
{
    const T cosTheta = cos(theta);
    const T sinTheta = sin(theta);

    return {
        cosTheta, (T)0, -sinTheta,
        (T)0,     (T)1, (T)0,
        sinTheta, (T)0, cosTheta 
    };
}

template <typename T>
Matrix3d<T> Matrix3d<T>::RotateZ(const T& theta)
{
    const T cosTheta = cos(theta);
    const T sinTheta = sin(theta);

    return {
        cosTheta, sinTheta,  (T)0,
        -sinTheta, cosTheta, (T)0,
        (T)0,     (T)0,      (T)1
    };
}

template <typename T>
Matrix3d<T> Matrix3d<T>::FlipX()
{
    return{
        (T)-1, (T)0, (T)0,
        (T)0,  (T)1, (T)0,
        (T)0,  (T)0, (T)1
    };
}

template <typename T>
Matrix3d<T> Matrix3d<T>::FlipY()
{
    return{
        (T)1, (T)0,  (T)0,
        (T)0, (T)-1, (T)0,
        (T)0, (T)0,  (T)1

    };
}

template <typename T>
Matrix3d<T> Matrix3d<T>::FlipZ()
{
    return{
        (T)1, (T)0,  (T)0,
        (T)0, (T)1,  (T)0,
        (T)0, (T)0,  (T)-1

    };
}

template <typename T>
Matrix3d<T> Matrix3d<T>::Scale(const T& scale)
{
    return{
        (T)scale, (T)0,     (T)0,
        (T)0,     (T)scale, (T)0,
        (T)0,     (T)0,     (T)scale
    };
}

template <typename T>
Matrix3d<T> Matrix3d<T>::Translate(const Vec3d<T>& offset)
{
    return {
        (T)1, (T)0, offset.x,
        (T)0, (T)1, offset.y,
        (T)0, (T)0, offset.z
    };
}

template <typename T>
Vec3d<T> operator *(const Vec3d<T>& v, const Matrix3d<T>& mat)
{
    return mat * v;
}

template <typename T>
Vec3d<T>& operator *=(Vec3d<T>& v, const Matrix3d<T>& mat)
{
    return v = v * mat;
}

template <typename T>
Vec2d<T> operator *(const Vec2d<T>& v, const Matrix3d<T>& mat)
{
    return Vec2d<T>(Vec3d<T>(v) * mat);
}

template <typename T>
Vec2d<T>& operator *=(Vec2d<T>& v, const Matrix3d<T>& mat)
{
    return v = v * mat;
}
