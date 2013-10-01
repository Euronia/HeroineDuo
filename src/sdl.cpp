#include <stdio.h>

#include <SDL/SDL.h>

#include "sdl.hpp"


SDL_Surface *screen;

bool sdlInit()
{
	SDL_Init(SDL_INIT_VIDEO);
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_HWSURFACE);
	if(!screen)
		return false;
	SDL_WM_SetCaption("HeroineDuo", 0);
	return true;
}

void sdlQuit()
{
	SDL_Quit();
}
