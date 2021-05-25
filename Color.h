#pragma once
#include "Engine.h"

using Color = olc::Pixel;

//class Color
//{
//public:
    //Color(const olc::Pixel& pixel)
        //:
        //pixel(pixel)
    //{
    //}

    //Color(int8_t r, int8_t g, int8_t b, int8_t a = 0)
        //:
        //Color(olc::Pixel(r, g, b, a))
    //{
    //}

    //int8_t GetR() const
    //{
        //return pixel.r;
    //}

    //int8_t GetG() const
    //{
        //return pixel.g;
    //}

    //int8_t GetB() const
    //{
        //return pixel.b;
    //}

    //int8_t GetA() const
    //{
        //return pixel.a;
    //}

    //const olc::Pixel GetPixel() const
    //{
        //return pixel;
    //}

    //operator olc::Pixel() const
    //{
        //return olc::Pixel(pixel.r, pixel.g, pixel.b, pixel.a);
    //}

    //Color& operator =(const Color& rhs)
    //{
        //if (*this == rhs)
            //return *this;

        //pixel = rhs.pixel; 
        //return *this;
    //}

    //bool operator ==(const Color& rhs) const
    //{
        //return (pixel == rhs.pixel);
    //}

    //bool   operator !=(const Color& rhs) const
    //{
        //return !(*this == rhs);
    //}

    //Color  operator * (const float i) const
    //{
        //return static_cast<Color>(pixel * i);
    //}

    //Color  operator / (const float i) const
    //{
        //return static_cast<Color>(pixel / i);
    //}

    //Color& operator *=(const float i)
    //{
        //pixel *= i;
        //return *this;
    //}

    //Color& operator /=(const float i)
    //{
        //pixel /= i;
        //return *this;
    //}

    //Color  operator + (const Color& rhs) const
    //{
        //return static_cast<Color>(pixel + rhs.pixel);
    //}

    //Color  operator - (const Color& rhs) const
    //{
        //return static_cast<Color>(pixel - rhs.pixel);
    //}
    
    //Color& operator +=(const Color& rhs)
    //{
        //pixel += rhs.pixel;
        //return *this;
    //}
    //Color& operator -=(const Color& rhs)
    //{
        //pixel -= rhs.pixel;
        //return *this;
    //}


//private:
    //olc::Pixel pixel;
//};
