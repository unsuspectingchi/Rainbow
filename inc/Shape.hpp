#pragma once

#include "SDL.h"

class Shape
{
public:
  virtual ~Shape() = default;
  virtual void Draw(SDL_Renderer *pRenderer) const = 0;
};