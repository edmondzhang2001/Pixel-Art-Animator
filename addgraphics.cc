#include <iostream>
#include "addgraphics.h"
using namespace std;

addgraphics::addgraphics( Studio *subject, int top, int bot, int left, int right )
    : subject{subject}, top{top}, bot{bot}, left{left}, right{right}
{
  subject->attach( this );
  Xwindow *x = new Xwindow(10*(right - left + 1), 10*(bot - top + 1));
  this->xwindow = x;
}

addgraphics::~addgraphics() {
  subject->detach( this );
  delete xwindow;
}

void addgraphics::notify() {
    int k = 0;
    for (int j = top; j <= bot; ++j) {
        int l = 0;
        for (int i = left; i <= right; ++i) {
            char c = subject->getState(j, i);
            if ( c == ' ') {
                this->xwindow->fillRectangle(l, k, 10, 10, Xwindow::White);
                l+=10;
            }
            else if (c >= 'a' && c <= 'z') {
                this->xwindow->fillRectangle(l, k, 10, 10, Xwindow::Red);
                l+=10;
            }
            else if (c >= 'A' && c <= 'Z') {
                this->xwindow->fillRectangle(l, k, 10, 10, Xwindow::Green);
                l+=10;
            }
            else if (c >= '0' && c <= '9') {
                this->xwindow->fillRectangle(l, k, 10, 10, Xwindow::Blue);
                l+=10;
            }
            else {
                this->xwindow->fillRectangle(l, k, 10, 10, Xwindow::Black);
                l+=10;
            }

        }
        k+=10;
    }
}
