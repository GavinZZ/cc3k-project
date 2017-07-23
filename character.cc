#include "character.h"
#include <iostream>
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

void Character::change(int health, int attack, int defence) {
    this->health += health;
    this->attack += attack;
    this->defence += defence;
    this->correction_atk -= attack;
    this->correction_def -= defence;
}

bool Character::isDead() {
    return health <= 0;
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

Character::~Character() {
    
}
