#include <stdio.h>
#define SDL_MAIN_HANDLED 1 
#include <SDL2/SDL.h>

int main(int argc, char* argv[])
{
  printf("HELLO!\n");
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    fprintf(stderr, "could not initialize sdl2: %s\n", SDL_GetError());
    return 1;
  }

  SDL_version compiled;
  SDL_version linked;

  SDL_VERSION(&compiled);
  SDL_GetVersion(&linked);
  printf("We compiled against SDL version %d.%d.%d ...\n", compiled.major, compiled.minor, compiled.patch);
  printf("But we are linking against SDL version %d.%d.%d.\n", linked.major, linked.minor, linked.patch);

  SDL_Window* window = NULL;

  return 0;
}
