#pragma once

#include <vector>
#include "SDL.h"
#include "Shape.hpp"
#include "Wingine.hpp"

class Game
{
public:
  Game();
  ~Game();

  void Finalize();
  void FinalizeController();
  void FinalizeModel();
  void FinalizeView();

  bool Initialize();
  void InitializeController();
  void InitializeModel();
  void InitializeView();

  void Run();
  void RunController(const Uint8 *pState);
  void RunModel();
  void RunView();

private:
  Wingine wingine;
  SDL_Window *pWindow;
  SDL_Renderer *pRenderer;
  std::vector<Shape *> shapes;
};