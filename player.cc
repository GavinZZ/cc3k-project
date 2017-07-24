#include "player.h"
#include <iostream>
class Enemy;
class Human;
class Dwarf;
class Elf;
class Orcs;
class Merchant;
class Dragon;
using namespace std;

void Player::changeGold(int gold) {
    this->gold += gold;
}

int Player::getGold() {
    return this->gold;
}

void Player::changeCorrection(){
    this->defence-=correction_def;
    this->Character::attack-=correction_atk;
}

void Player::CA(int val) {
    correction_atk += val;
}

void Player::CD(int val) {
    correction_def += val;
}
