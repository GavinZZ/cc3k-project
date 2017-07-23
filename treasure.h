#ifndef _TREASURE_H_
#define _TREASURE_H_

#include "item.h"


class Treasure : public Item {
    int val;
public:
    Treasure(std::string s, int row, int col);
    int getVal();
};


#endif
