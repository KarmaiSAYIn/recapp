#pragma once
#include "Game.h"

using Key = olc::Key;

class Keyboard final
{
public:
    Keyboard() = default;

    Keyboard(const Keyboard&) = delete;
    Keyboard& operator=(const Keyboard&) = delete;

    void SetGameObject(Game *game);

    bool KeyDownEvent(Key key) const;
    bool KeyIsPressed(Key key) const;
    bool KeyIsEmpty(Key key) const;

private:
    Game *game = nullptr;
};
