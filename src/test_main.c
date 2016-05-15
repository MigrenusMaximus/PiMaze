#include "debug.h"

#include "generator.h"

#include <stdio.h>
#include <stdlib.h> /* atoi */
#include <string.h> /* strcmp */

int main(int argc, char** argv) {
    Grid newGrid;
    if (argc >= 3)
        newGrid = generateMaze(atoi(argv[1]), atoi(argv[2]));
    else
        newGrid = generateMaze(20, 20);
    printMaze(&newGrid);
    printf("Test zavrsen.\n");
    return 0;
}