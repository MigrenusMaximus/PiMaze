#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#include "definitions.h"

#include "game.h"
#include "ppm.h"

/* Renderuje trenutnu scenu na osnovu
   pozicije igraca u svijetu i izgleda
   labirinta */
void renderScene(Game *game, int fieldOfView, int width);
/* Raycast vraca row-major koordinate tacke
   s kojom se sudario */
int raycast(Grid *maze, Player *player, float angle);
/* Testna funkcija, bice izbrisana prije kraja */
void preparePPM(PPMData *ppm);

#endif 