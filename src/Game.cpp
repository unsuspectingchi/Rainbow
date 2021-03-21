#include "Circle.hpp"
#include "Game.hpp"
#include "GameConfig.hpp"
#include "Line.hpp"
#include "Polygon.hpp"
#include "RectIn.hpp"
#include "SDL.h"

Game::Game()
    : wingine(*this), pWindow(nullptr), pRenderer(nullptr)
{
  if (Initialize())
  {
    Run();
  }
  Finalize();
}

Game::~Game()
{
  
}

void Game::Finalize()
{
  FinalizeModel();
  FinalizeView();
  FinalizeController();
  wingine.Finalize();
}

void Game::FinalizeController()
{

}

void Game::FinalizeModel()
{

}

void Game::FinalizeView()
{

}

bool Game::Initialize()
{
  if (!wingine.Initialize())
  {
    return false;
  }
  InitializeModel();
  InitializeView();
  InitializeController();
  return true;
}

void Game::InitializeController()
{

}

void Game::InitializeModel()
{
  rainbow.Insert(new RectIn(0, 0, 100, 100, Color{255, 0, 0, 255}), 1); //red
  rainbow.Insert(new RectIn(0, 100, 90, 90, Color{255, 165, 0, 255}), 2); //orange
  rainbow.Insert(new RectIn(0, 190, 80, 80, Color{255, 239, 0, 255}), 3); //yellow
  rainbow.Insert(new RectIn(0, 270, 70, 70, Color{0, 255, 0, 255}), 4); //green
  rainbow.Insert(new RectIn(0, 340, 60, 60, Color{0, 0, 255, 255}), 5); //blue
  rainbow.Insert(new RectIn(0, 400, 50, 50, Color{120, 0, 255, 255}), 6); //violet
}

void Game::InitializeView()
{
  pWindow = wingine.GetWindow();
  pRenderer = wingine.GetRenderer();
  SDL_SetWindowTitle(pWindow, GameConfig::title.c_str());
}

void Game::Run()
{
  wingine.Run();
}

void Game::RunController(const Uint8 *state)
{
  if (state[SDL_SCANCODE_DOWN])
  {
    SDL_Log("pressed down");
  }
  if (state[SDL_SCANCODE_LEFT])
  {
    SDL_Log("pressed left");
  }
  if (state[SDL_SCANCODE_RIGHT])
  {
    SDL_Log("pressed right");
  }
  if (state[SDL_SCANCODE_UP])
  {
    SDL_Log("pressed up");
  }
}

void Game::RunModel()
{

}

void Game::RunView()
{
  rainbow.SetIterToHead();
  RectIn *ray = rainbow.GetNext();
  while (ray)
  {
      ray->Draw(pRenderer);
      ray = rainbow.GetNext();
  }
}