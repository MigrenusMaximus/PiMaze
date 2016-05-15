#include "debug.h"

#include "generator.h"

#include <stdio.h>

int main() {
    Grid newGrid = generateMaze(20, 20);
    printMaze(&newGrid);
    printf("Test zavrsen.\n");
    return 0;
}