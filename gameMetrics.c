#ifdef _WIN32
	#include <SDL.h>
#else
	#include <SDL2/SDL.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gameMetrics.h"
#include "../tools.h"


Metrics * newMetrics(Textures * textures)
{
    Metrics * metrics = NULL;
    int w, h, i;

    if (!textures)
        return NULL;

    metrics = (Metrics *)calloc(1, sizeof(Metrics));
    if (!metrics)
        return NULL;

    metrics->screen.x = 0;
    metrics->screen.y = 0;
    metrics->screen.w = WINDOW_WIDTH;
    metrics->screen.h = WINDOW_HEIGHT;

		SDL_QueryTexture(textures->notes[0], NULL, NULL, &w, &h);
    metrics->note.x = (metrics->screen.w - w) / 2;
    metrics->note.y = (metrics->screen.h - h) / 2;
    metrics->note.w = w;
    metrics->note.h = h;

		SDL_QueryTexture(textures->string, NULL, NULL, &w, &h);

    SDL_QueryTexture(textures->gameArea, NULL, NULL, &w, &h);
    metrics->gameArea.x = (metrics->screen.w - w) / 2;
    metrics->gameArea.y = (metrics->screen.h - h) / 2;
    metrics->gameArea.w = w;
    metrics->gameArea.h = h;

    return metrics;
}

void freeMetrics(Metrics * metrics)
{
    free(metrics);
}

void initMetrics(Metrics * metrics, int nbStrings)
{
	int i, w = metrics->gameArea.w, h = metrics->gameArea.h;
	for(i = 0; i < 5; i++)
	{
		metrics->strings[i].string.x = (i+0.4) * metrics->gameArea.x / (nbStrings + 1) + metrics->gameArea.x;
    metrics->strings[i].string.y = metrics->gameArea.y;
    metrics->strings[i].string.w = w;
    metrics->strings[i].string.h = h;
		if (i < nbStrings)
			metrics->strings[i].isActive = 1;
		else
			metrics->strings[i].isActive = 0;
	}
}
