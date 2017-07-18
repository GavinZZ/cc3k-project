#ifndef _PLAYER_H_
#define _PLAYER_H_


#include "shade.h"
#include "drow.h"
#include "troll.h"
#include "goblin.h"
#include "vampire.h"
class Enemy;

class Player ：public Character{
  protected:
  int gold;
  public:
  void notify(Subject &sub, string action) override;
  virtual void attack(Enemy *enemy);
  virtual void beAttack(Human *h);
  virtual void beAttack(Dwarf *d);
  virtual void beAttack(Elf *e);
  virtual void beAttack(Orcs *o);
  virtual void beAttack(Dragon *d);
  virtual void beAttack(Merchant *m);
  void changeGold(int gold);
  int getGold();
  void notifyObservers();
};

#endif
