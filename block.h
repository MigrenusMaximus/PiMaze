#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "definitions.h"

struct _Texture {
	/* Visina teksture */
	int height;
	/* Sirina teksture */
	int width;
	/* Matricna reprezentacija teksture */
	Color** colorMap;
};

typedef struct _Texture Texture;

struct _Block {
	/* Da li je zid ili je staza */
	BOOL isWall;
	/* Tekstura */
	Texture texture;
};

typedef struct _Block Block;

#endif