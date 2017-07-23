#include "item.h"

int Item::getCol() {
    return col;
}

int Item::getRow() {
    return row;
}

int Item::getVal() {
    return val;
}

std::string Item::getSign() {
    return sign;
}

bool Item::getIsDead() {
    return isDead;
}

void Item::setDead() {
    isDead = true;
}
