#pragma once
#include "Game.h"

class Keyboard final
{
public:
    using Key = olc::Key;

public:
    Keyboard() = default;

    Keyboard(const Keyboard&) = delete;
    Keyboard& operator=(const Keyboard&) = delete;

    void SetGameObject(Game *game);

    bool KeyIsPressed(Key key) const;
    bool KeyIsEmpty(Key key) const;

private:
    Game *game = nullptr;
};
