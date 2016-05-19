#ifndef __GRID_H__
#define __GRID_H__

#include "definitions.h"
#include "block.h"

/*  Grid je osnovni koordinatni sistem koji
 *	odredjuje pozicije i karakteristike zidova
 *	ili manjka istih 
 */
struct _Grid {
	/* Visina u blokovima */
	int height;
	/* Sirina u blokovima */
	int width;
	/* Matrica blokova, koristimo row-major
	   metodu pristupa */
	Block* blocks;
};

typedef struct _Grid Grid;

Grid setGrid(int height, int width, Block* blocks);

#endif