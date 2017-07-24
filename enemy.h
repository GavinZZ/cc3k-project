#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
class Player;

class Enemy: public Character {
protected:
    bool isHostile = false;
public:
    void changeHostile();
    virtual void attack(Player *p, std::string &action) = 0;
    virtual void beAttack(Shade *s, std::string &action) = 0;
    virtual void beAttack(Drow *d, std::string &action) = 0;
    virtual void beAttack(Vampire *v, std::string &action) = 0;
    virtual void beAttack(Troll *t, std::string &action) = 0;
    virtual void beAttack(Goblin *g, std::string &action) = 0;
};

#endif
