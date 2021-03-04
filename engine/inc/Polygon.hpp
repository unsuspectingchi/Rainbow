#pragma once

#include "Color.hpp"
#include "Shape.hpp"

class Polygon : public Shape
{
public:
  Polygon(int numValues, int *values, Color color);
  void Draw(SDL_Renderer *pRenderer) const override;

private:
  int numValues;
  int *values;
  Color color;
};