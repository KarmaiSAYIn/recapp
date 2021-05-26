#include "MainWindow.h"

void MainWindow::SetGameObject(Game *game)
{
    this->game = game;
    mouse.SetGameObject(game);
    keyboard.SetGameObject(game);
}
