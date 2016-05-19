#ifndef __GAME_H__
#define __GAME_H__

#include "definitions.h"

#include "grid.h"

struct _Game {
    Grid maze;
    /* Pozicija u labirintu */
    int playerRow;
    int playerColumn;
    /* Velicina pojedinacnog bloka */
    int blockSize;
    /* Trenutna pozicija igraca unutar bloka */
    int playerXInBlock;
    int playerYInBlock;
    /* Smjer u kojem igrac gleda (0 - 360) */
    float playerRotation;
    /* Da li je igrac dosao do kraja labirinta */
    BOOL hasWon;
    /* Ovo koristimo da znamo da li da
       pollamo za nove movement komande */
    BOOL isPaused;
};

typedef struct _Game Game;

Game setGame(int mazeHeight, int mazeWidth, int displayHeight, int displayWidth, int blockSize);

void play();

#endif