#include "floor.h"
#include <fstream>
#include "potion.h"
#include "treasure.h"
#include <vector>
#include "human.h"
#include <iostream>
#include <memory>
#include "dwarf.h"
#include "elf.h"
#include "orcs.h"
#include "halfling.h"
#include "merchant.h"
#include "dragontreasure.h"
#include "dragon.h"
using namespace std;

Floor::Floor() {
    
}

void Floor:: setHostile() {
    merchantHostile = true;
    for (int i = 0; i < enemy.size(); i ++) {
        if (enemy[i]->getSign() == 'M') {
            enemy[i]->changeHostile();
        }
    }
}

Floor::Floor(string filename, Player* p, int ith) {
    ifstream iff{filename};
    string line;
    previous = '.';
    ith_floor = ith;
    onStair = false;
    merchantHostile = false;
    int count = (ith-1)*25;
    for(int j = 0; j < count; ++j) {
        getline(iff,line);
    }
    shared_ptr<Display> d{new Display{filename}};
    display = d;
    while (count < ith*25) {
        getline(iff, line);
        for (int j = 0; j < 79; j ++) {
            if(line[j] == '0'){
                shared_ptr<Item> pot{new Potion{"RH", count % 25, j}};
                display->changeChar(count % 25, j, 'P');
                item.emplace_back(pot);
            } else if(line[j] == '1'){
                shared_ptr<Item> pot{new Potion{"BA", count % 25, j}};
                display->changeChar(count % 25, j, 'P');
                item.emplace_back(pot);
            } else if(line[j] == '2'){
                shared_ptr<Item> pot{new Potion{"BD", count % 25, j}};
                display->changeChar(count % 25, j, 'P');
                item.emplace_back(pot);
            } else if(line[j] == '3'){
                shared_ptr<Item> pot{new Potion{"PH", count % 25, j}};
                display->changeChar(count % 25, j, 'P');
                item.emplace_back(pot);
            } else if(line[j] == '4'){
                shared_ptr<Item> pot{new Potion{"WA", count % 25, j}};
                display->changeChar(count % 25, j, 'P');
                item.emplace_back(pot);
            } else if(line[j] == '5'){
                shared_ptr<Item> pot{new Potion{"WD", count % 25, j}};
                display->changeChar(count % 25, j, 'P');
                item.emplace_back(pot);
            } else if(line[j] == '6'){
                shared_ptr<Item> treasure{new Treasure{"normal", count % 25, j}};
                display->changeChar(count % 25, j, 'G');
                item.emplace_back(treasure);
            } else if(line[j] == '7'){
                shared_ptr<Item> treasure{new Treasure{"small", count % 25, j}};
                display->changeChar(count % 25, j, 'G');
                item.emplace_back(treasure);
            } else if(line[j] == '8'){
                shared_ptr<Item> treasure{new Treasure{"merchantH", count % 25, j}};
                display->changeChar(count % 25, j, 'G');
                item.emplace_back(treasure);
            } else if(line[j] == '9'){
                shared_ptr<Item> treasure{new DragonTreasure{nullptr, count % 25, j}};
                display->changeChar(count % 25, j, 'G');
                item.emplace_back(treasure);
            } else if(line[j] == '@'){
                player = p;
                player->changePos(count % 25, j);
            } else if(line[j] == 'H') {
                shared_ptr<Enemy> e{new Human{count % 25, j}};
                display->changeChar(count % 25, j,line[j]);
                enemy.emplace_back(e);
            } else if(line[j] == 'W') {
                shared_ptr<Enemy> e{new Dwarf{count % 25, j}};
                display->changeChar(count % 25, j,line[j]);
                enemy.emplace_back(e);
            } else if(line[j] == 'E') {
                shared_ptr<Enemy> e{new Elf{count % 25, j}};
                display->changeChar(count % 25, j,line[j]);
                enemy.emplace_back(e);
            } else if(line[j] == 'O') {
                shared_ptr<Enemy> e{new Orcs{count % 25, j}};
                display->changeChar(count % 25, j,line[j]);
                enemy.emplace_back(e);
            } else if(line[j] == 'M') {
                shared_ptr<Enemy> e{new Merchant{count % 25, j, merchantHostile}};
                display->changeChar(count % 25, j,line[j]);
                enemy.emplace_back(e);
            } else if(line[j] == 'D') {
                shared_ptr<Enemy> e{new Dragon{count % 25, j}};
                display->changeChar(count % 25, j,line[j]);
                enemy.emplace_back(e);
            } else if(line[j] == 'L') {
                shared_ptr<Enemy> e{new Halfling{count % 25, j}};
                display->changeChar(count % 25, j,line[j]);
                enemy.emplace_back(e);
            } else if (line[j] == 92) {
                shared_ptr<Stair> s{new Stair{count % 25, j}};
                display->changeChar(count % 25, j,line[j]);
                stair = s;
            }
        }
        count ++;
    }
}

Floor::Floor(Player *p, int ith) {
    ith_floor = ith;
    onStair = false;
    merchantHostile = false;
    Display();
    int enemy_count = 0;
    int item_count = 0;
    int gold_count = 0;
    while (enemy_count < 20) {
        int chamber = rand() % 5;
        if (chamber == 0) {
            while (1) {
                bool result = false;
                int row = rand() % 4 + 3;
                int col = rand() % 26 + 3;
                for (int i = 0; i < enemy.size(); i ++) {
                    if (enemy[i]->getCol() == col && enemy[i]->getRow() == row) {
                        result = true;
                    }
                }
                for (int i = 0; i < item.size(); i ++) {
                    if (item[i]->getCol() == col && item[i]->getRow() == row) {
                        result = true;
                    }
                }
                if (!result) {
                    enemySpawn(row, col);
                    break;
                }
            }
        } else if (chamber == 1) {
            while (1) {
                bool result = false;
                int row = rand() % 7 + 15;
                int col = rand() % 21 + 4;
                for (int i = 0; i < enemy.size(); i ++) {
                    if (enemy[i]->getCol() == col && enemy[i]->getRow() == row) {
                        result = true;
                    }
                }
                for (int i = 0; i < item.size(); i ++) {
                    if (item[i]->getCol() == col && item[i]->getRow() == row) {
                        result = true;
                    }
                }
                if (!result) {
                    enemySpawn(row, col);
                    break;
                }
            }
        } else if (chamber == 2) {
            while (1) {
                bool result = false;
                int row = rand() % 3 + 10;
                int col = rand() % 12 + 37;
                for (int i = 0; i < enemy.size(); i ++) {
                    if (enemy[i]->getCol() == col && enemy[i]->getRow() == row) {
                        result = true;
                    }
                }
                for (int i = 0; i < item.size(); i ++) {
                    if (item[i]->getCol() == col && item[i]->getRow() == row) {
                        result = true;
                    }
                }
                if (!result) {
                    enemySpawn(row, col);
                    break;
                }
            }
        } else if (chamber == 3) {
            while (1) {
                bool result = false;
                int col = 0;
                int row = rand() % 6 + 16;
                if (row <= 18) {
                    col = rand() % 11 + 65;
                } else {
                    col = rand() % 39 + 36;
                }
                for (int i = 0; i < enemy.size(); i ++) {
                    if (enemy[i]->getCol() == col && enemy[i]->getRow() == row) {
                        result = true;
                    }
                }
                for (int i = 0; i < item.size(); i ++) {
                    if (item[i]->getCol() == col && item[i]->getRow() == row) {
                        result = true;
                    }
                }
                if (!result) {
                    enemySpawn(row, col);
                    break;
                }
            }
        } else if (chamber == 4) {
            bool result = false;
            int col = 0;
            int row = rand() % 10 + 3;
            if (row <= 4) {
                col = rand() % 23 + 38;
            } else if (row == 5) {
                col = rand() %  31 + 38;
            } else if (row == 6) {
                col = rand() % 34 + 38;
            } else {
                col = rand() % 15 + 61;
            }
            for (int i = 0; i < enemy.size(); i ++) {
                if (enemy[i]->getCol() == col && enemy[i]->getRow() == row) {
                    result = true;
                }
            }
            for (int i = 0; i < item.size(); i ++) {
                if (item[i]->getCol() == col && item[i]->getRow() == row) {
                    result = true;
                }
            }
            if (!result) {
                enemySpawn(row, col);
                break;
            }
        }
        enemy_count ++;
    }
    while (item_count < 10) {
        int chamber = rand() % 5;
        if (chamber == 0) {
            while (1) {
                bool result = false;
                int row = rand() % 4 + 3;
                int col = rand() % 26 + 3;
                for (int i = 0; i < item.size(); i ++) {
                    if (item[i]->getCol() == col && item[i]->getRow() == row) {
                        result = true;
                    }
                }
                for (int i = 0; i < enemy.size(); i ++) {
                    if (enemy[i]->getCol() == col && enemy[i]->getRow() == row) {
                        result = true;
                    }
                }
                if (!result) {
                    itemSpawn(row, col);
                    break;
                }
            }
        } else if (chamber == 1) {
            while (1) {
                bool result = false;
                int row = rand() % 7 + 15;
                int col = rand() % 21 + 4;
                for (int i = 0; i < item.size(); i ++) {
                    if (item[i]->getCol() == col && item[i]->getRow() == row) {
                        result = true;
                    }
                }
                for (int i = 0; i < enemy.size(); i ++) {
                    if (enemy[i]->getCol() == col && enemy[i]->getRow() == row) {
                        result = true;
                    }
                }
                if (!result) {
                    itemSpawn(row, col);
                    break;
                }
            }
        } else if (chamber == 2) {
            while (1) {
                bool result = false;
                int row = rand() % 3 + 10;
                int col = rand() % 12 + 37;
                for (int i = 0; i < item.size(); i ++) {
                    if (item[i]->getCol() == col && item[i]->getRow() == row) {
                        result = true;
                    }
                }
                for (int i = 0; i < enemy.size(); i ++) {
                    if (enemy[i]->getCol() == col && enemy[i]->getRow() == row) {
                        result = true;
                    }
                }
                if (!result) {
                    itemSpawn(row, col);
                    break;
                }
            }
        } else if (chamber == 3) {
            while (1) {
                bool result = false;
                int col = 0;
                int row = rand() % 6 + 16;
                if (row <= 18) {
                    col = rand() % 11 + 65;
                } else {
                    col = rand() % 39 + 36;
                }
                for (int i = 0; i < item.size(); i ++) {
                    if (item[i]->getCol() == col && item[i]->getRow() == row) {
                        result = true;
                    }
                }
                for (int i = 0; i < enemy.size(); i ++) {
                    if (enemy[i]->getCol() == col && enemy[i]->getRow() == row) {
                        result = true;
                    }
                }
                if (!result) {
                    itemSpawn(row, col);
                    break;
                }
            }
        } else if (chamber == 4) {
            bool result = false;
            int col = 0;
            int row = rand() % 10 + 3;
            if (row <= 4) {
                col = rand() % 23 + 38;
            } else if (row == 5) {
                col = rand() %  31 + 38;
            } else if (row == 6) {
                col = rand() % 34 + 38;
            } else {
                col = rand() % 15 + 61;
            }
            for (int i = 0; i < item.size(); i ++) {
                if (item[i]->getCol() == col && item[i]->getRow() == row) {
                    result = true;
                }
            }
            for (int i = 0; i < enemy.size(); i ++) {
                if (enemy[i]->getCol() == col && enemy[i]->getRow() == row) {
                    result = true;
                }
            }
            if (!result) {
                itemSpawn(row, col);
                break;
            }
        }
        item_count ++;
    }
    while (gold_count < 10) {
        int chamber = rand() % 5;
        if (chamber == 0) {
            while (1) {
                bool result = false;
                int row = rand() % 4 + 3;
                int col = rand() % 26 + 3;
                for (int i = 0; i < item.size(); i ++) {
                    if (item[i]->getCol() == col && item[i]->getRow() == row) {
                        result = true;
                    }
                }
                for (int i = 0; i < enemy.size(); i ++) {
                    if (enemy[i]->getCol() == col && enemy[i]->getRow() == row) {
                        result = true;
                    }
                }
                if (!result) {
                    goldSpawn(row, col);
                    break;
                }
            }
        } else if (chamber == 1) {
            while (1) {
                bool result = false;
                int row = rand() % 7 + 15;
                int col = rand() % 21 + 4;
                for (int i = 0; i < item.size(); i ++) {
                    if (item[i]->getCol() == col && item[i]->getRow() == row) {
                        result = true;
                    }
                }
                for (int i = 0; i < enemy.size(); i ++) {
                    if (enemy[i]->getCol() == col && enemy[i]->getRow() == row) {
                        result = true;
                    }
                }
                if (!result) {
                    goldSpawn(row, col);
                    break;
                }
            }
        } else if (chamber == 2) {
            while (1) {
                bool result = false;
                int row = rand() % 3 + 10;
                int col = rand() % 12 + 37;
                for (int i = 0; i < item.size(); i ++) {
                    if (item[i]->getCol() == col && item[i]->getRow() == row) {
                        result = true;
                    }
                }
                for (int i = 0; i < enemy.size(); i ++) {
                    if (enemy[i]->getCol() == col && enemy[i]->getRow() == row) {
                        result = true;
                    }
                }
                if (!result) {
                    goldSpawn(row, col);
                    break;
                }
            }
        } else if (chamber == 3) {
            while (1) {
                bool result = false;
                int col = 0;
                int row = rand() % 6 + 16;
                if (row <= 18) {
                    col = rand() % 11 + 65;
                } else {
                    col = rand() % 39 + 36;
                }
                for (int i = 0; i < item.size(); i ++) {
                    if (item[i]->getCol() == col && item[i]->getRow() == row) {
                        result = true;
                    }
                }
                for (int i = 0; i < enemy.size(); i ++) {
                    if (enemy[i]->getCol() == col && enemy[i]->getRow() == row) {
                        result = true;
                    }
                }
                if (!result) {
                    goldSpawn(row, col);
                    break;
                }
            }
        } else if (chamber == 4) {
            bool result = false;
            int col = 0;
            int row = rand() % 10 + 3;
            if (row <= 4) {
                col = rand() % 23 + 38;
            } else if (row == 5) {
                col = rand() %  31 + 38;
            } else if (row == 6) {
                col = rand() % 34 + 38;
            } else {
                col = rand() % 15 + 61;
            }
            for (int i = 0; i < item.size(); i ++) {
                if (item[i]->getCol() == col && item[i]->getRow() == row) {
                    result = true;
                }
            }
            for (int i = 0; i < enemy.size(); i ++) {
                if (enemy[i]->getCol() == col && enemy[i]->getRow() == row) {
                    result = true;
                }
            }
            if (!result) {
                goldSpawn(row, col);
                break;
            }
        }
        gold_count ++;
    }
    int player_room = rand() % 5;
    int stair_room = rand() % 5;
    while (stair_room == player_room) {
        stair_room = rand() % 5;
    }
    if (player_room == 0 || stair_room == 0) {
        while (1) {
            bool result = false;
            int row = rand() % 4 + 3;
            int col = rand() % 26 + 3;
            for (int i = 0; i < enemy.size(); i ++) {
                if (enemy[i]->getCol() == col && enemy[i]->getRow() == row) {
                    result = true;
                }
            }
            for (int i = 0; i < item.size(); i ++) {
                if (item[i]->getCol() == col && item[i]->getRow() == row) {
                    result = true;
                }
            }
            if (!result) {
                if (player_room == 0) {
                    player->changePos(row, col);
                } else {
                    shared_ptr<Stair> s{new Stair(row, col)};
                    stair = s;
                }
                break;
            }
        }
    } else if (stair_room == 1 || player_room == 1) {
        while (1) {
            bool result = false;
            int row = rand() % 7 + 15;
            int col = rand() % 21 + 4;
            for (int i = 0; i < enemy.size(); i ++) {
                if (enemy[i]->getCol() == col && enemy[i]->getRow() == row) {
                    result = true;
                }
            }
            for (int i = 0; i < item.size(); i ++) {
                if (item[i]->getCol() == col && item[i]->getRow() == row) {
                    result = true;
                }
            }
            if (!result) {
                if (player_room == 0) {
                    player->changePos(row, col);
                } else {
                    shared_ptr<Stair> s{new Stair(row, col)};
                    stair = s;
                }
                break;
            }
        }
    } else if (stair_room == 2 || player_room == 2) {
        while (1) {
            bool result = false;
            int row = rand() % 3 + 10;
            int col = rand() % 12 + 37;
            for (int i = 0; i < enemy.size(); i ++) {
                if (enemy[i]->getCol() == col && enemy[i]->getRow() == row) {
                    result = true;
                }
            }
            for (int i = 0; i < item.size(); i ++) {
                if (item[i]->getCol() == col && item[i]->getRow() == row) {
                    result = true;
                }
            }
            if (!result) {
                if (player_room == 0) {
                    player->changePos(row, col);
                } else {
                    shared_ptr<Stair> s{new Stair(row, col)};
                    stair = s;
                }
                break;
            }
        }
        
    } else if (stair_room == 3 || player_room == 3) {
        while (1) {
            bool result = false;
            int col = 0;
            int row = rand() % 6 + 16;
            if (row <= 18) {
                col = rand() % 11 + 65;
            } else {
                col = rand() % 39 + 36;
            }
            for (int i = 0; i < enemy.size(); i ++) {
                if (enemy[i]->getCol() == col && enemy[i]->getRow() == row) {
                    result = true;
                }
            }
            for (int i = 0; i < item.size(); i ++) {
                if (item[i]->getCol() == col && item[i]->getRow() == row) {
                    result = true;
                }
            }
            if (!result) {
                if (player_room == 0) {
                    player->changePos(row, col);
                } else {
                    shared_ptr<Stair> s{new Stair(row, col)};
                    stair = s;
                }
                break;
            }
        }
    } else if (stair_room == 4 || player_room == 4) {
        while (1) {
            bool result = false;
            int col = 0;
            int row = rand() % 10 + 3;
            if (row <= 4) {
                col = rand() % 23 + 38;
            } else if (row == 5) {
                col = rand() %  31 + 38;
            } else if (row == 6) {
                col = rand() % 34 + 38;
            } else {
                col = rand() % 15 + 61;
            }
            for (int i = 0; i < enemy.size(); i ++) {
                if (enemy[i]->getCol() == col && enemy[i]->getRow() == row) {
                    result = true;
                }
            }
            for (int i = 0; i < item.size(); i ++) {
                if (item[i]->getCol() == col && item[i]->getRow() == row) {
                    result = true;
                }
            }
            if (!result) {
                if (player_room == 0) {
                    player->changePos(row, col);
                } else {
                    shared_ptr<Stair> s{new Stair(row, col)};
                    stair = s;
                }
                break;
            }
        }
    }
    cout << 3 << endl;
}

void Floor::itemSpawn(int row, int col) {
    int chance = rand() % 6;
    if (chance == 0) {
        shared_ptr<Item> pot{new Potion{"RH", row, col}};
        item.emplace_back(pot);
    } else if (chance == 1) {
        shared_ptr<Item> pot{new Potion{"BA", row, col}};
        item.emplace_back(pot);
    } else if (chance == 2) {
        shared_ptr<Item> pot{new Potion{"BD", row, col}};
        item.emplace_back(pot);
    } else if (chance == 3) {
        shared_ptr<Item> pot{new Potion{"PH", row, col}};
        item.emplace_back(pot);
    } else if (chance == 4) {
        shared_ptr<Item> pot{new Potion{"WA", row, col}};
        item.emplace_back(pot);
    } else if (chance == 5) {
        shared_ptr<Item> pot{new Potion{"WD", row, col}};
        item.emplace_back(pot);
    }
    display->changeChar(row, col, 'P');
}

void Floor::goldSpawn(int row, int col) {
    int chance = rand() % 8;
    if (chance <= 4) {
        shared_ptr<Item> gold{new Treasure{"normal", row, col}};
        item.emplace_back(gold);
    } else if (chance <= 6) {
        shared_ptr<Item> gold{new Treasure{"small", row, col}};
        item.emplace_back(gold);
    } else {
        while (1) {
            bool result = false;
            int x = rand() % 3 + -1;
            int y = rand() % 3 + -1;
            for (int i = 0; i < item.size(); i ++) {
                if (item[i]->getCol() == x && item[i]->getRow() == y) {
                    result = true;
                }
            }
            for (int i = 0; i < enemy.size(); i ++) {
                if (enemy[i]->getCol() == x && enemy[i]->getRow() == y) {
                    result = true;
                }
            }
            if (!result) {
                shared_ptr<Dragon> dragon{new Dragon{row+x, col+y}};
                shared_ptr<Item> gold{new DragonTreasure{dragon, row, col}};
                display->changeChar(row+x, col+y, 'G');
                item.emplace_back(gold);
                break;
            }
        }
    }
    display->changeChar(row, col, 'G');
    
}

void Floor::enemySpawn(int row, int col) {
    int chance = rand() % 18;
    if (chance <= 3) {
        shared_ptr<Enemy> e{new Human{row, col}};
        enemy.emplace_back(e);
        display->changeChar(row, col, 'H');
    } else if (chance <= 6) {
        shared_ptr<Enemy> e{new Dwarf{row, col}};
        enemy.emplace_back(e);
        display->changeChar(row, col, 'W');
    } else if (chance <= 11) {
        shared_ptr<Enemy> e{new Halfling{row, col}};
        enemy.emplace_back(e);
        display->changeChar(row, col, 'L');
    } else if (chance <= 13) {
        shared_ptr<Enemy> e{new Elf{row, col}};
        enemy.emplace_back(e);
        display->changeChar(row, col, 'E');
    } else if (chance <= 15) {
        shared_ptr<Enemy> e{new Orcs{row, col}};
        enemy.emplace_back(e);
        display->changeChar(row, col, 'O');
    } else if (chance <= 17) {
        shared_ptr<Enemy> e{new Merchant{row, col, merchantHostile}};
        enemy.emplace_back(e);
        display->changeChar(row, col, 'M');
    }
}

bool Floor::isWon() {
    return ith_floor == 6;
}

bool Floor::isLost() {
    return player->getHealth() <= 0;
}

shared_ptr<Display>& Floor::getDisplay() {
    return display;
}

void Floor:: move_player(string direction, string &action) {
    // eight directions: no,so,ea,we,ne,nw,se,sw
    int playerx = player->getCol();
    int playery = player->getRow();
    if (direction == "no") {
        char next = display->getChar(playery-1, playerx);
        if (next == '.' || next == '+' || next == '#') {
            display->changeChar(playery, playerx, previous);
            previous = next;
            display->changeChar(playery-1,playerx,'@');
            player->changePos(playery-1,playerx);
        } else if (next == 'G') {
            for (int i = 0; i < item.size(); i ++) {
                if ((item[i]->getRow() == playery-1) && (item[i]->getCol() == playerx)) {
                        if (item[i]->getSign() == "dragon" && item[i]->getIsDead()) {
                            player->changeGold(6);
                            display->changeChar(playery-1, playerx, '@');
                            display->changeChar(playery, playerx, previous);
                            item.erase(item.begin()+i);
                        } else {
                            player->changeGold(item[i]->getVal());
                            display->changeChar(playery-1, playerx, '@');
                            player->changePos(playery-1, playerx);
                            display->changeChar(playery, playerx, '.');
                            item.erase(item.begin()+i);
                            action += ", and picks up 4 gold";
                        }
                }
            }
        } else if (next == 92) {
            onStair = true;
        } else {
            action = "Invalid movement";
        }
    }
    if (direction == "so") {
        char next = display->getChar(playery+1, playerx);
        if (next == '.' || next == '+' || next == '#') {
            display->changeChar(playery, playerx, previous);
            previous = next;
            display->changeChar(playery+1,playerx,'@');
            player->changePos(playery+1,playerx);
        } else if (next == 'G') {
            for (int i = 0; i < item.size(); i ++) {
                if ((item[i]->getRow() == playery+1) && (item[i]->getCol() == playerx)) {
                    if (item[i]->getSign() == "dragon" && item[i]->getIsDead()) {
                        player->changeGold(6);
                        display->changeChar(playery+1, playerx, '@');
                        display->changeChar(playery, playerx, previous);
                        item.erase(item.begin()+i);
                    } else {
                        player->changeGold(item[i]->getVal());
                        display->changeChar(playery+1, playerx, '@');
                        player->changePos(playery+1, playerx);
                        display->changeChar(playery, playerx, '.');
                        item.erase(item.begin()+i);
                        action += ", and picks up 4 gold";
                    }
                }
            }
        } else if (next == 92) {
            onStair = true;
        } else {
            action = "Invalid movement";
        }
    }
    if (direction == "we") {
        char next = display->getChar(playery, playerx-1);
        if (next == '.' || next == '+' || next == '#') {
            display->changeChar(playery, playerx, previous);
            previous = next;
            display->changeChar(playery,playerx-1,'@');
            player->changePos(playery,playerx-1);
        } else if (next == 'G') {
            for (int i = 0; i < item.size(); i ++) {
                if ((item[i]->getRow() == playery) && (item[i]->getCol() == playerx-1)) {
                            if (item[i]->getSign() == "dragon" && item[i]->getIsDead()) {
                            player->changeGold(6);
                            display->changeChar(playery, playerx-1, '@');
                            display->changeChar(playery, playerx, previous);
                            item.erase(item.begin()+i);
                        } else {
                            player->changeGold(item[i]->getVal());
                            display->changeChar(playery, playerx-1, '@');
                            player->changePos(playery, playerx-1);
                            display->changeChar(playery, playerx, '.');
                            item.erase(item.begin()+i);
                            action += ", and picks up 4 gold";
                        }
                
                }
            }
        } else if (next == 92) {
            onStair = true;
        } else {
            action = "Invalid movement";
        }
    }
    if (direction == "ea") {
        char next = display->getChar(playery, playerx + 1);
        if (next == '.' || next == '+' || next == '#') {
            display->changeChar(playery, playerx, previous);
            previous = next;
            display->changeChar(playery,playerx+1,'@');
            player->changePos(playery,playerx+1);
        } else if (next == 'G') {
            for (int i = 0; i < item.size(); i ++) {
                if ((item[i]->getRow() == playery) && (item[i]->getCol() == playerx+1)) {
                        if (item[i]->getSign() == "dragon" && item[i]->getIsDead()) {
                            player->changeGold(6);
                            display->changeChar(playery, playerx+1, '@');
                            display->changeChar(playery, playerx, previous);
                            item.erase(item.begin()+i);
                        } else {
                            player->changeGold(item[i]->getVal());
                            display->changeChar(playery, playerx+1, '@');
                            player->changePos(playery, playerx+1);
                            display->changeChar(playery, playerx, '.');
                            item.erase(item.begin()+i);
                            action += ", and picks up 4 gold";
                        }
                
                }
            }
        } else if (next == 92) {
            onStair = true;
        } else {
            action = "Invalid movement";
        }
    }
    if (direction == "nw") {
        char next = display->getChar(playery-1, playerx-1);
        if (next == '.' || next == '+' || next == '#') {
            display->changeChar(playery, playerx, previous);
            previous = next;
            display->changeChar(playery-1,playerx-1,'@');
            player->changePos(playery-1,playerx-1);
        } else if (next == 'G') {
            for (int i = 0; i < item.size(); i ++) {
                if ((item[i]->getRow() == playery-1) && (item[i]->getCol() == playerx-1)) {
                        if (item[i]->getSign() == "dragon" && item[i]->getIsDead()) {
                            player->changeGold(6);
                            display->changeChar(playery-1, playerx-1, '@');
                            display->changeChar(playery, playerx, previous);
                            item.erase(item.begin()+i);
                        } else {
                            player->changeGold(item[i]->getVal());
                            display->changeChar(playery-1, playerx-1, '@');
                            player->changePos(playery-1, playerx-1);
                            display->changeChar(playery, playerx, '.');
                            item.erase(item.begin()+i);
                            action += ", and picks up 4 gold";
                        }
                    
                }
            }
        } else if (next == 92) {
            onStair = true;
        } else {
            action = "Invalid movement";
        }
    }
    if (direction == "ne") {
        char next = display->getChar(playery-1, playerx+1);
        if (next == '.' || next == '+' || next == '#') {
            display->changeChar(playery, playerx, previous);
            previous = next;
            display->changeChar(playery-1,playerx+1,'@');
            player->changePos(playery-1,playerx+1);
        } else if (next == 'G') {
            for (int i = 0; i < item.size(); i ++) {
                if ((item[i]->getRow() == playery-1) && (item[i]->getCol() == playerx+1)) {
                        if (item[i]->getSign() == "dragon" && item[i]->getIsDead()) {
                            player->changeGold(6);
                            display->changeChar(playery-1, playerx+1, '@');
                            display->changeChar(playery, playerx, previous);
                            item.erase(item.begin()+i);
                        } else {
                            player->changeGold(item[i]->getVal());
                            display->changeChar(playery-1, playerx+1, '@');
                            player->changePos(playery-1, playerx+1);
                            display->changeChar(playery, playerx, '.');
                            item.erase(item.begin()+i);
                            action += ", and picks up 4 gold";
                        }
                    
                }
            }
        } else if (next == 92) {
            onStair = true;
        } else {
            action = "Invalid movement";
        }
    }
    if (direction == "sw") {
        char next = display->getChar(playery+1, playerx-1);
        if (next == '.' || next == '+' || next == '#') {
            display->changeChar(playery, playerx, previous);
            previous = next;
            display->changeChar(playery+1,playerx-1,'@');
            player->changePos(playery+1,playerx-1);
        } else if (next == 'G') {
            for (int i = 0; i < item.size(); i ++) {
                if ((item[i]->getRow() == playery+1) && (item[i]->getCol() == playerx-1)) {
                        if (item[i]->getSign() == "dragon" && item[i]->getIsDead()) {
                            player->changeGold(6);
                            display->changeChar(playery+1, playerx-1, '@');
                            display->changeChar(playery, playerx, previous);
                            item.erase(item.begin()+i);
                        } else {
                            player->changeGold(item[i]->getVal());
                            display->changeChar(playery+1, playerx-1, '@');
                            player->changePos(playery+1, playerx-1);
                            display->changeChar(playery, playerx, '.');
                            item.erase(item.begin()+i);
                            action += ", and picks up 4 gold";
                        }
                    
                }
            }
        } else if (next == 92) {
            onStair = true;
        } else {
            action = "Invalid movement";
        }
    }
    if (direction == "se") {
        char next = display->getChar(playery+1, playerx+1);
        if (next == '.' || next == '+' || next == '#') {
            display->changeChar(playery, playerx, previous);
            previous = next;
            display->changeChar(playery+1,playerx+1,'@');
            player->changePos(playery+1,playerx+1);
        } else if (next == 'G') {
            for (int i = 0; i < item.size(); i ++) {
                if ((item[i]->getRow() == playery+1) && (item[i]->getCol() == playerx+1)) {
            
                        if (item[i]->getSign() == "dragon" && item[i]->getIsDead()) {
                            player->changeGold(6);
                            display->changeChar(playery+1, playerx+1, '@');
                            display->changeChar(playery, playerx, previous);
                            item.erase(item.begin()+i);
                        } else {
                            player->changeGold(item[i]->getVal());
                            display->changeChar(playery+1, playerx+1, '@');
                            player->changePos(playery+1, playerx+1);
                            display->changeChar(playery, playerx, '.');
                            item.erase(item.begin()+i);
                            action += ", and picks up 4 gold";
                        }
                
                }
            }
        } else if (next == 92) {
            onStair = true;
        } else {
            action = "Invalid movement";
        }
    }
}

bool Floor::getState() {
    return onStair;
}

void Floor::use_potion(string direction, string &action) {
    bool result = false;
    int playerx = player->getCol();
    int playery = player->getRow();
    int potionx = playerx;
    int potiony = playery;
    if (direction == "no") {
        potiony--;
    } else if(direction == "so"){
        potiony++;
    } else if(direction == "nw"){
        potionx--;
        potiony--;
    } else if(direction == "we"){
        potionx--;
    } else if(direction == "sw"){
        potionx--;
        potiony++;
    } else if(direction == "ne"){
        potionx++;
        potiony--;
    } else if(direction == "ea"){
        potionx++;
    } else if(direction == "se"){
        potionx++;
        potiony++;
    }
    char potion = display->getChar(potiony,potionx);
    if (potion == 'P') {
        result = true;
        for(int i = 0; i <item.size();++i){
            if(item[i]->getRow() == potiony && item[i]->getCol() == potionx){
                string s = item[i]->getSign();
                // check if player is drow. if so, effects are 1.5 times stronger.
                if(s == "RH") {
                    if (player->getSign() == 'D') {
                        player->change(15);
                    } else {
                        player->change(10);
                    }
                    if (player->getSign() != 'V' && player->getHealth() > 120) {
                        player->setHealth();
                    }
                    action = "PC uses " + s;
                } else if (s == "BA") {
                    if (player->getSign() == 'D') {
                        player->change(0, 7.5);
                        player->CA(7.5);
                    } else {
                        player->change(0,5);
                        player->CA(5);
                    }
                    action = "PC uses " + s;
                } else if (s == "BD") {
                    if (player->getSign() == 'D') {
                        player->change(0, 0, 7.5);
                        player->CD(7.5);
                    } else {
                        player->change(0,0,5);
                        player->CD(5);
                    }
                    action = "PC uses " + s;
                } else if (s == "PH") {
                    if (player->getSign() == 'D') {
                        player->change(-15);
                    } else {
                        player->change(-10);
                    }
                    action = "PC uses " + s;
                } else if (s == "WA") {
                    if (player->getSign() == 'D') {
                        player->change(0, -7.5);
                        player->CA(-7.5);
                    } else {
                        player->change(0,-5);
                        player->CA(-5);
                    }
                    action = "PC uses " + s;
                } else if (s == "WD") {
                    if (player->getSign() == 'D') {
                        player->change(0, 0, -7.5);
                        player->CD(-7.5);
                    } else {
                        player->change(0,0,-5);
                        player->CD(-5);
                    }
                    action = "PC uses " + s;
                }
                item.erase(item.begin()+i);
                display->changeChar(potiony, potionx, '.');
            }
        }
    }
    if (!result) {
        action += "Invalid use of potion";
    }
}

bool Floor::getMerchantHostile() {
    return merchantHostile;
}

void Floor::move_enemy(string &action) {
    int playerx = player->getCol();
    int playery = player->getRow();
    bool da=false;
    for(int i = 0; i<enemy.size();++i) {
        if((enemy[i]->getCol()==playerx+1 || enemy[i]->getCol() == playerx-1 || enemy[i]->getCol() == playerx) && (enemy[i]->getRow() == playery+1 || enemy[i]->getRow() == playery-1 || enemy[i]->getRow() == playery)){
            enemy[i]->attack(&(*player), action);
            if (enemy[i]->getSign() == 'M' && enemy[i]->getHostile() == false) {
                int movex;
                int movey;
                while (1) {
                    movex = rand () % 3 + -1;
                    movey = rand () % 3 + -1;
                    if (movex != 0 || movey != 0) break;
                }
                int newy = enemy[i]->getRow()+movey;
                int newx = enemy[i]->getCol()+movex;
                char next = display->getChar(newy, newx);
                if (next == '.' && enemy[i]->getSign() != 'D') {
                    display->changeChar(enemy[i]->getRow(), enemy[i]->getCol(), '.');
                    enemy[i]->changePos(newy, newx);
                    display->changeChar(newy, newx, enemy[i]->getSign());
                }
                
            }
            if(enemy[i]->getSign() == 'D') {
                da = true;
            }
        } else {
            int movex;
            int movey;
            while (1) {
                movex = rand () % 3 + -1;
                movey = rand () % 3 + -1;
                if (movex != 0 || movey != 0) break;
            }
            int newy = enemy[i]->getRow()+movey;
            int newx = enemy[i]->getCol()+movex;
            char next = display->getChar(newy, newx);
            if (next == '.' && enemy[i]->getSign() != 'D') {
                display->changeChar(enemy[i]->getRow(), enemy[i]->getCol(), '.');
                enemy[i]->changePos(newy, newx);
                display->changeChar(newy, newx, enemy[i]->getSign());
            }
        }
    }
    if (!da) {
        for (int i = 0; i < item.size(); i ++) {
            if (item[i]->getSign() == "dragon" &&
                (item[i]->getRow() == playery+1 || item[i]->getRow() == playery-1 || item[i]->getRow() == playery) && (item[i]->getCol() == playerx + 1 || item[i]->getCol() == playerx -1 || item[i]->getCol() == playerx)) {
                int r = item[i]->getRow();
                int c = item[i]->getCol();
                for (int j = 0; j < enemy.size(); j ++) {
                    if (enemy[j]->getSign() == 'D' && (enemy[j]->getRow() == r + 1 || enemy[j]->getRow() == r   -1 || enemy[j]->getRow() == r) && (enemy[j]->getCol() == c + 1 || enemy[j]->getCol() == c -1 || enemy[j]->getCol() == c)) {
                        enemy[j]->attack(&(*player),action);
                    }
                }
            }
        }
    }
}

void Floor::attack(string direction, string &action) {
    int playerx = player->getCol();
    int playery = player->getRow();
    int enemyx = playerx;
    int enemyy = playery;
    if (direction == "no") {
        enemyy--;
    } else if(direction == "so"){
        enemyy++;
    } else if(direction == "nw"){
        enemyx--;
        enemyy--;
    } else if(direction == "we"){
        enemyx--;
    } else if(direction == "sw"){
        enemyx--;
        enemyy++;
    } else if(direction == "ne"){
        enemyx++;
        enemyy--;
    } else if(direction == "ea"){
        enemyx++;
    } else if(direction == "se"){
        enemyx++;
        enemyy++;
    }
    bool result = false;
    for(int i = 0;i < enemy.size();i++){
        if(enemy[i]->getRow() == enemyy && enemy[i]->getCol() == enemyx){
            result = true;
            player->attack(&(*enemy[i]), action);
            if (enemy[i]->getSign() == 'M') {
                merchantHostile = true;
            }
            if(enemy[i]->getHealth()<=0){
                display->changeChar(enemyy,enemyx,'.');
                if (enemy[i]->getSign() == 'H') {
                    player->changeGold(2);
                } else if (enemy[i]->getSign() == 'M') {
                    shared_ptr<Item> treasure{new Treasure{"merchantH", enemyy, enemyx}};
                    display->changeChar(enemyy, enemyx, 'G');
                    item.emplace_back(treasure);
                } else if (enemy[i]->getSign() == 'D') {
                    for (int j = 0; j < item.size(); j ++) {
                        for (int x = -1; x < 2; x ++) {
                            for (int y = -1; y < 2; y ++) {
                                if ((item[j]->getRow() == enemyy+y) &&
                                    (item[j]->getCol() == enemyx+x) &&item[j]->getSign() == "dragon") {
                                    item[j]->setDead();
                                }
                            }
                        }
                    }
                } else {
                    player->changeGold(1);
                }
                // check if player is goblin. if so, steal 5 gold for every slained enemy.
                enemy.erase(enemy.begin()+i);
            }
        }
    }
    if (!result) {
        action += "Invalid attack";
    }
}

ostream &operator<<(std::ostream &out, const Floor &floor) {
    out << *(floor.display);
    return out;
}


Floor::~Floor() {
}


