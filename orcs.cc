//
//  orcs.cpp
//  CC3K
//
//  Created by Apple on 2017-07-19.
//  Copyright © 2017 GavinZ. All rights reserved.
//

#include "orcs.h"
#include "tgmath.h"


Orcs::Orcs(int row, int col) {
    this->row = row;
    this->col = col;
    this->sign = 'O';
    this->health = 180;
    this->Character::attack = 30;
    this->defence = 25;
    isHostile = false;
}

void Orcs::attack(Player *p) {
    int onHit = rand() % 2;
    if (onHit == 1) {
        p->beAttack(this);
    }
}

void Orcs::beAttack(Shade* s) {
    int damage = ceil((100/(100+this->defence)))*s->getAttack();
    this->health -= damage;
}

void Orcs::beAttack(Drow* d) {
    int damage = ceil((100/(100+this->defence)))*d->getAttack();
    this->health -= damage;
}

void Orcs::beAttack(Vampire* v) {
    int damage = ceil((100/(100+this->defence)))*v->getAttack();
    this->health -= damage;
    v->healthLost(5);
}
void Orcs::beAttack(Troll *t) {
    int damage = ceil((100/(100+this->defence)))*t->getAttack();
    this->health -= damage;
}

void Orcs::beAttack(Goblin *g) {
    int damage = ceil((100/(100+this->defence)))*g->getAttack();
    this->health -= damage;
}
