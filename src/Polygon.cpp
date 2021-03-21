#include <math.h>
#include "Polygon.hpp"

Polygon::Polygon(int numValues, int *values, Color color)
    : numValues(numValues), values(values), color(color)
{
}

void Polygon::Draw(SDL_Renderer *pRenderer) const
{
  SDL_SetRenderDrawColor(pRenderer, color.r, color.g, color.b, color.a);
  for (int i = 2; i < numValues; i += 2)
  {
    SDL_RenderDrawLine(pRenderer,
                       values[i - 2], values[i - 1],
                       values[i], values[i + 1]);
  }
  SDL_RenderDrawLine(pRenderer,
                     values[numValues - 2], values[numValues - 1],
                     values[0], values[1]);
}