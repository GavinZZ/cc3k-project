
//
//  human.cpp
//  CC3K
//
//  Created by Apple on 2017-07-19.
//  Copyright © 2017 GavinZ. All rights reserved.
//

#include "human.h"
#include "tgmath.h"


Human::Human(int row, int col) {
    this->row = row;
    this->col = col;
    this->sign = 'H';
    this->health = 140;
    this->Character::attack = 20;
    this->defence = 20;
    isHostile = false;
}

void Human::attack(Player *p) {
    int onHit = rand() % 2;
    if (onHit == 1) {
        p->beAttack(this);
    }
}

void Human::beAttack(Shade* s) {
    int damage = ceil((100/(100+this->defence)))*s->getAttack();
    this->health -= damage;
}

void Human::beAttack(Drow* d) {
    int damage = ceil((100/(100+this->defence)))*d->getAttack();
    this->health -= damage;
}

void Human::beAttack(Vampire* v) {
    int damage = ceil((100/(100+this->defence)))*v->getAttack();
    this->health -= damage;
}
void Human::beAttack(Troll *t) {
    int damage = ceil((100/(100+this->defence)))*t->getAttack();
    this->health -= damage;
}

void Human::beAttack(Goblin *g) {
    int damage = ceil((100/(100+this->defence)))*g->getAttack();
    this->health -= damage;
}
