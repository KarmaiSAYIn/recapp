#pragma once
#include "Engine.h"

using Color = olc::Pixel;

namespace Colors
{
	static const Color
        // Rainbow
		Red(255, 0, 0),
        Orange(255, 165, 0),
		Yellow(255, 255, 0),
		Green(0, 255, 0),
		Blue(0, 0, 255),
        Indigo(75, 0, 130),
        Violet(238, 130, 238),

        // Shades
		White(255, 255, 255),
		Grey(192, 192, 192),
        Black(0, 0, 0),
        Blank(0, 0, 0, 0),
   
        // Extras
		Cyan(0, 255, 255),
        Purple(0, 255, 255),
		Magenta(255, 0, 255),
        Orchid(218, 112, 214),
        Fuchsia(255, 0, 255),
        Lavender(230, 230,250),
        Thistle(216, 191, 216),
        Plum(221, 160, 221);
};
