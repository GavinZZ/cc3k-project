#ifndef _HUMAN_H_
#define _HUMAN_H_

#include "shade.h"
#include "drow.h"
#include "vanpire.h"
#include "troll.h"
#include "goblin.h"
#include "enemy.h"

class Human : public Enemy{
  public:
  virtual void beAttack(Shade *s);
  virtual void beAttack(Drow *d);
  virtual void beAttack(Vampire *v);
  virtual void beAttack(Troll *t);
  virtual void beAttack(Goblin *g);
};

#endif
