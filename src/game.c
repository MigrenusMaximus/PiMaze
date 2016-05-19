#include "game.h"

#include "generator.h"

Game setGame(int mazeHeight, int mazeWidth, int displayHeight, int displayWidth, int blockSize) {
    Game newGame;
    /* Generisanje labirinta */
    Grid maze = generateMaze(mazeHeight, mazeWidth);
    
}