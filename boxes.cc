#include "decorator.h"
#include "asciiart.h"
#include "boxes.h"

filledbox::filledbox( char c, int top, int bot, int left, int right, AsciiArt *comp )
  : decorator{comp}, c{c}, top{top}, bot{bot}, left{left}, right{right} {}

char filledbox::charAt(int row, int col, int tick) {
    if ( row >= top && row <= bot && col >= left && col <= right) {
        return c;
    }
    else {
        return comp->charAt(row, col, tick);
    }
}

//---------------------------------------------------------------//

blinkingbox::blinkingbox( char c, int top, int bot, int left, int right, AsciiArt *comp )
  : decorator{comp}, c{c}, top{top}, bot{bot}, left{left}, right{right} {}

char blinkingbox::charAt(int row, int col, int tick) {
    if ( row >= top && row <= bot && col >= left && col <= right && tick % 2 == 0) {
        return c;
    }
    else {
        return comp->charAt(row, col, tick);
    }
}

//---------------------------------------------------------------//

maskbox::maskbox( char c, int top, int bot, int left, int right, AsciiArt *comp )
  : decorator{comp}, c{c}, top{top}, bot{bot}, left{left}, right{right} {}

char maskbox::charAt(int row, int col, int tick) {
    if ( row >= top && row <= bot && col >= left && col <= right && comp->charAt(row, col, tick) != ' ') {
        return c;
    }
    else {
        return comp->charAt(row, col, tick);
    }
}

//---------------------------------------------------------------//

movingbox::movingbox( char c, int top, int bot, int left, int right, char direction, AsciiArt *comp )
  : decorator{comp}, c{c}, top{top}, bot{bot}, left{left}, right{right}, direction{direction} {}

char movingbox::charAt(int row, int col, int tick) {
    if (direction == 'd') {
        if ( row >= top + tick && row <= bot + tick && col >= left && col <= right ) {
            return c;
        }
        else {
            return comp->charAt(row, col, tick);
        }
    }
    else if (direction == 'u') {
        if ( row >= top - tick && row <= bot - tick && col >= left && col <= right ) {
            return c;
        }
        else {
            return comp->charAt(row, col, tick);
        }
    }
    else if (direction == 'r') {
        if ( row >= top && row <= bot && col >= left + tick && col <= right + tick ) {
            return c;
        }
        else {
            return comp->charAt(row, col, tick);
        }
    }
    else {
        if ( row >= top && row <= bot && col >= left - tick && col <= right - tick ) {
            return c;
        }
        else {
            return comp->charAt(row, col, tick);
        }
    } 
}