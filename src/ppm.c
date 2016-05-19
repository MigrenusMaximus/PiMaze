#include "ppm.h"

#include <stdio.h>

PPMData setPPMData(int maxColor, int width, int height, uint8_t *red, uint8_t *green, uint8_t *blue) {
    PPMData newPPMData;
    
    newPPMData.maxColor = maxColor;
    newPPMData.width = width;
    newPPMData.height = height;
    newPPMData.red = red;
    newPPMData.green = green;
    newPPMData.blue = blue;
    
    return newPPMData;
}

PPMData setBlackPPMData(int maxColor, int width, int height, uint8_t *red, uint8_t *green, uint8_t *blue) {
    PPMData newPPMData;
    
    newPPMData.maxColor = maxColor;
    newPPMData.width = width;
    newPPMData.height = height;
    newPPMData.red = red;
    newPPMData.green = green;
    newPPMData.blue = blue;
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            red[i * width + j] = 0;
            green[i * width + j] = 0;
            blue[i * width + j] = 0;
        }
    }
    
    return newPPMData;
}

void writePPM(PPMData *ppmData, const char* filename) {
    FILE *out = fopen(filename, "w");
    /* Format headera:
        P6 whitespace sirina whitespace visina whitespace maxColor whitespace */
    fprintf(out, "P6 %d %d %d\n", ppmData->width, ppmData->height, ppmData->maxColor);
    /* Iz nekog razloga, moramo upisivati GBR umjesto RGB
       Moguce je da je to do testne platforme, ali posto se
       ovaj modul koristi samo za testiranje, nije ni bitno */
    for (int i = 0; i < ppmData->height; i++) {
        for (int j = 0; j < ppmData->width; j++) {
            fwrite(&ppmData->green[i * ppmData->width + j], sizeof(uint8_t), 1, out);
            fwrite(&ppmData->blue[i * ppmData->width + j], sizeof(uint8_t), 1, out);
            fwrite(&ppmData->red[i * ppmData->width + j], sizeof(uint8_t), 1, out);
        }
    }
    
    fclose(out);
}

void setPPMColor(PPMData *ppm, Color color) {
    for (int i = 0; i < ppm->height; i++) {
        for (int j = 0; j < ppm->width; j++) {
            ppm->red[i * ppm->width + j] = color.red;
            ppm->green[i * ppm->width + j] = color.green;
            ppm->blue[i * ppm->width + j] = color.blue;
        }
    }
}