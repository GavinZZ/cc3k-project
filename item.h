#ifndef _ITEM_H_
#define _ITEM_H_
#include <string>

class Item  {
protected:
    int row;
    int col;
    std::string sign;
    bool isDead;
    int val;
public:
    int getCol();
    int getRow();
    int getVal();
    bool getIsDead();
    void setDead();
    std::string getSign();
    ~Item();
};

#endif
