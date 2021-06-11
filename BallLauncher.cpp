#include "BallLauncher.h"

BallLauncher::BallLauncher(const Vec2& spawnLocation, float minVelocityX, float maxVelocityX, float yVel, Rectf ballArea, float fBallSpawnInterval)
    :
    spawnLocation(spawnLocation), 
    ballArea(ballArea),
    fBallSpawnInterval(fBallSpawnInterval),
    fTime(fBallSpawnInterval),
    yVel(yVel),
    rng(std::random_device{}()),
    xVelDist(minVelocityX, std::nextafterf(maxVelocityX, std::numeric_limits<float>::max()))
{
}

void BallLauncher::Update(float fElapsedTime, std::vector<Ball>& balls)
{
    if (fTime >= fBallSpawnInterval)
    {
        fTime -= fBallSpawnInterval;
        balls.emplace_back(spawnLocation, Vec2(xVelDist(rng), yVel), ballRadius);
    }

    for (auto ball = balls.begin(); ball != balls.end(); ++ball)
    {
        ball->Update(fElapsedTime);

        const float width = ball->GetRadius() * 2;
        const Rectf ballRect(ball->GetPos(), width, width);
        if (!ballRect.IsContainedBy(ballArea))
        {
            int nDistance = ball - std::begin(balls) - 1;
            balls.erase(ball);
            ball = std::begin(balls) + nDistance;
        }
    }

    fTime += fElapsedTime;
}

