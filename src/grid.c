#include "grid.h"

Grid setGrid(int height, int width, Block* blocks) {
    Grid newGrid;
    
    newGrid.height = height;
    newGrid.width = width;
    newGrid.blocks = blocks;
    
    return newGrid;
}