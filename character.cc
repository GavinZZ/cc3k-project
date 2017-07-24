#include "character.h"
#include <iostream>
#include <sstream>
using namespace std;

int Character::getHealth() {
    return this->health;
}

int Character::getAttack() {
    return attack;
}

int Character::getDefence() {
    return defence;
}

void Character::setHealth() {
    this->health = 120;
}

void Character::change(int health, int attack, int defence) {
    this->health += health;
    this->attack += attack;
    this->defence += defence;
}

bool Character::isDead() {
    return health <= 0;
}

bool Character::getHostile() {
    return isHostile;
}

void Character::setCorrection() {
    correction_atk = 0;
    correction_def = 0;
}

void Character::changePos(int row, int col) {
    this->col = col;
    this->row = row;
}

int Character::getCol() {
    return col;
}

int Character::getRow() {
    return row;
}

char Character::getSign() {
    return sign;
}

void Character::healthLost(int damage) {
    health -= damage;
}

string Character::intToStr(int num) {
    string result;
    stringstream ss;
    ss << num;
    result = ss.str();
    return result;
}

Character::~Character() {
    
}
