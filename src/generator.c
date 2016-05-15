#include "generator.h"

/* Potrebno za generisanje random brojeva */
#include <time.h>
#include <stdlib.h>

#include "stack.h"

Grid generateMaze(int height, int width, Texture* wallTexture) {
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
    
    /* Bacamo novcic, ako je 1, onda nam je pocetak
       labirinta na vrhu ili dnu, a ako je 0, pocetak
       je s lijeve ili s desne strane */
    if (rand() % 2 == 1) {
        currentRow = rand() % 2 ? 0 : height - 1;
        currentColumn = rand() % width;
    } else {
        currentRow = rand() % height;
        currentColumn = rand() % 2 ? 0 : width - 1;
    }
    
    /* Posto smo posjetili prvu celiju */
    visitedCells += 1;
    
    Stack stack;
    /* Iako nam nece biti potrebno toliko memorije, 
       inicijalaziriamo stek na visina * sirina */
    stackInit(&stack, height * width);
    /* Postavljamo prvu celiju */
    push(&stack, currentRow * width + currentColumn);
    /* Otvaramo prvu celiju */
    blocks[currentRow][currentColumn].isWall = FALSE; 
    
    /* Petlja se izvrsava dok ne posjetimo sve celije */
    while (visitedCells < width * height) {
        /* U directions drzimo smjerove u kojima se
           algoritam smije kretati */
        Direction directions = NONE;
        
        if (currentRow > 1 && blocks[currentRow - 1][currentColumn].isWall == 2)
            directions |= UP;
        if (currentRow < height - 1 && blocks[currentRow + 1][currentColumn].isWall == 2)
            directions |= DOWN;
        if (currentColumn > 1 && blocks[currentRow][currentColumn - 1].isWall == 2)
            directions |= LEFT;
        if (currentColumn < width - 1 && blocks[currentRow][currentColumn + 1].isWall == 2)
            directions |= RIGHT;
        
        /* Ako nema neposjecenih komsija provjeravamo
           da li postoji ijedna celija da ih ima na steku */
        if (directions == NONE) {
            if (isEmpty(&stack) == FALSE) {
                
            } else {
                /* Ako nema vise celija na steku,
                   znaci da smo zavrsili */
                break;
            }
        }
    }
}

void init() {
    srand(time(NULL));
}