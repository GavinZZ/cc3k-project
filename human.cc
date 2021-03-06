
//
//  human.cpp
//  CC3K
//
//  Created by Apple on 2017-07-19.
//  Copyright © 2017 GavinZ. All rights reserved.
//

#include "human.h"
#include "tgmath.h"
using namespace std;

Human::Human(int row, int col) {
    this->row = row;
    this->col = col;
    this->sign = 'H';
    this->health = 140;
    this->Character::attack = 20;
    this->defence = 20;
    isHostile = false;
}

void Human::attack(Player *p, string &action) {
    int onHit = rand() % 2;
    if (onHit == 1) {
        p->beAttack(this, action);
    } else {
        string string = ", H deals 0 to PC";
        action += string;
    }
}

void Human::beAttack(Shade* s, string &action) {
    int damage = 0;
    damage = ceil(s->getAttack()*100/(100+this->defence));
    this->health -= damage;
    string d = intToStr(damage);
    string heal = intToStr(this->health);
    string string = "PC deals " + d + " to " + this->getSign() + "(" + heal + ")";
    action += string;
}

void Human::beAttack(Drow* d, string &action) {
    int damage = 0;
    damage = ceil(d->getAttack()*100/(100+this->defence));
    this->health -= damage;
    string dd = intToStr(damage);
    string heal = intToStr(this->health);
    string string = "PC deals " + dd + " to " + this->getSign() + "(" + heal + ")";
    action += string;
}

void Human::beAttack(Vampire* v, string &action) {
    v->healthLost(-5);
    int damage = 0;
    damage = ceil(v->getAttack()*100/(100+this->defence));
    this->health -= damage;
    string d = intToStr(damage);
    string heal = intToStr(this->health);
    string string = "PC deals " + d + " to " + this->getSign() + "(" + heal + ")";
    action += string;
}
void Human::beAttack(Troll *t, string &action) {
    int damage = 0;
    damage = ceil(t->getAttack()*100/(100+this->defence));
    this->health -= damage;
    string d = intToStr(damage);
    string heal = intToStr(this->health);
    string string = "PC deals " + d + " to " + this->getSign() + "(" + heal + ")";
    action += string;
}

void Human::beAttack(Goblin *g, string &action) {
    int damage = 0;
    damage = ceil(g->getAttack()*100/(100+this->defence));
    this->health -= damage;
    string d = intToStr(damage);
    string heal = intToStr(this->health);
    string string = "PC deals " + d + " to " + this->getSign() + "(" + heal + ")";
    action += string;
}
