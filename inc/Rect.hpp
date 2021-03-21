#pragma once

#include "Color.hpp"
#include "Shape.hpp"

class Rect : public Shape
{
public:
  Rect(int posX, int posY, int dimX, int dimY, Color color);
  void Draw(SDL_Renderer *pRenderer) const override;

private:
  SDL_Rect rect;
  Color color;
};