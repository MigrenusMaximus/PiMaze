#include "block.h"

Block setBlock(BOOL isWall, Texture* texture, BOOL isVisited) {
    Block newBlock;
    
    newBlock.isWall = isWall;
    newBlock.texture = texture;
    newBlock.isVisited = isVisited;
    
    return newBlock;
}