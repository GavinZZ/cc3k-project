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
    bool isHostile;
public:
    bool getHostile();
    int getHealth();
    int getAttack();
    int getDefence();
    void change(int health = 0, int attack = 0, int defence = 0);
    void changePos(int row, int col);
    bool isDead();
    int getCol();
    int getRow();
    char getSign();
    void healthLost(int damage);
    ~Character();
};

#endif
