#ifndef _TROLL_H_
#define _TROLL_H_

#include "player.h"

class Enemy;
class Human;
class Dwarf;
class Elf;
class Orcs;
class Merchant;
class Dragon;
class Halfling;

class Troll : public Player {
public:
    Troll();
    void attack (Enemy *enemy, std::string &action) override;
    void beAttack(Human *h, std::string &action) override;
    void beAttack(Dwarf *d, std::string &action) override;
    void beAttack(Elf *e, std::string &action) override;
    void beAttack(Orcs *o, std::string &action) override;
    void beAttack(Merchant *m, std::string &action) override;
    void beAttack(Dragon *d, std::string &action) override;
    void beAttack(Halfling *h, std::string &action) override;
};

#endif
