#include <stdio.h>

#include <SDL/SDL.h>

#include "sdl.hpp"


enum
{
	BITMAP_GRASS=0,
	BITMAP_HERO1,
	NUM_BITMAPS
};

SDL_Surface *bitmaps[NUM_BITMAPS];

void loadBitmaps()
{
	bitmaps[BITMAP_GRASS] = SDL_LoadBMP("data/Pictures/grass.bmp");
	bitmaps[BITMAP_HERO1] = SDL_LoadBMP("data/Pictures/hero1.bmp");
}

void displayBitmap(int bitmap, int x, int y)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	SDL_BlitSurface(bitmaps[bitmap], 0, screen, &rect);
}

void displayMap()
{
	for(int x = 0; x < SCREEN_WIDTH; x += TILE_SIZE)
	{
		for(int y = 0; y < SCREEN_HEIGHT; y += TILE_SIZE)
			displayBitmap(BITMAP_GRASS, x, y);
	}
}

void run()
{
	sdlInit();
	loadBitmaps();

	int heroPosX = SCREEN_WIDTH/2;
	int heroPosY = SCREEN_HEIGHT/2;
	while(1)
	{
		SDL_Event event;
		int ok = SDL_PollEvent(&event);
		if(ok)
		{
			if(event.type == SDL_QUIT)
				break;
			else if(event.type == SDL_KEYDOWN)
			{
				if(event.key.keysym.sym == SDLK_w)
					heroPosY -= TILE_SIZE;
				else if(event.key.keysym.sym == SDLK_a)
					heroPosX -= TILE_SIZE;
				else if(event.key.keysym.sym == SDLK_s)
					heroPosY += TILE_SIZE;
				else if(event.key.keysym.sym == SDLK_d)
					heroPosX += TILE_SIZE;
			}
		}
		displayMap();
		displayBitmap(BITMAP_HERO1, heroPosX, heroPosY);
		SDL_Flip(screen);
	}

	sdlQuit();
}
