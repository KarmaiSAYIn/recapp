#include "Mouse.h"

void Mouse::SetGameObject(Game *game)
{
    this-> game = game;
}

int Mouse::GetPosX() const
{
    return game->GetMouseX();
}

int Mouse::GetPosY() const
{
    return game->GetMouseY();
}

Vei2 Mouse::GetPos() const
{
    return (Vei2(GetPosX(), GetPosY()));
}

bool Mouse::LeftIsPressed() const
{
    return (game->GetMouse(0).bHeld);
}

bool Mouse::RightIsPressed() const
{
    return (game->GetMouse(1).bHeld);
}

bool Mouse::LeftIsEmpty() const
{
    return !LeftIsPressed();
}

bool Mouse::RightIsEmpty() const
{
    return !RightIsPressed();
}

bool Mouse::WheelUp() const
{
    return (game->GetMouseWheel() > 0);
}

bool Mouse::WheelDown() const
{
    return (game->GetMouseWheel() < 0);
}
