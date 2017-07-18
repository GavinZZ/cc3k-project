#ifndef _DWARF_H_
#define _DWARF_H_

class Dwarf {
  public:
  virtual void beAttack(Shade *s);
  virtual void beAttack(Drow *d);
  virtual void beAttack(Vampire *v);
  virtual void beAttack(Troll *t);
  virtual void beAttack(Goblin *g);
};

#endif
