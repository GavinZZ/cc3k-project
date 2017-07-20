#ifndef _ITEM_H_
#define _ITEM_H_

class Item {
protected:
    int row;
    int col;
    int sign;
public:
    int getCol();
    int getRow();
    int getSign();
    ~Item();
};

#endif
