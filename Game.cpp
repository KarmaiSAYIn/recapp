#include "Game.h"
#include "Graphics.h"
#include <iostream>

Game::Game()
{
    sAppName = "Recapp";
}

void Game::SetGraphicsObject(Graphics *gfx)
{
    this->gfx = gfx;
}

bool Game::OnUserCreate()
{
    return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
    for (int x = 0; x < gfx->GetScreenWidth(); x++)
        for (int y = 0; y < gfx->GetScreenHeight(); y++)
           gfx->PutPixel(x, y, Color(rand() % 254, rand() % 255, rand()% 255));	

    return true;
}

//int Game::GetScreenHeight() const
//{
        //return ScreenHeight();
//}

//int Game::GetScreenWidth() const
//{
        //return ScreenWidth();
//}

//void Game::PutPixel(int x, int y, olc::Pixel c)
//{
    //assert(x < ScreenWidth() && y < ScreenHeight());
    //Draw(x, y, c);
//}

//void Game::PutPixel(Vei2 pos, olc::Pixel c)
//{
        //assert(pos.x < ScreenWidth() && pos.y < ScreenHeight());
        //PutPixel(pos.x, pos.y, c);
//}

//Color Game::GetPixel(int x, int y) const
//{
        //assert(x < ScreenWidth() && y < ScreenHeight());
            //return static_cast<Color>(GetPixelAt(x, y));
//}

//Color Game::GetPixel(Vei2 pos) const
//{
        //assert(pos.x < ScreenWidth() && pos.y < ScreenHeight());
            //return static_cast<Color>(GetPixel(pos.x, pos.y));
//}

