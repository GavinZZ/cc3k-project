#ifndef _FLOOR_H_
#define _FLOOR_H_
#include "player.h"
#include "display.h"
#include "item.h"
#include "enemy.h"

class Floor {
    std::vector<Enemy *> enemies;
    std::vector<Item *> items;
    Player * player;
    int ith_floor;
public:
    Floor(Player *p = nullptr,int ith = 1);
    bool isWon();
    bool isLost();
    void move_player(std::string direction);
    void use_potion(std::string direction);
    void move_enemy();
    void attack(std::string direction);
    void upstair();
    void changeDisplay(Display *d);
    void push_item(Item *item);
    void push_enemy(Enemy *enemy);
    ~Floor();
};

#endif
