#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include "subject.h"
#include <string>

class Display{
  vector<vector<char>> display;
  public:
  notify(Subject *sub, string action) override;
  ~Display();
}

#endif
