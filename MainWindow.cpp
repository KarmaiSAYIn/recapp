#include "MainWindow.h"

#include <assert.h>

#include "Game.h"

void MainWindow::SetGameObject(Game *game)
{
    assert(this->game == nullptr);
    this->game = game;
    mouse.SetGameObject(game);
    kbd.SetGameObject(game);
}

void MainWindow::SetWindowTitle(const std::string& s)
{
    game->SetWindowTitle(s);
}

