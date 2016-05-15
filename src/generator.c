#include "generator.h"

/* Potrebno za generisanje random brojeva */
#include <time.h>
#include <stdlib.h>

#include "stack.h"

/* Debug only - izbrisati */
#include <stdio.h>

Grid generateMaze(int height, int width) {//, Texture* wallTexture) {
    srand(time(NULL));
    
    Block** blocks;
    blocks = (Block**) malloc(height * sizeof(Block*));
    
    for(int i = 0; i < height; i++) {
        blocks[i] = (Block*) malloc(width * sizeof(Block));
        /* Svaki blok postavljamo na nultu vrijednost */
        for(int j = 0; j < width; j++) {
            /* Postavljamo na 2 da znamo da nije posjeceno */
            blocks[i][j].isWall = 2;
            //blocks[i][j].texture = ""
        }
    }
    
    int currentRow, currentColumn;
    int visitedCells = 0;
    Direction startingDirection = NONE;
    
    /* Bacamo novcic, ako je 1, onda nam je pocetak
       labirinta na vrhu ili dnu, a ako je 0, pocetak
       je s lijeve ili s desne strane */
    if (rand() % 2 == 1) {
        currentRow = rand() % 2 ? 0 : height - 1;
        currentColumn = rand() % (width - 1) + 1;
        startingDirection = (currentRow == 0) ? DOWN : UP;
    } else {
        currentRow = rand() % (height - 1) + 1;
        currentColumn = rand() % 2 ? 0 : width - 1;
        startingDirection = (currentColumn == 0) ? RIGHT : LEFT;
    }
    
    /* Posto smo posjetili prvu celiju */
    visitedCells += 1;
    
    Stack stack;
    /* Iako nam nece biti potrebno toliko memorije, 
       inicijalaziriamo stek na visina * sirina */
    stackInit(&stack, height * width);
    /* Otvaramo prvu celiju */
    blocks[currentRow][currentColumn].isWall = -1; /* DEBUG */ 
    
    printf("Starting cell: (%d, %d)\n", currentRow, currentColumn);
    printf("Starting direction: %d\n", startingDirection);
    
    /* Petlja se izvrsava dok ne posjetimo sve celije
       iako se ovaj exit condition nikada ne bi trebao
       triggerovati */
    while (visitedCells < width * height) {
        /* U directions drzimo smjerove u kojima se
           algoritam smije kretati */
        Direction directions = startingDirection;
        startingDirection = NONE;
        /* Ako je directions razlicit od NONE,
           znaci da nam je postavljen startingDirection */
        if (!directions) {
            /* Iskljucujemo rubne blokove jer zelimo ostaviti vanjski zid */
            if (currentRow > 2 && blocks[currentRow - 2][currentColumn].isWall == 2) {
                directions |= UP;
            }
            if (currentRow < height - 2 && blocks[currentRow + 2][currentColumn].isWall == 2) {
                directions |= DOWN;
            }
            if (currentColumn > 2 && blocks[currentRow][currentColumn - 2].isWall == 2) {
                directions |= LEFT;
            }
            if (currentColumn < width - 2 && blocks[currentRow][currentColumn + 2].isWall == 2) {
                directions |= RIGHT;
            }
        }
        
        /* Ako nema neposjecenih komsija provjeravamo
           da li postoji ijedna celija da ih ima na steku */
        if (directions == NONE) {
            if (isEmpty(&stack) == FALSE) {
                /* Uzimamo proslu celiju za trenutnu */
                int newPos = pop(&stack);
                /* Postavljamo koordinate */
                currentColumn = newPos % width;
                currentRow = (newPos - currentColumn) / width;
            } else {
                /* Ako nema vise celija na steku,
                   znaci da smo zavrsili */
                break;
            }
        } else {
            int newDirection;
            do {
                /* Pomjeramo 1 ulijevo za 0-3 mjesta i tako biramo
                   novi smjer */
                newDirection = 1 << (rand() % 4);
                /* Provjeravamo da li smo dobili jedan od mogucih smjerova */
            } while(!(newDirection &= directions));
            /* Trenutnu celiju postavljamo na stazu */
            //blocks[currentRow][currentColumn].isWall = FALSE;
            /* Trenutnu celiju smjestamo na stek */
            push(&stack, currentRow * width + currentColumn);
            /* Odredjujemo novu trenutnu celiju */
            switch(newDirection) {
                case UP:
                    currentRow -= 2;
                    blocks[currentRow + 1][currentColumn].isWall = FALSE;
                    //printf("Izbrisan zid na (%d, %d)\n", currentRow + 1, currentColumn);
                    break;
                case RIGHT:
                    currentColumn += 2;
                    blocks[currentRow][currentColumn - 1].isWall = FALSE;
                    //printf("Izbrisan zid na (%d, %d)\n", currentRow, currentColumn - 1);
                    break;
                case DOWN:
                    currentRow += 2;
                    blocks[currentRow - 1][currentColumn].isWall = FALSE;
                    //printf("Izbrisan zid na (%d, %d)\n", currentRow - 1, currentColumn);
                    break;
                case LEFT:
                    currentColumn -= 2;
                    blocks[currentRow][currentColumn + 1].isWall = FALSE;
                    //printf("Izbrisan zid na (%d, %d)\n", currentRow, currentColumn - 1);
                    break;
                default:
                    /* Ako smo ovdje, desila se greska */
                    break;
            }
            /* Oznacavamo novu celiju kao posjecenu */
            blocks[currentRow][currentColumn].isWall = FALSE;
        }
        /* Inkrementiramo brojac posjecenih celija */
        //visitedCells += 1;
    }
    
    /* Nakon sto smo napravili put kroz labirint
       postavljamo neposjecene celije na zidove */
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            if(blocks[i][j].isWall == 2)
                blocks[i][j].isWall = TRUE;
                
    /* Vracamo novi Grid */
    return setGrid(height, width, blocks);
}

void init() {
    srand(time(NULL));
}