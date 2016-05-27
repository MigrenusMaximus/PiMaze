#include "debug.h"

#include "game.h"
#include "ppm.h"

#include <stdio.h>
#include <stdlib.h> /* atoi i malloc */
#include <string.h> /* strcmp */
#include <stdint.h> /* uint8_t */

void drawLine(PPMData *ppm, Color color, int x0, int x1, int y0, int y1, int width);
void drawPolygon(PPMData *ppm, Color color, int x0, int x1, int y0, int y1, int width, int height);

int main(int argc, char** argv) {
    Game newGame = setGame(10, 10);
    printGame(&newGame);
    
    int width = 320, height = 240;
    uint8_t *red, *green, *blue;
    red = (uint8_t*) malloc (width * height * sizeof(uint8_t));
    green = (uint8_t*) malloc (width * height * sizeof(uint8_t));
    blue = (uint8_t*) malloc (width * height * sizeof(uint8_t));
    
    PPMData ppm = setPPMData(255, 320, 240, red, green, blue);
    
    Color zemlja = { 150, 150, 150 };
    Color nebo   = { 150, 150, 255 };
    
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            ppm.red[i * width + j]   = nebo.red;
            ppm.green[i * width + j] = nebo.green;
            ppm.blue[i * width + j]  = nebo.blue;
        }
    }
    
    for (int i = height / 2 - 1; i < height; i++) {
        for (int j = 0; j < width; j++) {            
            ppm.red[i * width + j]   = zemlja.red;
            ppm.green[i * width + j] = zemlja.green;
            ppm.blue[i * width + j]  = zemlja.blue;
        }
    }
    
    
    
    int dim;
    
    float konDim;
    
    for (dim = 0; dim < height; dim++) {
        if (newGame.maze->blocks[(dim + newGame.player.row) * newGame.maze->width + 1].isWall == TRUE) {
            //printf("Na %d", dim);
            //printf("\nDimenzije: %fx%f\n", 0.75f * (3.0f / (3.0f + 6.0f * (float)dim)), 0.75f * (3.0f / (3.0f + 6.0f * (float)dim)));
            konDim = 0.75f * (3.0f / (3.0f + 6.0f * (float)dim));
            break;
        }
    }
    
    int diff = (width - height) / 2;
    
    int yMin = (1 - konDim) / 2 * height;
    int yMax = yMin + konDim * height;
    int xMin = diff + yMin;
    int xMax = diff + yMax; 
    
    //printf("Okvir = (%d, %d) - (%d, %d)\n", yMin, xMin, yMax, xMax);
    /*
    for (int i = yMin; i <= yMax; i++) {
        for (int j = xMin; j <= xMax; j++) {
            if (i == yMin || i == yMax || j == xMin || j == xMax) {
                ppm.red[i * width + j]   = 255;//setColor(255, 0, 0).red;
                ppm.green[i * width + j] = 255;//setColor(255, 0, 0).green;
                ppm.blue[i * width + j]  = 0;//setColor(255, 0, 0).blue;
            }
        }        
    } */
    drawPolygon(&ppm, setColor(0, 255, 0), xMin, xMax, yMin, yMin, width, height);
    
    int top, bottom, left, right;
    int oldTop = 0, oldBottom = height - 1, oldLeft = diff, oldRight = width - diff;
    float newDim;
    
    for (int i = 0; i < dim; i++) {
        newDim = 0.75f * (3.0f / (3.0f + 6.0f * (float)i));
        top = (1 - newDim) / 2 * height;
        bottom = top + newDim * height;
        left = diff + top;
        right = diff + bottom;
        //printf("%d | Top: %d, Bottom: %d, Left: %d, Right: %d\n", i, top, bottom, left, right);
        for (int j = top; j <= bottom; j++) {
            ppm.red  [j * width + left] = 255;
            ppm.green[j * width + left] = 0;
            ppm.blue [j * width + left] = 0;
            ppm.red  [j * width + right] = 255; 
            ppm.green[j * width + right] = 0;
            ppm.blue [j * width + right] = 0;
        }
        //[(dim + newGame.player.row + 1) * newGame.maze->width + 1].isWall == TRUE
        if (newGame.maze->blocks[(i + newGame.player.row + 1) * newGame.maze->width + 2].isWall == TRUE) {
            drawPolygon(&ppm, setColor(0, 255, 255), oldLeft, left, oldTop, top, width, height);
            //drawPolygon(&ppm, setColor(0, 255, 255), oldLeft, left, oldBottom, bottom, width, height);
            if (oldLeft == diff) 
                drawPolygon(&ppm, setColor(0, 255, 255), 0, oldLeft, 0, 0, width, height);
        } else {
            if (oldLeft == diff) 
                drawPolygon(&ppm, setColor(0, 255, 0), 0, left, top, top, width, height);
            else
                drawPolygon(&ppm, setColor(0, 255, 0), oldLeft + 1, left, top, top, width, height);
            //drawPolygon(&ppm, setColor(0, 255, 0), oldLeft, left, bottom, bottom, width, height);
        }
        if (newGame.maze->blocks[(i + newGame.player.row + 1) * newGame.maze->width + 0].isWall == TRUE) {
            drawPolygon(&ppm, setColor(0, 255, 255), oldRight, right, oldTop, top, width, height);
            //drawPolygon(&ppm, setColor(0, 255, 255), oldRight, right, oldBottom, bottom, width, height);
            if (oldRight == width - diff) 
                drawPolygon(&ppm, setColor(0, 255, 255), oldRight, width - 1, 0, 0, width, height);
        } else {
            if (oldRight == width - diff) 
                drawPolygon(&ppm, setColor(0, 255, 0), oldRight, width - 1, top, top, width, height);
            else    
                drawPolygon(&ppm, setColor(0, 255, 0), oldRight, right - 1, top, top, width, height);
            //drawPolygon(&ppm, setColor(0, 255, 0), oldRight, right, bottom, bottom, width, height);
        }
        oldBottom = bottom;
        oldTop = top;
        oldLeft = left;
        oldRight = right;
    }
    
    if (newGame.maze->blocks[(dim + newGame.player.row + 1) * newGame.maze->width + 2].isWall == TRUE) {
        drawPolygon(&ppm, setColor(0, 255, 255), oldLeft, xMin, oldTop, yMin, width, height);
        //drawPolygon(&ppm, setColor(0, 255, 255), oldLeft, xMin, oldBottom, yMax, width, height);
    } else {
        drawPolygon(&ppm, setColor(0, 255, 0), oldLeft + 1, xMin, yMin, yMin, width, height);
        //drawPolygon(&ppm, setColor(0, 255, 0), oldLeft, xMin, yMax, yMax, width, height);
    }
    if (newGame.maze->blocks[(dim + newGame.player.row + 1) * newGame.maze->width + 0].isWall == TRUE) {
        drawPolygon(&ppm, setColor(0, 255, 255), oldRight, xMax + 1, oldTop, yMin, width, height);
        //drawPolygon(&ppm, setColor(0, 255, 255), oldRight, xMax, oldBottom, yMax, width, height);
    } else {
        drawPolygon(&ppm, setColor(0, 255, 255), oldRight, xMax, yMin, yMin, width, height);
        //drawPolygon(&ppm, setColor(0, 255, 255), oldRight, xMax, yMax, yMax, width, height);
    }
    
    writePPM(&ppm, "distance_test.ppm");
    
    printf("Test zavrsen.\n");
    return 0;
}

/*
void line(int x0, int y0, int x1, int y1) {
 
  int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
  int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
  int err = (dx>dy ? dx : -dy)/2, e2;
 
  for(;;){
    setPixel(x0,y0);
    if (x0==x1 && y0==y1) break;
    e2 = err;
    if (e2 >-dx) { err -= dy; x0 += sx; }
    if (e2 < dy) { err += dx; y0 += sy; }
  }
}
*/

void drawLine(PPMData *ppm, Color color, int x0, int x1, int y0, int y1, int width) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1; 
    int err = (dx > dy ? dx : -dy) / 2, e2;
    
    for(;;){
        ppm->red  [y0 * width + x0] = color.red;
        ppm->green[y0 * width + x0] = color.green;
        ppm->blue [y0 * width + x0] = color.blue;
        if (x0 == x1 && y0 == y1) 
            break;
        e2 = err;
        if (e2 > -dx) { 
            err -= dy; 
            x0 += sx; 
        }
        if (e2 < dy) { 
            err += dx; 
            y0 += sy; 
        }
    }
}

void drawPolygon(PPMData *ppm, Color color, int x0, int x1, int y0, int y1, int width, int height) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1; 
    int err = (dx > dy ? dx : -dy) / 2, e2;
    //int tempY = y0;
    for(;;) {
        drawLine(ppm, color, x0, x0, y0, height - y0, width);
        // ppm->red  [y0 * width + x0] = color.red;
        // ppm->green[y0 * width + x0] = color.green;
        // ppm->blue [y0 * width + x0] = color.blue;
        if (x0 == x1 && y0 == y1) 
            break;
        e2 = err;
        if (e2 > -dx) { 
            err -= dy; 
            x0 += sx; 
        }
        if (e2 < dy) { 
            err += dx; 
            y0 += sy; 
        }
    }
}