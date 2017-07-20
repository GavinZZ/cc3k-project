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

void Player::notify(Subject &sub, string action) {
    
}

void Player::changeGold(int gold) {
    this->gold += gold;
}

int Player::getGold() {
    return this->gold;
}

void Player::notifyObservers() {
    
}

