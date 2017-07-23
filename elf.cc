//
//  elf.cpp
//  CC3K
//
//  Created by Apple on 2017-07-19.
//  Copyright © 2017 GavinZ. All rights reserved.
//

#include "elf.h"
#include "tgmath.h"


Elf::Elf(int row, int col) {
    this->row = row;
    this->col = col;
    this->sign = 'E';
    this->health = 140;
    this->Character::attack = 30;
    this->defence = 10;
    isHostile = false;
}

void Elf::attack(Player *p) {
    int onHit = rand() % 2;
    if (onHit == 1) {
        p->beAttack(this);
    }
}

void Elf::beAttack(Shade* s) {
    int damage = ceil((100/(100+this->defence)))*s->getAttack();
    this->health -= damage;
}

void Elf::beAttack(Drow* d) {
    int damage = ceil((100/(100+this->defence)))*d->getAttack();
    this->health -= damage;
}

void Elf::beAttack(Vampire* v) {
    int damage = ceil((100/(100+this->defence)))*v->getAttack();
    this->health -= damage;
    v->healthLost(5);
}
void Elf::beAttack(Troll *t) {
    int damage = ceil((100/(100+this->defence)))*t->getAttack();
    this->health -= damage;
}

void Elf::beAttack(Goblin *g) {
    int damage = ceil((100/(100+this->defence)))*g->getAttack();
    this->health -= damage;
}
