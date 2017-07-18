#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "shade.h"
#include "drow.h"
#include "vanpire.h"
#include "troll.h"
#include "goblin.h"
#include "observer.h"
class Player;

class Enemy : public Observer, public Subject, public Character {
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
