#include "Game.h"
#include "Engine.h"
#include "Graphics.h"
#include "MainWindow.h"

int main()
{
    Graphics gfx;
    MainWindow wnd;
    Game theGame(gfx, wnd);
    gfx.SetGameObject(&theGame);
    wnd.SetGameObject(&theGame);
	if (theGame.Construct(1280, 720, 1, 1))
		theGame.Start();

	return 0;
}
