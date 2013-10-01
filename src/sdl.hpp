#ifndef SDL_HPP
#define SDL_HPP


enum
{
	SCREEN_WIDTH=800,
	SCREEN_HEIGHT=600,
	TILE_SIZE=32
};

extern struct SDL_Surface *screen;

void run();
bool sdlInit();
void sdlQuit();


#endif
