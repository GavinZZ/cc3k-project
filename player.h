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

class Player : public Character, public Subject {
protected:
    int gold;
public:
    virtual void attack(Enemy *enemy);
    virtual void beAttack(Human *h);
    virtual void beAttack(Dwarf *d);
    virtual void beAttack(Elf *e);
    virtual void beAttack(Orcs *o);
    virtual void beAttack(Dragon *d);
    virtual void beAttack(Merchant *m);
    virtual void beAttack(Halfling *h);
    void changeGold(int gold);
    int getGold();
    void notifyObservers();
};

#endif
