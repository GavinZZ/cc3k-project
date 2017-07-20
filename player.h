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

class Player : public Character, public Subject {
protected:
    int gold;
    int correction_atk;
    int correction_def;
public:
    void notify(Subject &sub, std::string action);
    virtual void attack(Enemy *enemy);
    virtual void beAttack(Human *h);
    virtual void beAttack(Dwarf *d);
    virtual void beAttack(Elf *e);
    virtual void beAttack(Orcs *o);
    virtual void beAttack(Dragon *d);
    virtual void beAttack(Merchant *m);
    void changeGold(int gold);
    int getGold();
    void notifyObservers();
};

#endif
