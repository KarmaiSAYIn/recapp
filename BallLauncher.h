#pragma once
#include "Ball.h"
#include "Camera.h"
#include "Rect.h"
#include <random>

class BallLauncher final
{
public:
    BallLauncher(const Vec2& spawnLocation, const Vec2& minVelocity, const Vec2& maxVelocity, Rectf ballArea, float fBallSpawnInterval = 1.0f);

    Rectf GetRect() const;

    void Update(float fElapsedTime, Camera& camera);

    void Draw(Camera& camera) const;
private:
    Vec2 spawnLocation;
    Rectf ballArea;

    float fBallSpawnInterval;
    float fTime;

    std::mt19937 rng;
    std::uniform_real_distribution<float> xVelDist;
    std::uniform_real_distribution<float> yVelDist;
    std::vector<Ball> launchedBalls;

    static constexpr float ballRadius = 10.0f;
};
