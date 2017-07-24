//
//  orcs.cpp
//  CC3K
//
//  Created by Apple on 2017-07-19.
//  Copyright © 2017 GavinZ. All rights reserved.
//

#include "orcs.h"
#include "tgmath.h"
using namespace std;


Orcs::Orcs(int row, int col) {
    this->row = row;
    this->col = col;
    this->sign = 'O';
    this->health = 180;
    this->Character::attack = 30;
    this->defence = 25;
    isHostile = false;
}

void Orcs::attack(Player *p, string &action) {
    int onHit = rand() % 2;
    if (onHit == 1) {
        p->beAttack(this, action);
    } else {
        string string = ", O deals 0 to PC";
        action += string;
    }
}

void Orcs::beAttack(Shade* s, string &action) {
    int damage = 0;
    damage = ceil(s->getAttack()*100/(100+this->defence));
    this->health -= damage;
    string d = intToStr(damage);
    string heal = intToStr(this->health);
    string string = "PC deals " + d + " to " + this->getSign() + "(" + heal + ")";
    action += string;
}

void Orcs::beAttack(Drow* d, string &action) {
    int damage = 0;
    damage = ceil(d->getAttack()*100/(100+this->defence));
    this->health -= damage;
    string dd = intToStr(damage);
    string heal = intToStr(this->health);
    string string = "PC deals " + dd + " to " + this->getSign() + "(" + heal + ")";
    action += string;
}

void Orcs::beAttack(Vampire* v, string &action) {
    v->healthLost(-5);
    int damage = 0;
    damage = ceil(v->getAttack()*100/(100+this->defence));
    this->health -= damage;
    string d = intToStr(damage);
    string heal = intToStr(this->health);
    string string = "PC deals " + d + " to " + this->getSign() + "(" + heal + ")";
    action += string;
}
void Orcs::beAttack(Troll *t, string &action) {
    int damage = 0;
    damage = ceil(t->getAttack()*100/(100+this->defence));
    this->health -= damage;
    string d = intToStr(damage);
    string heal = intToStr(this->health);
    string string = "PC deals " + d + " to " + this->getSign() + "(" + heal + ")";
    action += string;
}

void Orcs::beAttack(Goblin *g, string &action) {
    int damage = 0;
    damage = ceil(g->getAttack()*100/(100+this->defence));
    this->health -= damage;
    string d = intToStr(damage);
    string heal = intToStr(this->health);
    string string = "PC deals " + d + " to " + this->getSign() + "(" + heal + ")";
    action += string;
}
