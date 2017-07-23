#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "subject.h"
#include "character.h"
#include <string>
class Enemy;
class Human;
class Dwarf;
class Elf;
class Orcs;
class Merchant;
class Dragon;
class Halfling;

class Player : public Character, public Subject {
protected:
    int gold;
public:
    virtual void attack(Enemy *enemy, std::string &action);
    virtual void beAttack(Human *h, std::string &action);
    virtual void beAttack(Dwarf *d, std::string &action);
    virtual void beAttack(Elf *e, std::string &action);
    virtual void beAttack(Orcs *o, std::string &action);
    virtual void beAttack(Dragon *d, std::string &action);
    virtual void beAttack(Merchant *m, std::string &action);
    virtual void beAttack(Halfling *h, std::string &action);
    void changeGold(int gold);
    int getGold();
    void notifyObservers();
};

#endif
