#include "goblin.h"
#include "tgmath.h"
#include "enemy.h"
#include <sstream>
using namespace std;

Goblin::Goblin() {
    gold = 0;
    health = 110;
    Character::attack = 15;
    defence = 20;
    sign = 'G';
    col = 0;
    row = 0;
    correction_atk = 0;
    correction_def = 0;
}

void Goblin::attack(Enemy *enemy, std::string &action) {
    enemy->beAttack(this, action);
    if (enemy->getHealth() <= 0) gold += 5;
}

void Goblin::beAttack(Human *h, std::string &action) {
    int hit = rand() % 2;
    int damage = ceil(20*100/(100+this->defence));
    int total_damage = hit * damage;
    health -= total_damage;
    string td = intToStr(total_damage);
    string string = ", H deals " + td + " to PC";
    action += string;
}

void Goblin::beAttack(Dwarf *d, std::string &action) {
    int hit = rand() % 2;
    int damage = ceil(20*100/(100+this->defence));
    int total_damage = hit * damage;
    health -= total_damage;
    string td = intToStr(total_damage);
    string string = ", W deals " + td + " to PC";
    action += string;
}

void Goblin::beAttack(Elf *e, std::string &action) {
    int hit = rand() % 2;
    int damage = ceil(30*100/(100+this->defence));
    int total_damage = hit * damage;
    health -= total_damage;
    string td = intToStr(total_damage);
    string string = ", E deals " + td + " to PC";
    action += string;
}

void Goblin::beAttack(Orcs *o, std::string &action) {
    int hit = rand() % 2;
    int damage = ceil(30*100/(100+this->defence));
    int total_damage = hit * damage;
    health -= total_damage;
    string td = intToStr(total_damage);
    string string = ", O deals " + td + " to PC";
    action += string;
}

void Goblin::beAttack(Merchant *m, std::string &action) {
    int hit = rand() % 2;
    int damage = ceil(70*100/(100+this->defence));
    int total_damage = hit * damage;
    health -= total_damage;
    string td = intToStr(total_damage);
    string string = ", M deals " + td + " to PC";
    action += string;
}

void Goblin::beAttack(Dragon *d, std::string &action) {
    int hit = rand() % 2;
    int damage = ceil(20*100/(100+this->defence));
    int total_damage = hit * damage;
    health -= total_damage;
    string td = intToStr(total_damage);
    string string = ", D deals " + td + " to PC";
    action += string;
}

void Goblin::beAttack(Halfling *h, std::string &action) {
    int hit = rand() % 2;
    int damage = ceil(15*100/(100+this->defence));
    int total_damage = hit * damage;
    health -= total_damage;
    string td = intToStr(total_damage);
    string string = ", L deals " + td + " to PC";
    action += string;
}
