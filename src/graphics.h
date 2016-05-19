#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include "definitions.h"

#include "game.h"
#include "ppm.h"

void renderScene(Game *game, int fieldOfView, int width);
/* Raycast vraca row-major koordinate tacke
   s kojom se sudario */
int raycast(Grid *maze, Player *player, float angle);

void preparePPM(PPMData *ppm);

#endif 