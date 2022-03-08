#ifndef __ADDGRAPHICS_H__
#define __ADDGRAPHICS_H__
#include "observer.h"
#include "studio.h"
#include "window.h"

class addgraphics: public Observer {
  Studio *subject;
  Xwindow *xwindow;
  int top;
  int bot;
  int left;
  int right;

 public:
  addgraphics( Studio *subject, int top, int bot, int left, int right );
  void notify() override;
  ~addgraphics();
};

#endif