#pragma once
#include "Engine.h"

using Key = olc::Key;

class Keyboard final
{
public:
    Keyboard() = default;

    Keyboard(const Keyboard&) = delete;
    Keyboard& operator=(const Keyboard&) = delete;

    void SetGameObject(class Game *game);

    bool KeyDownEvent(Key key) const;
    bool KeyIsPressed(Key key) const;
    bool KeyIsEmpty(Key key) const;

private:
    class Game *game = nullptr;
};
