#include "MainWindow.h"
#include <assert.h>

void MainWindow::SetGameObject(Game *game)
{
    assert(this->game == nullptr);
    this->game = game;
    mouse.SetGameObject(game);
    keyboard.SetGameObject(game);
}

void MainWindow::SetWindowTitle(const std::string& s)
{
    game->SetWindowTitle(s);
}

