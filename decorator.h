#ifndef _DECORATOR_H_
#define _DECORATOR_H_
#include "asciiart.h"

class decorator: public AsciiArt {
    protected:
        AsciiArt *comp;
    public:
        decorator( AsciiArt *comp );
        virtual ~decorator();
};




#endif