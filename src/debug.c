#include "debug.h"

/* Koristi se za printf */
#include <stdio.h>

void printColor(Color color) {
    printf("(%d, %d, %d)", color.red, color.green, color.blue);
}

void printMaze(Grid *maze) {
    for (int i = 0; i < maze->height; i++)
        for (int j = 0; j < maze->width; j++)
            printf("%c", (maze->blocks[height][width].isWall == TRUE ? '0' : ' '));
}