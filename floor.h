#ifndef _FLOOR_H_
#define _FLOOR_H_
#include "player.h"
#include "display.h"
#include "item.h"
#include "stair.h"
#include "enemy.h"
#include <vector>
#include <memory>


class Floor {
    std::vector<std::shared_ptr<Enemy>> enemy;
    std::vector<std::shared_ptr<Item>> item;
    std::shared_ptr<Stair> stair;
    Player* player;
    std::shared_ptr<Display> display;
    int ith_floor;
    bool onStair;
    char previous;
    void itemSpawn(int row, int col);
    void enemySpawn(int row, int col);
    void goldSpawn(int row, int col);
    bool merchantHostile = false;
public:
    bool getMerchantHostile();
    void setHostile();
    std::shared_ptr<Display>& getDisplay();
    Floor();
    Floor(std::string filename, Player* p, int ith);
    Floor(Player* p, int ith);
    bool isWon();
    bool isLost();
    void move_player(std::string direction, std::string &action);
    void use_potion(std::string direction, std::string &action);
    void move_enemy(std::string &action);
    bool getState();
    void attack(std::string direction, std::string &action);
    ~Floor();
    friend std::ostream &operator<<(std::ostream &out, const Floor &floor);
};

#endif
