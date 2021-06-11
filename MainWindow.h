#pragma once
#include "Keyboard.h"
#include "Mouse.h"

class MainWindow final
{
public:
    MainWindow() = default;

    MainWindow(const MainWindow&) = delete;
    MainWindow& operator=(const MainWindow&) = delete;

    void SetGameObject(Game *game);

    void SetWindowTitle(const std::string& s);

public:
    Game *game = nullptr;
    Mouse mouse;
    Keyboard keyboard;
};
