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

void BallLauncher::Update(float fElapsedTime, Camera& camera)
{
    if (fTime >= fBallSpawnInterval)
    {
        fTime -= fBallSpawnInterval;
        launchedBalls.emplace_back(spawnLocation, Vec2(xVelDist(rng), yVel), ballRadius);
    }

    for (auto ball = launchedBalls.begin(); ball != launchedBalls.end(); ++ball)
    {
        ball->Update(fElapsedTime);

        const float width = ball->GetRadius() * 2;
        const Rectf ballRect(ball->GetPos(), width, width);
        if (!ballRect.IsContainedBy(ballArea))
        {
            int nDistance = ball - std::begin(launchedBalls) - 1;
            launchedBalls.erase(ball);
            ball = std::begin(launchedBalls) + nDistance;
        }
    }

    fTime += fElapsedTime;
}

void BallLauncher::Draw(Camera& camera) const
{
    for (const auto& ball : launchedBalls)
    {
        auto d = ball.GetDrawable();
        camera.Draw(d);
    }
}

