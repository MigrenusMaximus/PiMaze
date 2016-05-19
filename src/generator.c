#include "generator.h"

/* Potrebno za generisanje random brojeva */
#include <time.h>
#include <stdlib.h>

#include "stack.h"

/* Debug only - izbrisati */
//#include <stdio.h>
//#include "debug.h"
//#define DEBUG

Grid generateMaze(int height, int width) {
    /* Za labirint velicine n*m nam treba 2n*2m
       celija, s tim da konacni n i m moraju biti
       neparni i moramo da racunamo na vanjske zidove
       pa dodajemo +3 umjesto +1 */
    height = height * 2 + 3;
    width = width * 2 + 3;
    
    /* Maska nam sluzi da lakse mozemo koristiti
       enum Direction za generisanje labirinta */
                      /*      U  R     D            L */
    int rowMask[9]    = { 0, -1, 0, 0, +1, 0, 0, 0, 0 };
    int columnMask[9] = { 0, 0, +1, 0, 0, 0, 0, 0, -1 };
    
    /* Moramo da inicijaliziramo generator nasumicnih
       brojeva da bismo mogli generisati razlicite
       labirinte svaki put */
    srand(time(NULL));
    
    /* Matrica blokova koju cemo koristiti
       koristimo row-major raspored pa je 
       [i][j] == [i * width + j] */
    Block* blocks = (Block*) malloc(height * width * sizeof(Block));
    
    /* Postavljamo pocetno stanje matrice */
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            blocks[i * width + j] = (i % 2 == 0 || j % 2 == 0) ? setBlock(TRUE, NULL, FALSE) : setBlock(FALSE, NULL, FALSE);
    
    /* Deklaracija i definicija pocetnih koordinata
       Koordinate moraju biti na neparnim pozicijama */
    int currentRow, currentColumn;
    
    while ((currentRow = rand() % height) % 2 == 0);
    while ((currentColumn = rand() % width) % 2 == 0);
    
    #ifdef DEBUG
    blocks[currentRow * width + currentColumn].isWall = -1;
    #endif
    
    /* Inicijaliziramo stek na cetvrtinu dimenzija
       posto koristimo samo pola celija u svakoj dimenziji */
    Stack stack;
    stackInit(&stack, width * height / 4);
    
    /* Pocetnu celiju stavljamo na stek i oznacavamo
       kao posjecenu */
    push(&stack, currentRow * width + currentColumn);
    blocks[currentRow * width + currentColumn].isVisited = TRUE;
    
    #ifdef DEBUG
    int visitedCells = 1;
    #endif
    
    while (TRUE) {
        Direction directions = NONE;
        
        for (int i = 0; i < 4; i++) {
            int rowHeading = rowMask[1 << i];
            int columnHeading = columnMask[1 << i];
            /* Ako se nalazimo na rubu ili je ciljana
               celija vec posjecena, preskacemo */
            if (currentRow + rowHeading * 2 < 0 || 
                currentColumn + columnHeading * 2 < 0 ||
                currentRow + rowHeading * 2 >= height ||
                currentColumn + columnHeading * 2 >= width ||
                blocks[(currentRow + rowHeading * 2) * width + currentColumn + columnHeading * 2].isVisited == TRUE)
                continue;
            
            directions |= 1 << i;                
        }
        
        if (directions == NONE) {
            /* Uzimamo proslu celije sa steka
               Ako je stek prazan, znaci da smo zavrsili */
            if (isEmpty(&stack) == FALSE) {
                int newPos = pop(&stack);
                currentColumn = newPos % width;
                currentRow = (newPos - currentColumn) / width;
                continue;
            } else {
                break;
            }
        }
        
        /* Trenutnu celiju stavljamo na stek */
        push(&stack, currentRow * width + currentColumn);
        /* Nasumicni odabir novog smjera */
        Direction newDirection;
        do {
            newDirection = 1 << (rand() % 4);
        } while(!(newDirection & directions));
        /* Relativne koordinate nove celije */
        int rowHeading = rowMask[newDirection];
        int columnHeading = columnMask[newDirection];
        /* Uklanjanje zida i postavljanje nove trenutne celije */
        blocks[(currentRow + rowHeading) * width + currentColumn + columnHeading].isWall = FALSE;
        
        currentRow += rowHeading * 2;
        currentColumn += columnHeading * 2;
        
        blocks[currentRow * width + currentColumn].isVisited = TRUE;
        //blocks[(currentRow + rowHeading * 2) * width + currentColumn + columnHeading * 2].isVisited = TRUE;
        #ifdef DEBUG
        printf("%d: ", ++visitedCells);
        //printf("(%d, %d) -> ", currentRow, currentColumn);
        #endif
        /* Postavljanje nove trenutne celije */
        
        #ifdef DEBUG
        //printf("(%d, %d)", currentRow, currentColumn);
        printf("%s\n", getDirectionAsString(newDirection));
        //Grid tempGrid = setGrid(height, width, blocks);
        //printMaze(&tempGrid);
        printf("\n");
        #endif
    }
    
    blocks[0 * width + 1].isWall = FALSE;
    blocks[(height - 1) * width + width - 2].isWall = FALSE;
    
    Grid newGrid = setGrid(height, width, blocks);
    
    stackDestroy(&stack);
    
    return newGrid;    
}