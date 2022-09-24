#include <stdio.h>
#define SDL_MAIN_HANDLED 1 
#include <SDL2/SDL.h>

bool quit = false;

void readUserInput(SDL_Keysym ksym)
{
  if(ksym.sym == SDLK_ESCAPE)
  {
    //quit = true;
  }
}


int main(int argc, char* argv[])
{
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER | SDL_INIT_HAPTIC) < 0)
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

  SDL_Window* window = SDL_CreateWindow("Microsoft Windows Sucks", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_SHOWN);
  if (window == NULL)
  {
    fprintf(stderr, "could not create window: %s\n", SDL_GetError());
  }

  SDL_GameController* gc = SDL_GameControllerOpen(0);

  char data[48];
  data[0] = 0x02;
  data[1] = 0x04;
  data[2] = 0xff;
  data[3] = 0xff;
  data[4] = 0xff;
  data[5] = 0xff;
  data[6] = 0xff;
  data[7] = 0xff;
  data[8] = 0x0c;
  data[9] = 0x01;
  data[10] = 0x00;
  data[11] = 0x01;
  data[12] = 0x0;
  data[13] = 0xff;
  data[14] = 0x0;
  data[15] = 0x3f;
  data[16] = 0x7f;
  data[17] = 0xff;
  data[18] = 0x00;
  data[19] = 0x00;
  data[20] = 8;
  data[21] = 0x00;
  data[22] = 0x0;
  data[23] = 0x0;
  data[24] = 0x0;
  data[25] = 0x0;
  data[26] = 0x0;
  data[27] = 0x0;
  data[28] = 0x0;
  data[29] = 0x0;
  data[30] = 0x0;
  data[31] = 8;
  data[37] = 0x07;

  SDL_GameControllerSendEffect(gc, data, 48);

  SDL_Event e;

  while(!quit)
  {
    while (SDL_PollEvent(&e))
    {
      if(e.type == SDL_KEYDOWN)
      {
        readUserInput(e.key.keysym);
      }

      if(e.type == SDL_JOYBUTTONDOWN)
      {
        printf("JOY BUTTON PRESSED DOWN!\n");
      }

      if(e.type == SDL_JOYBUTTONUP)
      {
        printf("JOY BUTTON RELEASED!\n");
      }

      if (e.type == SDL_QUIT)
      {
        quit = true;
      }
    }
    SDL_GameControllerSendEffect(gc, data, 48);
  }

  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
