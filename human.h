#ifndef _HUMAN_H_
#define _HUMAN_H_

#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "enemy.h"

class Human : public Enemy{
public:
    void attack(Player *player) override;
    void beAttack(Shade *s) override;
    void beAttack(Drow *d) override;
    void beAttack(Vampire *v) override;
    void beAttack(Troll *t) override;
    void beAttack(Goblin *g) override;
};

#endif
