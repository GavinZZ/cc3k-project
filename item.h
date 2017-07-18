#ifndef _ITEM_H_
#define _ITEM_H_

#include "dragontreasure.h"
#include "treasure.h"
#include "potion.h"
#include "stair.h"

class Item {
  protected:
  int row;
  int col;
  int sign;
  public:
  int getCol();
  int getRow();
  int getSign();  
  ~Item();
};

#endif
