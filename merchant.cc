
//
//  merchant.cpp
//  CC3K
//
//  Created by Apple on 2017-07-19.
//  Copyright © 2017 GavinZ. All rights reserved.
//

#include "merchant.h"
#include "tgmath.h"
using namespace std;

Merchant::Merchant(int row, int col, bool hosility) {
    this->row = row;
    this->col = col;
    this->sign = 'M';
    this->health = 30;
    this->Character::attack = 70;
    this->defence = 5;
    isHostile = hosility;
}

void Merchant::attack(Player *p, string &action) {
    if (isHostile) {
        int onHit = rand() % 2;
        if (onHit == 1) {
            p->beAttack(this, action);
        } else {
            string string = ", M deals 0 to PC";
            action += string;
        }
    }
}

void Merchant::beAttack(Shade* s, string &action) {
    isHostile = true;
    int damage = 0;
    damage = ceil(s->getAttack()*100/(100+this->defence));
    this->health -= damage;
    string d = intToStr(damage);
    string heal = intToStr(this->health);
    string string = "PC deals " + d + " to " + this->getSign() + "(" + heal + ")";
    action += string;
}

void Merchant::beAttack(Drow* d, string &action) {
    isHostile = true;
    int damage = 0;
    damage = ceil(d->getAttack()*100/(100+this->defence));
    this->health -= damage;
    string dd = intToStr(damage);
    string heal = intToStr(this->health);
    string string = "PC deals " + dd + " to " + this->getSign() + "(" + heal + ")";
    action += string;
}

void Merchant::beAttack(Vampire* v, string &action) {
    v->healthLost(-5);
    isHostile = true;
    int damage = 0;
    damage = ceil(v->getAttack()*100/(100+this->defence));
    this->health -= damage;
    string d = intToStr(damage);
    string heal = intToStr(this->health);
    string string = "PC deals " + d + " to " + this->getSign() + "(" + heal + ")";
    action += string;
}
void Merchant::beAttack(Troll *t, string &action) {
    isHostile = true;
    int damage = 0;
    damage = ceil(t->getAttack()*100/(100+this->defence));
    this->health -= damage;
    string d = intToStr(damage);
    string heal = intToStr(this->health);
    string string = "PC deals " + d + " to " + this->getSign() + "(" + heal + ")";
    action += string;
}

void Merchant::beAttack(Goblin *g, string &action) {
    isHostile = true;
    int damage = 0;
    damage = ceil(g->getAttack()*100/(100+this->defence));
    this->health -= damage;
    string d = intToStr(damage);
    string heal = intToStr(this->health);
    string string = "PC deals " + d + " to " + this->getSign() + "(" + heal + ")";
    action += string;
}
