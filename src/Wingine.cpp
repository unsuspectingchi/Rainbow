#include "Wingine.hpp"
#include "Config.hpp"
#include "Game.hpp"

Wingine::Wingine(Game &game)
    : game(game),
      title(Config::title.c_str()),
      posX(Config::posX),
      posY(Config::posY),
      dimX(Config::dimX),
      dimY(Config::dimY),
      isRunning(true),
      pWindow(nullptr),
      pRenderer(nullptr),
      ticksCount(0),
      rendDriverIndex(Config::sdlRendDriverIndex),
      bgColor(Config::bgColor),
      fgColor(Config::fgColor)
{
  windowFlags = (Config::sdlWinFullscreen ? SDL_WINDOW_FULLSCREEN : 0) |
                (Config::sdlWinFsDestop ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0) |
                (Config::sdlWinOpengl ? SDL_WINDOW_OPENGL : 0) |
                (Config::sdlWinVulkan ? SDL_WINDOW_VULKAN : 0) |
                (Config::sdlWinHidden ? SDL_WINDOW_HIDDEN : 0) |
                (Config::sdlWinBorderless ? SDL_WINDOW_BORDERLESS : 0) |
                (Config::sdlWinResizable ? SDL_WINDOW_RESIZABLE : 0) |
                (Config::sdlWinMinimized ? SDL_WINDOW_MINIMIZED : 0) |
                (Config::sdlWinMaximized ? SDL_WINDOW_MAXIMIZED : 0) |
                (Config::sdlWinInputGrabbed ? SDL_WINDOW_INPUT_GRABBED : 0) |
                (Config::sdlWinAllowHighdpi ? SDL_WINDOW_ALLOW_HIGHDPI : 0);
  initFlags = (Config::sdlInitTimer ? SDL_INIT_TIMER : 0) |
              (Config::sdlInitAudio ? SDL_INIT_AUDIO : 0) |
              (Config::sdlInitVideo ? SDL_INIT_VIDEO : 0) |
              (Config::sdlInitJoystick ? SDL_INIT_JOYSTICK : 0) |
              (Config::sdlInitHaptic ? SDL_INIT_HAPTIC : 0) |
              (Config::sdlInitController ? SDL_INIT_GAMECONTROLLER : 0) |
              (Config::sdlInitEvents ? SDL_INIT_EVENTS : 0) |
              (Config::sdlInitEverything ? SDL_INIT_EVERYTHING : 0);
  rendFlags = (Config::sdlRendSoftware ? SDL_RENDERER_SOFTWARE : 0) |
              (Config::sdlRendAccelerated ? SDL_RENDERER_ACCELERATED : 0) |
              (Config::sdlRendPresentvsync ? SDL_RENDERER_PRESENTVSYNC : 0) |
              (Config::sdlRendTexture ? SDL_RENDERER_TARGETTEXTURE : 0);
}

void Wingine::Finalize()
{
  SDL_Log("Finalizing Wingine.");
  SDL_DestroyRenderer(pRenderer);
  SDL_DestroyWindow(pWindow);
  SDL_Quit();
}

bool Wingine::Initialize()
{
  if (SDL_Init(initFlags) != 0)
  {
    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    return false;
  }
  pWindow = SDL_CreateWindow(title, posX, posY, dimX, dimY, windowFlags);
  if (!pWindow)
  {
    SDL_Log("Failed to create window: %s", SDL_GetError());
    return false;
  }
  pRenderer = SDL_CreateRenderer(pWindow, rendDriverIndex, rendFlags);
  if (!pRenderer)
  {
    SDL_Log("Failed to create renderer: %s", SDL_GetError());
    return false;
  }
  SDL_Log("Initialized MyWindow.");
  return true;
}

void Wingine::Run()
{
  SDL_Log("Running Wingine.");
  while (isRunning)
  {
    RunController();
    RunModel();
    RunView();
  }
}

void Wingine::RunController()
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
    case SDL_QUIT:
      isRunning = false;
      break;
    }
  }
  const Uint8 *state = SDL_GetKeyboardState(NULL);
  if (state[SDL_SCANCODE_ESCAPE])
  {
    isRunning = false;
  }
  game.RunController(state);
}

void Wingine::RunModel()
{
  while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksCount + 16))
    ;
  float deltaTime = (SDL_GetTicks() - ticksCount) / 1000.0f;
  if (deltaTime > 0.05f)
  {
    deltaTime = 0.05f;
  }
  ticksCount = SDL_GetTicks();
  game.RunModel();
}

void Wingine::RunView()
{
  SDL_SetRenderDrawColor(pRenderer, bgColor.r, bgColor.g, bgColor.b, bgColor.a);
  SDL_RenderClear(pRenderer);
  game.RunView();
  SDL_RenderPresent(pRenderer);
}

SDL_Renderer *Wingine::GetRenderer()
{
  return pRenderer;
}

SDL_Window *Wingine::GetWindow()
{
  return pWindow;
}
