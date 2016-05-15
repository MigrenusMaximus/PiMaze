#include "block.h"

Block setBlock(BOOL isWall, Texture* texture) {
    Block newBlock;
    
    newBlock.isWall = isWall;
    newBlock.texture = texture;
    
    return newBlock;
}