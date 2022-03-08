#include <iostream>
#include "asciiart.h"
#include "blank.h"
#include "studio.h"
#include "addtext.h"
#include "observer.h"
#include "decorator.h"
#include "subject.h"
#include "boxes.h"
#include "addgraphics.h"
#include <vector>
#include <memory>
using namespace std;

int main () {
  AsciiArt *canvas = new Blank;
  vector<Observer *> vec;

  Studio s{canvas};

  std::string command;

  while (std::cin >> command) {
        if (command == "render" ) {
      s.render();
    }
    else if (command == "animate") {
      int n;
      std::cin >> n;
      s.animate(n);
    }
    else if (command == "reset") {
      s.reset();
    }
    else if (command == "filledbox") {
      int top, bottom, left, right;
      char what;
      std::cin >> top >> bottom >> left >> right >> what;
      canvas = new filledbox{what, top, bottom, left, right, canvas};
      s.picture() = canvas;

    }
    else if (command == "blinkingbox") {
      int top, bottom, left, right;
      char what;
      std::cin >> top >> bottom >> left >> right >> what;
      canvas = new blinkingbox{what, top, bottom, left, right, canvas};
      s.picture() = canvas;

    }
    else if (command == "movingbox") {
      int top, bottom, left, right;
      char what, dir;
      std::cin >> top >> bottom >> left >> right >> what >> dir;
      canvas = new movingbox{what, top, bottom, left, right, dir, canvas};
      s.picture() = canvas;

    }
    else if (command == "maskbox") {
      int top, bottom, left, right;
      char what;
      std::cin >> top >> bottom >> left >> right >> what;
      canvas = new maskbox{what, top, bottom, left, right, canvas};
      s.picture() = canvas;
    }
    else if (command == "addtext") {
      int top, bottom, left, right;
      std::cin >> top >> bottom >> left >> right;
      vec.push_back(new addtext{&s, top, bottom, left, right});
    }
    else if (command == "addgraphics") {
      int top, bottom, left, right;
      std::cin >> top >> bottom >> left >> right;
      vec.push_back(new addgraphics{&s, top, bottom, left, right});
    }
  }
  for(Observer *o: vec) {
    delete o;
  }
}
