#ifndef __GAME_H__
#define __GAME_H__

#include "definitions.h"

#include "grid.h"

struct _Player {
    /* Pozicija u labirintu */
    int row;
    int column;
    /* Smjer u kojem igrac gleda */
    Direction direction;      
};

typedef struct _Player Player;

/* Konstruktor za Player */
Player setPlayer(int row, int column, Direction direction);

struct _Game {
    /* Labirint */
    Grid *maze;
    /* Da li je igrac dosao do kraja labirinta */
    BOOL hasWon;
    /* Ovo koristimo da znamo da li da
       prikazujemo meni ili igru */
    BOOL isPaused;
    /* Informacije o igracu drzimo u
       odvojenoj strukturi, posto se one uvijek
       zajedno koriste */
    Player player;
};

typedef struct _Game Game;

/* Konstruktor za Game */
Game setGame(int mazeHeight, int mazeWidth);
/* Destruktor za Game */
void destroyGame(Game *game);
/* Game loop */
void play();

#endif