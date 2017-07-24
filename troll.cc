#include "troll.h"
#include "tgmath.h"
#include <sstream>
#include "enemy.h"
using namespace std;

Troll::Troll() {
    gold = 0;
    health = 120;
    Character::attack = 25;
    defence = 15;
    sign = 'T';
    col = 0;
    row = 0;
    correction_atk = 0;
    correction_def = 0;
}

void Troll::attack(Enemy *enemy, std::string &action) {
    enemy->beAttack(this, action);
}

void Troll::beAttack(Human *h, std::string &action) {
    int hit = rand() % 2;
    int damage = ceil(20*100/(100+this->defence));
    int total_damage = hit * damage;
    health -= total_damage;
    string td = intToStr(total_damage);
    string string = ", H deals " + td + " to PC";
    action += string;
}

void Troll::beAttack(Dwarf *d, std::string &action) {
    int hit = rand() % 2;
    int damage = ceil(20*100/(100+this->defence));
    int total_damage = hit * damage;
    health -= total_damage;
    string td = intToStr(total_damage);
    string string = ", W deals " + td + " to PC";
    action += string;
}

void Troll::beAttack(Elf *e, std::string &action) {
    int hit = rand() % 2;
    int damage = ceil(30*100/(100+this->defence));
    int total_damage = hit * damage;
    health -= total_damage;
    string td = intToStr(total_damage);
    string string = ", E deals " + td + " to PC";
    action += string;
}

void Troll::beAttack(Orcs *o, std::string &action) {
    int hit = rand() % 2;
    int damage = ceil(30*100/(100+this->defence));
    int total_damage = hit * damage;
    health -= total_damage;
    string td = intToStr(total_damage);
    string string = ", O deals " + td + " to PC";
    action += string;
}

void Troll::beAttack(Merchant *m, std::string &action) {
    int hit = rand() % 2;
    int damage = ceil(70*100/(100+this->defence));
    int total_damage = hit * damage;
    health -= total_damage;
    string td = intToStr(total_damage);
    string string = ", M deals " + td + " to PC";
    action += string;
}

void Troll::beAttack(Dragon *d, std::string &action) {
    int hit = rand() % 2;
    int damage = ceil(20*100/(100+this->defence));
    int total_damage = hit * damage;
    health -= total_damage;
    string td = intToStr(total_damage);
    string string = ", D deals " + td + " to PC";
    action += string;
}

void Troll::beAttack(Halfling *h, std::string &action) {
    int hit = rand() % 2;
    int damage = ceil(15*100/(100+this->defence));
    int total_damage = hit * damage;
    health -= total_damage;
    string td = intToStr(total_damage);
    string string = ", L deals " + td + " to PC";
    action += string;
}
