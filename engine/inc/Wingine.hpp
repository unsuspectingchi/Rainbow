#pragma once

#include <vector>
#include "Color.hpp"
#include "SDL.h"

class Game;

class Wingine
{
public:
  Wingine(Game &game);

  void Finalize();
  bool Initialize();
  void Run();

  SDL_Renderer *GetRenderer();
  SDL_Window *GetWindow();

private:
  void RunController();
  void RunModel();
  void RunView();

  Game &game;
  char const *title;
  int posX;
  int posY;
  int dimX;
  int dimY;
  bool isRunning;
  SDL_Window *pWindow;
  SDL_Renderer *pRenderer;
  Uint32 ticksCount;
  int rendDriverIndex;
  Color bgColor;
  Color fgColor;
  Uint32 windowFlags;
  Uint32 initFlags;
  Uint32 rendFlags;
};