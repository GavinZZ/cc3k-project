#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include "subject.h"
#include <string>
#include "observer.h"

class Display : public Observer{
  vector<vector<char>> display;
  public:
  notify(Subject *sub, string action) override;
  ~Display();
};

#endif
