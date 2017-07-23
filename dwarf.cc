//
//  dwarf.cpp
//  CC3K
//
//  Created by Apple on 2017-07-19.
//  Copyright © 2017 GavinZ. All rights reserved.
//

#include "dwarf.h"
#include "tgmath.h"


Dwarf::Dwarf(int row, int col) {
    this->row = row;
    this->col = col;
    this->sign = 'W';
    this->health = 100;
    this->Character::attack = 20;
    this->defence = 30;
    isHostile = false;
}

void Dwarf::attack(Player *p) {
    int onHit = rand() % 2;
    if (onHit == 1) {
        p->beAttack(this);
    }
}

void Dwarf::beAttack(Shade* s) {
    int damage = ceil((100/(100+this->defence)))*s->getAttack();
    this->health -= damage;
}

void Dwarf::beAttack(Drow* d) {
    int damage = ceil((100/(100+this->defence)))*d->getAttack();
    this->health -= damage;
}

void Dwarf::beAttack(Vampire* v) {
    int damage = ceil((100/(100+this->defence)))*v->getAttack();
    this->health -= damage;
    v->healthLost(5);
}
void Dwarf::beAttack(Troll *t) {
    int damage = ceil((100/(100+this->defence)))*t->getAttack();
    this->health -= damage;
}

void Dwarf::beAttack(Goblin *g) {
    int damage = ceil((100/(100+this->defence)))*g->getAttack();
    this->health -= damage;
}




