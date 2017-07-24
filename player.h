#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "subject.h"
#include "character.h"
class Enemy;
class Human;
class Dwarf;
class Elf;
class Orcs;
class Merchant;
class Dragon;
class Halfling;

class Player : public Character{
protected:
    int gold;
public:
    virtual void attack(Enemy *enemy, std::string &action) = 0;
    virtual void beAttack(Human *h, std::string &action) = 0;
    virtual void beAttack(Dwarf *d, std::string &action) = 0;
    virtual void beAttack(Elf *e, std::string &action) = 0;
    virtual void beAttack(Orcs *o, std::string &action) = 0;
    virtual void beAttack(Dragon *d, std::string &action) = 0;
    virtual void beAttack(Merchant *m, std::string &action) = 0;
    virtual void beAttack(Halfling *h, std::string &action) = 0;
    void changeGold(int gold);
    void changeCorrection();
    int getGold();
};

#endif
