#include "definitions.h"

const char* getDirectionAsString(Direction direction) {
    switch (direction) {
        case UP:
            return "UP";
        case RIGHT:
            return "RIGHT";
        case DOWN:
            return "DOWN";
        case LEFT:
            return "LEFT";
        case NONE:
            return "NONE";
        default:
            return "ERROR";
    }
}