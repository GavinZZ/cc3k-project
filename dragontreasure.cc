//
//  dragontreasure.cpp
//  CC3K
//
//  Created by Apple on 2017-07-19.
//  Copyright © 2017 GavinZ. All rights reserved.
//

#include "dragontreasure.h"
using namespace std;

DragonTreasure::DragonTreasure(shared_ptr<Dragon> dragon, int row, int col) {
    val = 6;
    sign = "dragon";
    row = row;
    col = col;
    dragon = dragon;
    isDead = false;
}

int DragonTreasure::getVal() {
    return val;
}


