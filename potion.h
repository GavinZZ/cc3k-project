#ifndef _POTION_H_
#define _POTION_H_
#include <string>

#include <string>
#include "item.h"

class Potion : public Item{
    std::string type;
public:
    std::string getType();
};

#endif
