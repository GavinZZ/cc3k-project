//
//  dwarf.cpp
//  CC3K
//
//  Created by Apple on 2017-07-19.
//  Copyright © 2017 GavinZ. All rights reserved.
//

#include "dwarf.h"
#include "tgmath.h"
using namespace std;

Dwarf::Dwarf(int row, int col) {
    this->row = row;
    this->col = col;
    this->sign = 'W';
    this->health = 100;
    this->Character::attack = 20;
    this->defence = 30;
    isHostile = false;
}

void Dwarf::attack(Player *p, string &action) {
    int onHit = rand() % 2;
    if (onHit == 1) {
        p->beAttack(this, action);
    } else {
        string string = ", W deals 0 to PC";
        action += string;
    }
}

void Dwarf::beAttack(Shade* s, string &action) {
    int damage = 0;
    damage = ceil(s->getAttack()*100/(100+this->defence));
    this->health -= damage;
    string d = intToStr(damage);
    string heal = intToStr(this->health);
    string string = "PC deals " + d + " to " + this->getSign() + "(" + heal + ")";
    action += string;
}

void Dwarf::beAttack(Drow* d, string &action) {
    int damage = 0;
    damage = ceil(d->getAttack()*100/(100+this->defence));
    this->health -= damage;
    string dd = intToStr(damage);
    string heal = intToStr(this->health);
    string string = "PC deals " + dd + " to " + this->getSign() + "(" + heal + ")";
    action += string;
}

void Dwarf::beAttack(Vampire* v, string &action) {
    v->healthLost(5);
    int damage = 0;
    damage = ceil(v->getAttack()*100/(100+this->defence));
    this->health -= damage;
    string d = intToStr(damage);
    string heal = intToStr(this->health);
    string string = "PC deals " + d + " to " + this->getSign() + "(" + heal + ")";
    action += string;
}
void Dwarf::beAttack(Troll *t, string &action) {
    int damage = 0;
    damage = ceil(t->getAttack()*100/(100+this->defence));
    this->health -= damage;
    string d = intToStr(damage);
    string heal = intToStr(this->health);
    string string = "PC deals " + d + " to " + this->getSign() + "(" + heal + ")";
    action += string;
}

void Dwarf::beAttack(Goblin *g, string &action) {
    int damage = 0;
    damage = ceil(g->getAttack()*100/(100+this->defence));
    this->health -= damage;
    string d = intToStr(damage);
    string heal = intToStr(this->health);
    string string = "PC deals " + d + " to " + this->getSign() + "(" + heal + ")";
    action += string;
}




