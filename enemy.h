#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"
#include "dragon.h"

class Enemy {
  public:
  void notify(Subject &sub, string action) override;
  void attack(Player *p);
  virtual void beAttack(Shade *s);
  virtual void beAttack(Drow *d);
  virtual void beAttack(Vampire *v);
  virtual void beAttack(Troll *t);
  virtual void beAttack(Goblin *g);
  void notifyObserver();
};

#endif
