#pragma once

#include <string>
#include "SDL.h"
#include "Color.hpp"

using std::string;

namespace GameConfig
{
  string const title = "Game";           // window title
  Color const fgColor(255, 255, 0, 255); // foreground color
}