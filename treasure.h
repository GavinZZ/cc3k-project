#ifndef _TREASURE_H_
#define _TREASURE_H_

#include "item.h"

class Treasure : public Item {
  int val;
  public:
  int getVal();
};


#endif
