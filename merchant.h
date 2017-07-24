#ifndef _MERCHANT_H_
#define _MERCHANT_H_

#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "enemy.h"

class Merchant : public Enemy{
public:
    Merchant(int row, int col, bool Hostility);
    virtual void attack(Player *p, std::string &action);
    virtual void beAttack(Shade *s, std::string &action);
    virtual void beAttack(Drow *d, std::string &action);
    virtual void beAttack(Vampire *v, std::string &action);
    virtual void beAttack(Troll *t, std::string &action);
    virtual void beAttack(Goblin *g, std::string &action);
};

#endif
