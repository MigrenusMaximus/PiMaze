#ifndef __GRID_H__
#define __GRID_H__

#include "definitions.h"
#include "block.h"

/*  Grid je osnovni koordinatni sistem koji
 *	odredjuje pozicije i karakteristike zidova
 *	ili manjka istih 
 */
struct _Grid {
	/* Sirina u blokovima */
	int width;
	/* Visina u blokovima */
	int length;
	/* Matrica blokova */
	Block** blocks;
};

#endif