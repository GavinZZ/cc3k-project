#ifndef _FLOOR_H_
#define _FLOOR_H_
#include "player.h"
#include "display.h"
#include "item.h"
#include "stair.h"
#include "enemy.h"
#include <vector>

class Floor {
    std::vector<std::shared_ptr<Enemy>> enemy;
    std::vector<std::shared_ptr<Item>> item;
    std::shared_ptr<Stair> stair;
    std::shared_ptr<Player> player;
    std::shared_ptr<Display> display;
    int ith_floor;
    bool onStair;
    char previous;
    void itemSpawn(int row, int col);
    void enemySpawn(int row, int col);
    void goldSpawn(int row, int col);
    bool merchantHostile;
public:
    bool getMerchantHostile();
    Floor(std::string filename, Player *p, int ith);
    Floor(Player *p, int ith);
    bool isWon();
    bool isLost();
    void move_player(std::string direction);
    void use_potion(std::string direction);
    void move_enemy();
    bool getState();
    Display * getDisplay();
    void attack(std::string direction);
    ~Floor();
    friend std::ostream &operator<<(std::ostream &out, const Floor &floor);
};

#endif
