#pragma once

#include <string>
#include "SDL.h"
#include "Color.hpp"

using std::string;

namespace Config
{
  bool const sdlInitTimer = false;      // timer subsystem
  bool const sdlInitAudio = false;      // audio subsystem
  bool const sdlInitVideo = true;       // video & events subsystem
  bool const sdlInitJoystick = false;   // joystick & events subsys
  bool const sdlInitHaptic = false;     // haptic (force feedback)
  bool const sdlInitController = false; // controller & joystick
  bool const sdlInitEvents = false;     // events subsystem
  bool const sdlInitEverything = false; // all of the above

  bool const sdlWinFullscreen = false;   // fullscreen window
  bool const sdlWinFsDestop = false;     // destop size & resolution
  bool const sdlWinOpengl = false;       // usable w/ OpenGL context
  bool const sdlWinVulkan = false;       // usable w/ Vulkan context
  bool const sdlWinHidden = false;       // window is not visible
  bool const sdlWinBorderless = false;   // no window decoration
  bool const sdlWinResizable = true;     // window can be resized
  bool const sdlWinMinimized = false;    // window is minimized
  bool const sdlWinMaximized = false;    // window is maximized
  bool const sdlWinInputGrabbed = false; // grab input focus
  bool const sdlWinAllowHighdpi = true;  // allow high-DPI if support

  bool const sdlRendSoftware = false;    // renderer is a software fallback
  bool const sdlRendAccelerated = true;  // use hardware acceleration
  bool const sdlRendPresentvsync = true; // present sync'd w/ refresh rate
  bool const sdlRendTexture = false;     // supports rendering to texture
  int const sdlRendDriverIndex = -1;     // driver index (-1 = first found)

  int const dimX = 800;                    // width (px)
  int const dimY = 600;                    // height (px)
  int const posX = SDL_WINDOWPOS_CENTERED; // left edge (or centered)
  int const posY = SDL_WINDOWPOS_CENTERED; // top edge (or centered)
  string const title = "Wingine";          // window title
  Color const bgColor(0, 0, 0, 255);       // background color
  Color const fgColor(255, 255, 255, 255); // foreground color
}