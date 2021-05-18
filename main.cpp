#include "Game.h"
#include "Engine.h"
#include "Graphics.h"

int main()
{
    Game TheGame;
    Graphics gfx(&TheGame);
    TheGame.SetGraphicsObject(&gfx);
	if (TheGame.Construct(1280 / 4, 720 / 4, 4, 4))
		TheGame.Start();

	return 0;
}
