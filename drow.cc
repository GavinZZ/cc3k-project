#include "drow.h"
#include "tgmath.h"
#include <sstream>
#include "enemy.h"
using namespace std;

Drow::Drow() {
    gold = 0;
    health = 150;
    Character::attack = 25;
    defence = 15;
    sign = 'D';
    col = 0;
    row = 0;
    correction_atk = 0;
    correction_def = 0;
}

void Drow::attack(Enemy *enemy, std::string &action) {
    enemy->beAttack(this, action);
}

void Drow::beAttack(Human *h, std::string &action) {
    int hit = rand() % 2;
    int damage = ceil(20*100/(100+this->defence));
    int total_damage = hit * damage;
    health -= total_damage;
    string td = intToStr(total_damage);
    string string = ", H deals " + td + " to PC";
    action += string;
}

void Drow::beAttack(Dwarf *d, std::string &action) {
    int hit = rand() % 2;
    int damage = ceil(20*100/(100+this->defence));
    int total_damage = hit * damage;
    health -= total_damage;
    string td = intToStr(total_damage);
    string string = ", W deals " + td + " to PC";
    action += string;
}

void Drow::beAttack(Elf *e, std::string &action) {
    int hit = rand() % 2;
    int damage = ceil(30*100/(100+this->defence));
    int total_damage = hit * damage;
    health -= total_damage;
    string td = intToStr(total_damage);
    string string = ", E deals " + td + " to PC";
    action += string;
}

void Drow::beAttack(Orcs *o, std::string &action) {
    int hit = rand() % 2;
    int damage = ceil(30*100/(100+this->defence));
    int total_damage = hit * damage;
    health -= total_damage;
    string td = intToStr(total_damage);
    string string = ", O deals " + td + " to PC";
    action += string;
}

void Drow::beAttack(Merchant *m, std::string &action) {
    int hit = rand() % 2;
    int damage = ceil(70*100/(100+this->defence));
    int total_damage = hit * damage;
    health -= total_damage;
    string td = intToStr(total_damage);
    string string = ", M deals " + td + " to PC";
    action += string;
}

void Drow::beAttack(Dragon *d, std::string &action) {
    int hit = rand() % 2;
    int damage = ceil(15*100/(100+this->defence));
    int total_damage = hit * damage;
    health -= total_damage;
    string td = intToStr(total_damage);
    string string = ", D deals " + td + " to PC";
    action += string;
}

void Drow::beAttack(Halfling *h, std::string &action) {
    int hit = rand() % 2;
    int damage = ceil(15*100/(100+this->defence));
    int total_damage = hit * damage;
    health -= total_damage;
    string td = intToStr(total_damage);
    string string = ", L deals " + td + " to PC";
    action += string;
}
