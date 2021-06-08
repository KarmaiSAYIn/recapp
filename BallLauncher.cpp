#include "BallLauncher.h"
#include <assert.h>

BallLauncher::BallLauncher(const Vec2& spawnLocation, const Vec2& minVelocity, const Vec2& maxVelocity, Rectf ballArea, float fBallSpawnInterval)
    :
    spawnLocation(spawnLocation), 
    ballArea(ballArea),
    fBallSpawnInterval(fBallSpawnInterval),
    fTime(fBallSpawnInterval),
    rng(std::random_device{}()),
    xVelDist(minVelocity.x, std::nextafterf(maxVelocity.x, std::numeric_limits<float>::max())),
    yVelDist(minVelocity.y, std::nextafterf(maxVelocity.y, std::numeric_limits<float>::max()))
{
}

Rectf BallLauncher::GetRect() const
{
    return ballArea;
}

void BallLauncher::Update(float fElapsedTime, Camera& camera)
{
    if (fTime >= fBallSpawnInterval)
    {
        fTime -= fBallSpawnInterval;
        launchedBalls.emplace_back(spawnLocation, Vec2(xVelDist(rng), yVelDist(rng)), ballRadius);
    }

    for (auto ball = launchedBalls.begin(); ball != launchedBalls.end(); ++ball)
    {
        ball->Update(fElapsedTime);

        const float width = ball->GetRadius() * 2;
        const Rectf ballRect(ball->GetPos(), width, width);
        std::cout << "(" << ball->GetPos().x << ", " << ball->GetPos().y << ") " << ballRect.GetLeft() << " " << ballRect.GetRight() << " " << ballRect.GetTop() << " " << ballRect.GetBottom() << "\n";
        if (!ballArea.CollideRect(ballRect))
        {
            auto nDistance = ball - launchedBalls.begin();
            launchedBalls.erase(ball);
            ball = launchedBalls.begin() + nDistance;
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

