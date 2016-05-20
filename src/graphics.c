#include "graphics.h"

#include "color.h"

#include <stdlib.h>

void renderScene(Game *game, int fieldOfView, int width) {
    float increment = fieldOfView / width;
    
    /* Spremamo sliku tako sto donje dvije trecine
       bojimo kao zemlju, a gornju trecinu kao nebo */
    PPMData ppm;
    preparePPM(&ppm);
    
    Color zid = { 180, 50, 0 };
    
    for (float i = -(fieldOfView / 2); i < fieldOfView / 2; i += increment) {
        /* Za sada cemo koristiti samo boju */
        if (game->maze.blocks[raycast(&game->maze, &game->player, i)].isWall == TRUE) {
            
        } else {
            
        }
    }
}

int raycast(Grid *maze, Player *player, float angle) {
    
}

void preparePPM(PPMData *ppm) {
    uint8_t *red, *green, *blue;
    int height = 240, width = 320, maxColor = 255;
    red = (uint8_t*) malloc (width * height * sizeof(uint8_t));
    green = (uint8_t*) malloc (width * height * sizeof(uint8_t));
    blue = (uint8_t*) malloc (width * height * sizeof(uint8_t));
    
    PPMData ppm = setPPMData(maxColor, width, height, red, green, blue);
    
    Color zemlja = { 150, 150, 150 };
    Color nebo   = { 150, 150, 255 };
    
    for (int i = 0; i < height / 3; i++) {
        for (int j = 0; j < width; j++) {
            ppm.red[i * width + j]   = nebo.red;
            ppm.green[i * width + j] = nebo.green;
            ppm.blue[i * width + j]  = nebo.blue;
        }
    }
    
    for (int i = height / 3 - 1; i < height; i++) {
        for (int j = 0; j < width; j++) {            
            ppm.red[i * width + j]   = zemlja.red;
            ppm.green[i * width + j] = zemlja.green;
            ppm.blue[i * width + j]  = zemlja.blue;
        }
    }
}