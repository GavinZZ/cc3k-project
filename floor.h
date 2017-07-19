#ifndef _FLOOR_H_
#define _FLOOR_H_
#include "player.h"
#include "display.h"
#include "item.h"
#include "enemy.h"

class Floor {
  vector<Enemy *> enemies;
  vector<Item *> items;
  Player * player;
  int ith_floor;
  public:
  Floor(Player *p = nullptr,int ith = 1);
  Bool isWon();
  Bool isLost();
  void move_player(string direction);
  void use_potion(string direction);
  void move_enemy();
  void attack(string direction);
  void upstair();
  ~Floor();
};

#endif
