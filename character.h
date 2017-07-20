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
    int correction_atk;
    int correction_def;
public:
    int getHealth();
    int getAttack();
    int getDefence();
    void change(int health = 0, int attack = 0, int defence = 0);
    bool isDead();
    int getCol();
    int getRow();
    char getSign();
    ~Character();
};

#endif
