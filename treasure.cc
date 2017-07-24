//
//  treasure.cpp
//  CC3K
//
//  Created by Apple on 2017-07-19.
//  Copyright © 2017 GavinZ. All rights reserved.
//

#include "treasure.h"
using namespace std;

Treasure::Treasure(string s, int row, int col) {
    sign = s;
    if (s == "normal") {
        val = 2;
    } else if (s == "small") {
        val = 1;
    } else if (s == "merchantH") {
        val = 6;
    }
    this->row = row;
    this->col = col;
}
