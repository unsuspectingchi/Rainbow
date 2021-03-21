#include "Line.hpp"

Line::Line(int x1, int y1, int x2, int y2, Color color)
    : x1(x1), y1(y1), x2(x2), y2(y2), color(color)
{
}

void Line::Draw(SDL_Renderer *pRenderer) const
{
  SDL_SetRenderDrawColor(pRenderer, color.r, color.g, color.b, color.a);
  SDL_RenderDrawLine(pRenderer, x1, y1, x2, y2);
}