#pragma once

#include "Color.hpp"
#include "Shape.hpp"

class Circle : public Shape
{
public:
  Circle(int cx, int cy, int r, Color color);
  void Draw(SDL_Renderer *pRenderer) const override;

private:
  int cx;
  int cy;
  int r;
  Color color;
};