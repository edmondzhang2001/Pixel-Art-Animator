#ifndef _BOXES_H_
#define _BOXES_H_
#include "decorator.h"
class AssciiArt;



class filledbox: public decorator {
    char c;
    int top;
    int bot;
    int left;
    int right;
 public:
    filledbox( char c, int top, int bot, int left, int right, AsciiArt *comp );
    char charAt(int row, int col, int tick) override;
 
};

class blinkingbox: public decorator {
    char c;
    int top;
    int bot;
    int left;
    int right;
 public:
    blinkingbox( char c, int top, int bot, int left, int right, AsciiArt *comp );
    char charAt(int row, int col, int tick) override;
 
};

class maskbox: public decorator {
    char c;
    int top;
    int bot;
    int left;
    int right;
 public:
    maskbox( char c, int top, int bot, int left, int right, AsciiArt *comp );
    char charAt(int row, int col, int tick) override;
  
};



class movingbox: public decorator {
    char c;
    int top;
    int bot;
    int left;
    int right;
    char direction;
 public:
    movingbox( char c, int top, int bot, int left, int right, char direction, AsciiArt *comp );
    char charAt(int row, int col, int tick) override;
};





#endif