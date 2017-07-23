//
//  halfling.cpp
//  CC3K
//
//  Created by Apple on 2017-07-20.
//  Copyright © 2017 GavinZ. All rights reserved.
//

#include "halfling.h"
#include "tgmath.h"


Halfling::Halfling(int row, int col) {
    this->row = row;
    this->col = col;
    this->sign = 'L';
    this->health = 100;
    this->Character::attack = 15;
    this->defence = 20;
    isHostile = false;
}

void Halfling::attack(Player *p) {
    int onHit = rand() % 2;
    if (onHit == 1) {
        p->beAttack(this);
    }
}

void Halfling::beAttack(Shade* s) {
    int onHit = rand() % 2;
    if (onHit) {
        int damage = ceil((100/(100+this->defence)))*s->getAttack();
        this->health -= damage;
    }
}

void Halfling::beAttack(Drow* d) {
    int onHit = rand() % 2;
    if (onHit) {
        int damage = ceil((100/(100+this->defence)))*d->getAttack();
        this->health -= damage;
    }
}

void Halfling::beAttack(Vampire* v) {
    int onHit = rand() % 2;
    if (onHit) {
        int damage = ceil((100/(100+this->defence)))*v->getAttack();
        this->health -= damage;
    }
}
void Halfling::beAttack(Troll *t) {
    int onHit = rand() % 2;
    if (onHit) {
        int damage = ceil((100/(100+this->defence)))*t->getAttack();
        this->health -= damage;
    }
}

void Halfling::beAttack(Goblin *g) {
    int onHit = rand() % 2;
    if (onHit) {
        int damage = ceil((100/(100+this->defence)))*g->getAttack();
        this->health -= damage;
    }
}




