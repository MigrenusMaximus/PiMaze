#include "debug.h"

/* Koristi se za printf */
#include <stdio.h>

void printColor(Color color) {
    printf("(%d, %d, %d)", color.red, color.green, color.blue);
}

void printMaze(Grid *maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            if(maze->blocks[i][j].isWall == -1) {
                printf("S");
                continue;
            }
            printf("%c", (maze->blocks[i][j].isWall == TRUE ? '.' : ' '));
        }
        printf("\n");
        //printf("\n");        
    }
    printf("\n");
}