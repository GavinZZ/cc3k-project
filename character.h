#ifndef _CHARACTER_H_
#define _CHARACTER_H_

class Character {
  protected:
  int health;
  int attack;
  int defence;
  char sign;
  int col;
  int row;
  public:
  int getHealth();
  int getAttack();
  int getDefence();
  void change(int health = 0, int attack = 0, int defence = 0);
  Bool isDead();
  int getCol();
  int getRow();
  char getSign();
  ~Character();
}

#endif
