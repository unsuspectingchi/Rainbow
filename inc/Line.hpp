#pragma once

#include "Color.hpp"
#include "Shape.hpp"

class Line : public Shape
{
public:
  Line(int x1, int y1, int x2, int y2, Color color);
  void Draw(SDL_Renderer *pRenderer) const override;

private:
  int x1;
  int y1;
  int x2;
  int y2;
  Color color;
};