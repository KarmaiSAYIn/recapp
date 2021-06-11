#include "Time.h"

Time::Time()
{
    start = std::chrono::steady_clock::now();
}

float Time::Mark()
{
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::chrono::duration<float> elapsedTime = end - start;
    start = end;
    return elapsedTime.count();
}

