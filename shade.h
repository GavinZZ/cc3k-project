#ifndef _SHADE_H_
#define _SHADE_H_

#include "player.h"
#include "enemy.h"
#include "human.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"
#include "dragon.h"

class Shade : public Player{
  public:
  void beAttack(Human *h);
  void beAttack(Dwarf *d);
  void beAttack(Elf *e);
  void beAttack(Orcs *o);
  void beAttack(Merchant *m);
  void beAttack(Dragon *d);
};

#endif
