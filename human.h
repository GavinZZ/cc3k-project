#ifndef _HUMAN_H_
#define _HUMAN_H_

class Human {
  virtual void beAttack(Shade *s);
  virtual void beAttack(Drow *d);
  virtual void beAttack(Vampire *v);
  virtual void beAttack(Troll *t);
  virtual void beAttack(Goblin *g);
};

#endif
