#ifndef __MOVEMENT_H__
#define __MOVEMENT_H__

#include "definitions.h"

struct _Movement {
    float xAmount;
    float yAmount;
};

typedef struct _Movement Movement;

/* Polla se ulazni uredjaj i vraca
   se koliko se treba pomjeriti po
   x i y koordinatama */
Movement getMovement();

#endif