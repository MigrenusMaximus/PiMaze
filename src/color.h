#ifndef __COLOR_H__
#define __COLOR_H__

#include <stdio.h>

#include "definitions.h"

/*  
 *	Banggood displej ima 18-bitni color space. Svaka komponenta
 *	(R, G, B) je definisana sa 6 bita, stoga koristimo char za
 *	smjestanje vrijednosti. Dva najznacajnija bita cemo ignorisati.
 */

struct _Color {
	char red;
	char green;
	char blue;
};

/*
 *  Definisanje strukture kao tipa
 */

typedef struct _Color Color;

/*
 *  TODO: Dodati predefinisane boje
 */
 
 /*
  *  Deklaracije funckija
  */

/* Shorthand za postavljanje komponenti boje */
Color setColor(char red, char green, char blue);

#endif