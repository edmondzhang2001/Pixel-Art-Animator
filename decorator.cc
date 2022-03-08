#include "asciiart.h"
#include "decorator.h"

decorator::decorator( AsciiArt *comp )
  : comp{comp} {}

decorator::~decorator() { delete comp; }