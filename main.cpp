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
	if (theGame.Construct(Graphics::ScreenWidth, Graphics::ScreenHeight, 1, 1, true))
		theGame.Start();

	return 0;
}
