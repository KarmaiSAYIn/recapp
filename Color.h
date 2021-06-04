#pragma once
#include "Engine.h"

using Color = olc::Pixel;

namespace Colors
{
	static const Color
        // Rainbow
		RED(255, 0, 0),
        ORANGE(255, 165, 0),
		YELLOW(255, 255, 0),
		GREEN(0, 255, 0),
		BLUE(0, 0, 255),
        INGIDGO(75, 0, 130),
        VIOLET(238, 130, 238),

        // Shades
		WHITE(255, 255, 255),
		GREY(192, 192, 192),
        BLACK(0, 0, 0),
        BLANK(0, 0, 0, 0),
   
        // Extras
		CYAN(0, 255, 255),
        PURPLE(0, 255, 255),
		MAGENTA(255, 0, 255),
        ORCHID(218, 112, 214),
        FUCHSIA(255, 0, 255),
        LAVENDER(230, 230,250),
        THISTLE(216, 191, 216),
        PLUM(221, 160, 221);
};
