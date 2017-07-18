#ifndef _FLOOR_H_
#define _FLOOR_H_

class Floor {
  public:
  Floor();
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
