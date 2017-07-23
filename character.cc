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
    health += health;
    attack += attack;
    defence += defence;
}

bool Character::isDead() {
    return health <= 0;
}

bool Character::getHostile() {
    return isHostile;
}

void Character::changePos(int row, int col) {
    col = col;
    row = row;
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
