#include "Game.h"

int main()
{
	Game demo;
	if (demo.Construct(1280 / 4, 720 / 4, 4, 4))
		demo.Start();

	return 0;
}
