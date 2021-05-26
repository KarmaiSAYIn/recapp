#include "Keyboard.h"

void Keyboard::SetGameObject(Game *game)
{
    this->game = game;
}

bool Keyboard::KeyIsPressed(Key key) const
{
    return (game->GetKey(key).bHeld);
}

bool Keyboard::KeyIsEmpty(Key key) const
{
    return !KeyIsPressed(key);
}
