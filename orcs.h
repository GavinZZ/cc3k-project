#ifndef _ORCS_H_
#define _ORCS_H_

class Orcs {
  public:
  virtual void beAttack(Shade *s);
  virtual void beAttack(Drow *d);
  virtual void beAttack(Vampire *v);
  virtual void beAttack(Troll *t);
  virtual void beAttack(Goblin *g);
};

#endif
