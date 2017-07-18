#ifndef _TROLL_H_
#define _TROLL_H_

#include "player.h"
#include "enemy.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"
#include "dragon.h"

class Troll : public Player {
  public:
  void beAttack(Human *h);
  void beAttack(Dwarf *d);
  void beAttack(Elf *e);
  void beAttack(Orcs *o);
  void beAttack(Merchant *m);
  void beAttack(Dragon *d);
};

#endif
