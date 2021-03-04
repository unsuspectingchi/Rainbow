#include <math.h>
#include "Circle.hpp"

const double ANGLE_STEP = 0.01;
const double PI2 = 2 * acos(-1);

Circle::Circle(int cx, int cy, int r, Color color)
    : cx(cx), cy(cy), r(r), color(color)
{
}

void Circle::Draw(SDL_Renderer *pRenderer) const
{
  SDL_SetRenderDrawColor(pRenderer, color.r, color.g, color.b, color.a);
  int priorX = cx + r;
  int priorY = cy;
  int nextX, nextY;
  for (double angle = ANGLE_STEP; angle < PI2; angle += ANGLE_STEP)
  {
    nextX = round(cx + r * cos(angle));
    nextY = round(cy + r * sin(angle));
    SDL_RenderDrawLine(pRenderer, priorX, priorY, nextX, nextY);
    priorX = nextX;
    priorY = nextY;
  }
  SDL_RenderDrawLine(pRenderer, priorX, priorY, cx + r, cy);
}