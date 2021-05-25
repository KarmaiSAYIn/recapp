#include "Game.h"
#include "Engine.h"
#include "Graphics.h"

int main()
{
    Graphics gfx;
    Game TheGame(gfx);
    gfx.SetGameObject(&TheGame);
	if (TheGame.Construct(1280, 720, 1, 1))
		TheGame.Start();

	return 0;
}
