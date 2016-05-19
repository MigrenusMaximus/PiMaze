#ifndef __PPM_H__
#define __PPM_H__

#include "definitions.h"

#include <stdint.h>

/* Specifikacija formata http://netpbm.sourceforge.net/doc/ppm.html */

struct _PPMData {
    int maxColor;
    int height;
    int width;
    uint8_t *red;
    uint8_t *green;
    uint8_t *blue;
};

typedef struct _PPMData PPMData;

PPMData createImage(int maxColor, int width, int height, uint8_t *red, uint8_t *green, uint8_t *blue);
void writePPM(PPMData *ppmData, const char* filename);

#endif