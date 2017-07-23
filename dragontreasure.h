#ifndef _DRAGONTREASURE_H_
#define _DRAGONTREASURE_H_

#include "dragon.h"
#include "item.h"

class DragonTreasure : public Item{
    int val;
    std::shared_ptr<Dragon> dragon;
public:
    DragonTreasure(std::shared_ptr<Dragon> dragon, int row, int col);
    int getVal();
    bool isDragonDead();
};

#endif
