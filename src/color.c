#include "color.h"

Color setColor(char red, char green, char blue) {
    Color newColor;
    
    newColor.red = red;
    newColor.green = green;
    newColor.blue = blue;
    
    return newColor;
}