#ifndef __ADDTEXT_H__
#define __ADDTEXT_H__
#include "observer.h"
#include "studio.h"

class addtext: public Observer {
  Studio *subject;
  int top;
  int bot;
  int left;
  int right;

 public:
  addtext( Studio *subject, int top, int bot, int left, int right );
  void notify() override;
  ~addtext();
};

#endif