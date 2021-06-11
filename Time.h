#pragma once
#include <chrono>

class Time final
{
public:
    Time();

    float Mark();

private:
    std::chrono::steady_clock::time_point start;
};
