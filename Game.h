#pragma once
#include "Engine.h"
#include "CoordinateTransformer.h"
#include "Cube.h"
#include "Time.h"
#include "Scene.h"

class Game : public olc::PixelGameEngine
{
public:
    Game() = delete;
    Game(const Game&) = delete;
    Game(class Graphics& gfx, class MainWindow& wnd);

    void SetGraphicsObject(class Graphics& gfx);

	bool OnUserCreate() override;
	bool OnUserUpdate() override;

    void UpdateModel(float fElapsedTime);
    void ComposeFrame();

private:
    void AdvanceScene(int direction);

private:
    class Graphics& gfx;
    class MainWindow& wnd;
    Time time;

    unsigned int nFrameCount = 0;
    unsigned int nFPS = 0;
    float fTime = 0.0f;
    
    CoordinateTransformer transformer;

    std::vector<std::unique_ptr<Scene>> scenes;
    std::vector<std::unique_ptr<Scene>>::iterator currScene;

    static constexpr float fUpdateSpeed = 0.000025f;
};
