//
//  halfling.cpp
//  CC3K
//
//  Created by Apple on 2017-07-20.
//  Copyright © 2017 GavinZ. All rights reserved.
//

#include "halfling.h"
#include "tgmath.h"
using namespace std;


Halfling::Halfling(int row, int col) {
    this->row = row;
    this->col = col;
    this->sign = 'L';
    this->health = 100;
    this->Character::attack = 15;
    this->defence = 20;
    isHostile = false;
}

void Halfling::attack(Player *p, string &action) {
    int onHit = rand() % 2;
    if (onHit == 1) {
        p->beAttack(this, action);
    } else {
        string string = ", L deals 0 to PC";
        action += string;
    }
}

void Halfling::beAttack(Shade* s, string &action) {
    int onHit = rand() % 2;
    int damage = 0;
    if (onHit) {
        damage = ceil(s->getAttack()*100/(100+this->defence));
        this->health -= damage;
    }
    string d = intToStr(damage);
    string heal = intToStr(this->health);
    string string = "PC deals " + d + " to " + this->getSign() + "(" + heal + ")";
    action += string;
}

void Halfling::beAttack(Drow* d, string &action) {
    int onHit = rand() % 2;
    int damage = 0;
    if (onHit) {
        damage = ceil(d->getAttack()*100/(100+this->defence));
        this->health -= damage;
    }
    string dd = intToStr(damage);
    string heal = intToStr(this->health);
    string string = "PC deals " + dd + " to " + this->getSign() + "(" + heal + ")";
    action += string;
}

void Halfling::beAttack(Vampire* v, string &action) {
    int onHit = rand() % 2;
    int damage = 0;
    if (onHit) {
        v->healthLost(-5);
        damage = ceil(v->getAttack()*100/(100+this->defence));
        this->health -= damage;
    }
    string d = intToStr(damage);
    string heal = intToStr(this->health);
    string string = "PC deals " + d + " to " + this->getSign() + "(" + heal + ")";
    action += string;
}
void Halfling::beAttack(Troll *t, string &action) {
    int onHit = rand() % 2;
    int damage = 0;
    if (onHit) {
        damage = ceil(t->getAttack()*100/(100+this->defence));
        this->health -= damage;
    }
    string d = intToStr(damage);
    string heal = intToStr(this->health);
    string string = "PC deals " + d + " to " + this->getSign() + "(" + heal + ")";
    action += string;
}

void Halfling::beAttack(Goblin *g, string &action) {
    int onHit = rand() % 2;
    int damage = 0;
    if (onHit) {
        damage = ceil(g->getAttack()*100/(100+this->defence));
        this->health -= damage;
    }
    string d = intToStr(damage);
    string heal = intToStr(this->health);
    string string = "PC deals " + d + " to " + this->getSign() + "(" + heal + ")";
    action += string;
}




