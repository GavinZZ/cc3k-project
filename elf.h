#ifndef _ELF_H_
#define _ELF_H_

#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "enemy.h"

class Elf : public Enemy {
public:
    Elf(int row, int col);
    void attack(Player *player, std::string &action) override;
    void beAttack(Shade *s, std::string &action) override;
    void beAttack(Drow *d, std::string &action) override;
    void beAttack(Vampire *v, std::string &action) override;
    void beAttack(Troll *t, std::string &action) override;
    void beAttack(Goblin *g, std::string &action) override;
};

#endif
