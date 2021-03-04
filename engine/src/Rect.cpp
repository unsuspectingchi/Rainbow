#include "Rect.hpp"

Rect::Rect(int posX, int posY, int dimX, int dimY, Color color)
    : rect({posX, posY, dimX, dimY}), color(color)
{
}

void Rect::Draw(SDL_Renderer *pRenderer) const
{
  SDL_SetRenderDrawColor(pRenderer, color.r, color.g, color.b, color.a);
  SDL_RenderDrawRect(pRenderer, &rect);
}