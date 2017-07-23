
//
//  merchant.cpp
//  CC3K
//
//  Created by Apple on 2017-07-19.
//  Copyright © 2017 GavinZ. All rights reserved.
//

#include "merchant.h"
#include "tgmath.h"


Merchant::Merchant(int row, int col, bool hosility) {
    this->row = row;
    this->col = col;
    this->sign = 'M';
    this->health = 30;
    this->Character::attack = 70;
    this->defence = 5;
    isHostile = hosility;
}

void Merchant::attack(Player *p) {
    if (getHostile()) {
        int onHit = rand() % 2;
        if (onHit == 1) {
            p->beAttack(this);
        }
    }
}

void Merchant::beAttack(Shade* s) {
    isHostile = true;
    int damage = ceil((100/(100+this->defence)))*s->getAttack();
    this->health -= damage;
}

void Merchant::beAttack(Drow* d) {
    isHostile = true;
    int damage = ceil((100/(100+this->defence)))*d->getAttack();
    this->health -= damage;
}

void Merchant::beAttack(Vampire* v) {
    isHostile = true;
    int damage = ceil((100/(100+this->defence)))*v->getAttack();
    this->health -= damage;
}
void Merchant::beAttack(Troll *t) {
    isHostile = true;
    int damage = ceil((100/(100+this->defence)))*t->getAttack();
    this->health -= damage;
}

void Merchant::beAttack(Goblin *g) {
    isHostile = true;
    int damage = ceil((100/(100+this->defence)))*g->getAttack();
    this->health -= damage;
}
