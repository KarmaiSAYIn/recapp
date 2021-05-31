#pragma once
#include "Game.h"
#include "Vec.h"

class Mouse final
{
public:
    Mouse() = default;

    Mouse(const Mouse&) = delete;
    Mouse& operator=(const Mouse&) = delete;

    void SetGameObject(Game *game);

    int GetPosX() const;
    int GetPosY() const;
    Vei2 GetPos() const;

    bool LeftIsPressed() const;
    bool RightIsPressed() const;
    bool LeftIsEmpty() const;
    bool RightIsEmpty() const;
    bool WheelUp() const;
    bool WheelDown() const;

private:
    Game *game = nullptr;
};
