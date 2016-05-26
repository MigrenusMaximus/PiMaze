#include "game.h"

#include "generator.h"

#include <stdlib.h> /* malloc i free */

#include "debug.h"

Player setPlayer(int row, int column, Direction direction) {
    Player newPlayer;
    
    newPlayer.row = row;
    newPlayer.column = column;
    newPlayer.direction = direction;
    
    return newPlayer;   
}

Game setGame(int mazeHeight, int mazeWidth) {
    Game newGame;
    /* Generisanje labirinta */
    newGame.maze = (Grid*) malloc(sizeof(Grid));
    *newGame.maze = generateMaze(mazeHeight, mazeWidth);
    /* Generisanje igraca */
    newGame.player = setPlayer(0, 1, DOWN);
    return newGame;
}

void destroyGame(Game *game) {
    free(game->maze);
}