#include "Keyboard.h"
#include <assert.h>

void Keyboard::SetGameObject(Game *game)
{
    assert(this->game == nullptr);
    this->game = game;
}

bool Keyboard::KeyDownEvent(Key key) const
{
    return (game->GetKey(key).bPressed);
}

bool Keyboard::KeyIsPressed(Key key) const
{
    return (game->GetKey(key).bHeld);
}

bool Keyboard::KeyIsEmpty(Key key) const
{
    return !KeyIsPressed(key);
}
