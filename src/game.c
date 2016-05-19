#include "game.h"

#include "generator.h"

Player setPlayer(int row, int column, int xPos, int yPos, float rotation) {
    Player newPlayer;
    
    newPlayer.row = row;
    newPlayer.column = column;
    newPlayer.xPos = xPos;
    newPlayer.yPos = yPos;
    newPlayer.rotation = rotation;
    
    return newPlayer;   
}

Game setGame(int mazeHeight, int mazeWidth, int displayHeight, int displayWidth, int blockSize) {
    Game newGame;
    /* Generisanje labirinta */
    Grid maze = generateMaze(mazeHeight, mazeWidth);
    
}