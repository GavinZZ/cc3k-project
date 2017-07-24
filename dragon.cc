
#include "dragon.h"
#include "tgmath.h"
using namespace std;

Dragon::Dragon(int row, int col) {
    this->row = row;
    this->col = col;
    this->sign = 'D';
    this->health = 150;
    this->Character::attack = 20;
    this->defence = 20;
    isHostile = false;
}

void Dragon::attack(Player *p, string &action) {
    int onHit = rand() % 2;
    if (onHit == 1) {
        p->beAttack(this, action);
    } else {
        string string = ", D deals 0 to PC";
        action += string;
    }
}

void Dragon::beAttack(Shade* s, string &action) {
    int damage = 0;
    damage = ceil(s->getAttack()*100/(100+this->defence));
    this->health -= damage;
    string d = intToStr(damage);
    string heal = intToStr(this->health);
    string string = "PC deals " + d + " to " + this->getSign() + "(" + heal + ")";
    action += string;
}

void Dragon::beAttack(Drow* d, string &action) {
    int damage = 0;
    damage = ceil(d->getAttack()*100/(100+this->defence));
    this->health -= damage;
    string dd = intToStr(damage);
    string heal = intToStr(this->health);
    string string = "PC deals " + dd + " to " + this->getSign() + "(" + heal + ")";
    action += string;
}

void Dragon::beAttack(Vampire* v, string &action) {
    v->healthLost(-5);
    int damage = 0;
    damage = ceil(v->getAttack()*100/(100+this->defence));
    this->health -= damage;
    string d = intToStr(damage);
    string heal = intToStr(this->health);
    string string = "PC deals " + d + " to " + this->getSign() + "(" + heal + ")";
    action += string;
}
void Dragon::beAttack(Troll *t, string &action) {
    int damage = 0;
    damage = ceil(t->getAttack()*100/(100+this->defence));
    this->health -= damage;
    string d = intToStr(damage);
    string heal = intToStr(this->health);
    string string = "PC deals " + d + " to " + this->getSign() + "(" + heal + ")";
    action += string;
}

void Dragon::beAttack(Goblin *g, string &action) {
    int damage = 0;
    damage = ceil(g->getAttack()*100/(100+this->defence));
    this->health -= damage;
    string d = intToStr(damage);
    string heal = intToStr(this->health);
    string string = "PC deals " + d + " to " + this->getSign() + "(" + heal + ")";
    action += string;
}




