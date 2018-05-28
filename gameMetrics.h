
#ifndef _GAME_METRICS_INCLUDED_
#define _GAME_METRICS_INCLUDED_

#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include "../GameModel/model.h"
#include "textures.h"

typedef struct Sting_s
{
	int isActive;
	SDL_Rect string;
}String;

typedef struct Metrics_s
{
    SDL_Rect screen;
    SDL_Rect note;
    SDL_Rect gameArea;
    String strings[5];
} Metrics;

Metrics * newMetrics(Textures * textures);
void freeMetrics(Metrics * metrics);

void initMetrics(Metrics *metrics, int nbStrings);

#endif
