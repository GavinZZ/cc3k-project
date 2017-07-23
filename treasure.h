#ifndef _TREASURE_H_
#define _TREASURE_H_

#include "item.h"


class Treasure : public Item {
public:
    Treasure(std::string s, int row, int col);
};


#endif
