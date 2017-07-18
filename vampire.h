#ifndef _VAMPIRE_H_
#define _VAMPIRE_H_

class Shade {
  public:
  void beAttack(Human *h);
  void beAttack(Dwarf *d);
  void beAttack(Elf *e);
  void beAttack(Orcs *o);
  void beAttack(Merchant *m);
  void beAttack(Dragon *d);
};

#endif
