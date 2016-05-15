#ifndef __DEFINITIONS_H__
#define __DEFINITIONS_H__

#define TRUE 1
#define FALSE 0
/* Koristimo char za istinitosne vrijednosti
   jer se ne isplati trositi resurse na int ili short */
#define BOOL char

enum _Direction {
    NONE = 0,
    UP = 1,
    RIGHT = 2,
    DOWN = 4,
    LEFT = 8  
};

typedef enum _Direction Direction;

#endif