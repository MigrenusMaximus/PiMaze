#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include "definitions.h"
#include "color.h"

struct _Texture {
	/* Visina teksture */
	int height;
	/* Sirina teksture */
	int width;
	/* Matricna reprezentacija teksture */
	Color *colorMap;
};

typedef struct _Texture Texture;

/* Postavljanje teksture iz mape boja i njenih dimenzija */
Texture setTexture(Color *colorMap, int height, int width);

#endif