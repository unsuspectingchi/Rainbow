#include "Circle.hpp"
#include "Game.hpp"
#include "GameConfig.hpp"
#include "Line.hpp"
#include "Polygon.hpp"
#include "Rect.hpp"
#include "RectIn.hpp"
#include "SDL.h"

Game::Game()
    : wingine(*this), pWindow(nullptr), pRenderer(nullptr), shapes()
{
  if (Initialize())
  {
    Run();
  }
  Finalize();
}

Game::~Game()
{
  for (Shape *pShape : shapes)
  {
    delete pShape;
  }
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
  shapes.emplace_back(new RectIn{50, 50, 100, 50, Color{255, 0, 0, 255}});
  shapes.emplace_back(new Rect{150, 50, 100, 50, Color{255, 0, 0, 255}});
  shapes.emplace_back(new Line{150, 50, 250, 100, Color{255, 0, 0, 255}});
  shapes.emplace_back(new Line{150, 100, 250, 50, Color{255, 0, 0, 255}});
  shapes.emplace_back(new RectIn{50, 100, 100, 50, Color{0, 255, 0, 255}});
  shapes.emplace_back(new Rect{150, 100, 100, 50, Color{0, 255, 0, 255}});
  shapes.emplace_back(new Line{150, 100, 250, 150, Color{0, 255, 0, 255}});
  shapes.emplace_back(new Line{150, 150, 250, 100, Color{0, 255, 0, 255}});
  shapes.emplace_back(new RectIn{50, 150, 100, 50, Color{0, 0, 255, 255}});
  shapes.emplace_back(new Rect{150, 150, 100, 50, Color{0, 0, 255, 255}});
  shapes.emplace_back(new Line{150, 150, 250, 200, Color{0, 0, 255, 255}});
  shapes.emplace_back(new Line{150, 200, 250, 150, Color{0, 0, 255, 255}});
  shapes.emplace_back(new Circle{300, 300, 100, Color{0, 255, 255, 255}});
  static int verts[6] = {400, 400, 500, 500, 500, 100};
  shapes.emplace_back(new Polygon{6, verts, Color{255, 255, 0, 255}});
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
  for (Shape *pShape : shapes)
  {
    pShape->Draw(pRenderer);
  }
}