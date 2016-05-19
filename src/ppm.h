#ifndef __PPM_H__
#define __PPM_H__

#include "definitions.h"

#include "color.h"

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

/* Konstruktor za PPMData */
PPMData setPPMData(int maxColor, int width, int height, uint8_t *red, uint8_t *green, uint8_t *blue);
/* Konstruktor za PPMData koji postavlja
   boju svi piksela na crnu (0, 0, 0) */
PPMData setBlackPPMData(int maxColor, int width, int height, uint8_t *red, uint8_t *green, uint8_t *blue);
/* Stvara PPM fajl na datoj lokaciji */
void writePPM(PPMData *ppmData, const char* filename);
/* Postavlja boju svi piksela na onu
   datu u argumentu */
void setPPMColor(PPMData *ppm, Color color);

#endif