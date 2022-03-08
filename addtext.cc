#include <iostream>
#include "addtext.h"
using namespace std;

addtext::addtext( Studio *subject, int top, int bot, int left, int right )
    : subject{subject}, top{top}, bot{bot}, left{left}, right{right}
{
  subject->attach( this );
}

addtext::~addtext() {
  subject->detach( this );
}

void addtext::notify() {
  cout << '+';
  for (int j = left; j <= right; ++j) cout << '-';
  cout << '+' << std::endl;
  for (int i = top; i <= bot; ++i) {
    cout << '|';
    for (int j = left; j <= right; ++j) {
      cout << subject->getState(i, j);
    }
    cout << '|' << std::endl;
  }
  cout << '+';
  for (int j = left; j <= right; ++j) cout << '-';
  cout << '+' << std::endl;
}