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

		for(i = 1; i < MAX_STRINGS; i++)
		{
			SDL_QueryTexture(textures->notes[i], NULL, NULL, &w, &h);
		}
		initMetrics(metrics, nbSrings);
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
	int i, w = metrics->gameArea.h, h = metrics->gameArea.h;

  if(nbStrings > 5 || nbStrings < 3)
	{
		printf("Error : unsupported strings number !");
		system("exit");
	}
	for(i = 1; i < nbStrings; i++)
	{
		metrics->note.x = nbStrings * i * 256 / (1 + nbStrings) - 128;
		metrics->note.y = 0;
		metrics->note.w = w;
		metrics->note.h = h;
	}
}
