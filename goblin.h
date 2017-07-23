#ifndef _GOBLIN_H_
#define _GOBLIN_H_

#include "player.h"

class Enemy;
class Human;
class Dwarf;
class Elf;
class Orcs;
class Merchant;
class Dragon;
class Halfling;

class Goblin: public Player{
public:
	void Goblin();
    void attack (Enemy *enemy) override;
    void beAttack(Human *h) override;
    void beAttack(Dwarf *d) override;
    void beAttack(Elf *e) override;
    void beAttack(Orcs *o) override;
    void beAttack(Merchant *m) override;
    void beAttack(Dragon *d) override;
    void beAttack(Halfling *h) override;
};

#endif
