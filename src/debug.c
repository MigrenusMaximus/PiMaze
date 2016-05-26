#include "debug.h"

/* Koristi se za printf */
#include <stdio.h>

void printColor(Color color) {
    printf("(%d, %d, %d)", color.red, color.green, color.blue);
}

void printMaze(Grid *maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            if(maze->blocks[i * maze->width + j].isWall == -1) {
                printf("S");
                continue;
            }
            printf("%c", (maze->blocks[i * maze->width + j].isWall == TRUE ? '+' : ' '));
        }
        // printf("  Ispisan %d-ti red\n", i);
        printf("\n");
    }
    printf("\n");
}

void printGame(Game *game) {
    for (int i = 0; i < game->maze->height; i++) {
        for (int j = 0; j < game->maze->width; j++) {
            // if(game->maze->blocks[i * game->maze->width + j].isWall == -1) {
            //     printf("S");
            //     continue;
            // }
            if (game->player.row == i && game->player.column == j) {
                printf("P");
                continue;
            }
            printf("%c", (game->maze->blocks[i * game->maze->width + j].isWall == TRUE ? '+' : ' '));
        }
        // printf("  Ispisan %d-ti red\n", i);
        printf("\n");
    }
    printf("\n");
}