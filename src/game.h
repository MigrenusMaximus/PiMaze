#ifndef __GAME_H__
#define __GAME_H__

#include "definitions.h"

#include "grid.h"

struct _Player {
    /* Pozicija u labirintu */
    int row;
    int column;
    /* Trenutna pozicija igraca unutar bloka */
    int xPos;
    int yPos;
    /* Smjer u kojem igrac gleda (0 - 360) */
    float rotation;      
};

typedef struct _Player Player;

/* Konstruktor za Player */
Player setPlayer(int row, int column, int xPos, int yPos, float rotation);

struct _Game {
    Grid maze;
    /* Velicina pojedinacnog bloka */
    int blockSize;
    /* Da li je igrac dosao do kraja labirinta */
    BOOL hasWon;
    /* Ovo koristimo da znamo da li da
       pollamo za nove movement komande */
    BOOL isPaused;
    /* Informacije o igracu drzimo u
       odvojenoj strukturi, posto se one uvijek
       zajedno koriste */
    Player player;
};

typedef struct _Game Game;

/* Konstruktor za Game */
Game setGame(int mazeHeight, int mazeWidth, int displayHeight, int displayWidth, int blockSize);

void play();

#endif