#include "debug.h"

#include "generator.h"
#include "ppm.h"

#include <stdio.h>
#include <stdlib.h> /* atoi i malloc */
#include <string.h> /* strcmp */
#include <stdint.h> /* uint8_t */

#include <time.h>

int main(int argc, char** argv) {
    srand(time(NULL));
    
    uint8_t *red, *green, *blue;
    int height = 240, width = 320, maxColor = 255;
    red = (uint8_t*) malloc (width * height * sizeof(uint8_t));
    green = (uint8_t*) malloc (width * height * sizeof(uint8_t));
    blue = (uint8_t*) malloc (width * height * sizeof(uint8_t));
    
    PPMData ppm = setPPMData(maxColor, width, height, red, green, blue);
   
    // Color boja1 = { 181, 84, 130 };
    // Color boja2 = { 100, 100, 200 };
    // Color boja3 = { 0, 35, 55 };
    // Color boja4 = { 200, 200, 25 };
    
    Color boje[4];// = { boja1, boja2, boja3, boja4 };
    
    for (int i = 0; i < 4; i++)
        boje[i] = setColor(rand() % 255, rand() % 255, rand() % 255);
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int boj;
            if (i < height / 2)
                if (j < width / 2)
                    boj = 0;
                else
                    boj = 1;
            else
                if (j < width / 2)
                    boj = 2;
                else
                    boj = 3;
            ppm.red[i * width + j] = boje[boj].red;
            ppm.green[i * width + j] = boje[boj].green;
            ppm.blue[i * width + j] = boje[boj].blue;                    
        }
    }
    
    //setPPMColor(&ppm, boja);
    /*
    for (int i = 0; i < height; i++) {
        ppm.red[i * width + i] = 0;
        ppm.green[i * width + i] = 0;
        ppm.blue[i * width + i] = 255;
    }
    */
    
    writePPM(&ppm, "image_test.ppm");
    /*
    Grid newGrid;
    if (argc >= 3)
        newGrid = generateMaze(atoi(argv[1]), atoi(argv[2]));
    else
        newGrid = generateMaze(10, 10);
    printMaze(&newGrid);
    */
    printf("Test zavrsen.\n");
    return 0;
}