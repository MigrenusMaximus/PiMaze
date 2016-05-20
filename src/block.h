#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "definitions.h"
#include "texture.h"

struct _Block {
	/* Da li je zid ili je staza. */
	BOOL isWall;
	/* Pokazivac na teksturu
	   Koristimo pokazivac jer nema razloga da trosimo memoriju
	   svaki put kad inicijaliziramo novi blok ako ce se vecina
	   tekstra reusati. */
	Texture* texture;
	/* Da li je blok posjecen - koristi se tokom
	   generacije labirinta */
	BOOL isVisited;
};

typedef struct _Block Block;

/* Konstruktor za Block */
Block setBlock(BOOL isWall, Texture* texture, BOOL isVisited);

#endif
