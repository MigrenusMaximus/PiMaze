#ifndef __BLOCK_H__
#define __BLOCK_H__

#include "definitions.h"
#include "texture.h"

struct _Block {
	/* Da li je zid ili je staza.
       ": 1" oznacava da nam je za spremanje
       atributa portreban samo jedan bajt memorije */
	BOOL isWall;
	/* Pokazivac na teksturu
	   Koristimo pokazivac jer nema razloga da trosimo memoriju
		 svaki put kad inicijaliziramo novi blok ako ce se vecina
		 tekstra reusati.
	*/
	Texture* texture;
};

typedef struct _Block Block;

Block setBlock(BOOL isWall, Texture* texture);

#endif
