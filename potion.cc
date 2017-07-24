//
//  potion.cpp
//  CC3K
//
//  Created by Apple on 2017-07-19.
//  Copyright © 2017 GavinZ. All rights reserved.
//

#include "potion.h"
using namespace std;

Potion::Potion(string s, int row, int col) {
    val = -1;
    sign = s;
    this->row = row;
    this->col = col;
}
