#pragma once
#include "Vec.h"

class Mouse final
{
public:
    Mouse() = default;

    Mouse(const Mouse&) = delete;
    Mouse& operator=(const Mouse&) = delete;

    void SetGameObject(class Game *game);

    int GetPosX() const;
    int GetPosY() const;
    Vei2 GetPos() const;

    bool LeftIsPressed() const;
    bool RightIsPressed() const;
    bool LeftIsEmpty() const;
    bool RightIsEmpty() const;

    bool LeftDownEvent() const;
    bool RightDownEvent() const;
    bool LeftUpEvent() const;
    bool RightUpEvent() const;

    bool WheelUp() const;
    bool WheelDown() const;

private:
    class Game *game = nullptr;
};
