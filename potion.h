#ifndef _POTION_H_
#define _POTION_H_
#include <string>

#include <string>
#include "item.h"

class Potion : public Item{
public:
    Potion(std::string s, int row, int col);
};

#endif
