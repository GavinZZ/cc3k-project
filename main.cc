#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include "floor.h"
#include "display.h"
#include "character.h"
#include "item.h"
class Shade;
class Vampire;
class Goblin;
class Drow;
class Troll;
using namespace std;


int main(int argc, const char* argv[]) {
    while (1) {
    Shade shade;
    Vampire v;
    Goblin g;
    Drow d;
    Troll t;
    bool hostile = false;
    Player *p = &shade;// default setting
    cout<<"Welcome to the world of CC3K! Please chouse your character race"<<endl;
    string r;
    // s, d, v, g, t: specifies the race the player wishes to be when starting a game.
    cout << "v for Vampire || Health: 50  || Attack: 25 || Defence: 25 || Skills: gain 5HP for every successful attack." << endl;
    cout << "g for Goblin  || Health: 110 || Attack: 15 || Defence: 20 || Skills: steal 5 gold from every enemy slained." << endl;
    cout << "d for Drow    || Health: 150 || Attack: 25 || Defence: 15 || Skills: all potions' effect are magnified by 1.5." << endl;
    cout << "t for Troll   || Health: 120 || Attack: 25 || Defence: 15 || Skills: regain 5HP every turn." << endl;
        cout << "s for Shade   || Health: 125 || Attack: 25 || Defence: 25 || Skills: no skills."<<endl;
        cout << "Max health of all race except vampire is capped at their starting HP." << endl;
        cout << "Warning: If an invalid command is taken, the default character Shade will be chosen" << endl;
    
    string race = "Shade";
    cin >> r;
    if(r == "v"){
        p = &v;
        race = "Vampire";
    } else if (r =="g"){
        p = &g;
        race = "Goblin";
    } else if(r == "d"){
        p = &d;
        race = "Drow";
    } else if(r == "t"){
        p = &t;
        race = "Troll";
    }
    Floor f;
    if(argc == 2){
        string filename = argv[1];
        Floor floor {filename, p,1};
        f = floor;
    } else if(argc==1){
        // we don't have command line arguments
        Floor floor {p,1};
        f = floor;
    }
    string s;
    string action = "Player character has spawned."; // used to print action mode
    int n = 1;
    cout<< f <<endl;
    cout<<"Race: "<<race<<" Gold:"<<p->getGold();
    cout<<"                                                   Floor: "<< n << endl;
    cout<<"HP: "<<p->getHealth()<<endl;
    cout<<"Atk: "<<p->getAttack()<<endl;
    cout<<"Def: "<<p->getDefence()<<endl;
    cout << "Action: ";
    cout<<action<<endl;
    while(true){
        if(p->getSign()== 'T'){
            p->change(5);
            if (p->getHealth() >= 120) {
                p->setHealth();
            }
        }
        action = "";
        cin>> s;
        if(s == "no" || s == "ne" || s == "ea" || s == "se" || s == "so" || s == "sw" || s == "we" || s == "nw"){
            string direction;
            if(s == "no"){
                direction = "North";
            } else if(s == "ne"){
                direction = "NorthEast";
            } else if(s == "ea"){
                direction = "East";
            } else if(s == "se"){
                direction = "SouthEast";
            } else if(s == "so"){
                direction = "South";
            } else if(s == "sw"){
                direction = "SouthWest";
            } else if(s == "we"){
                direction = "West";
            } else if(s == "nw"){
                direction = "NorthWest";
            }
            action += "PC moves ";
            action += direction;
            f.move_player(s, action);
            if(f.getState()){
                n++;
                if(n == 6){
                    cout<<"Congratulation! You reach the end of adventure."<<endl;
                    cout<<"Do you want to play again: r to play again, q to quit"<<endl;
                } else {
                    p->changeCorrection();
                    p->setCorrection();
                    if(argc == 2){
                        string filename = argv[1];
                        Floor floor {filename, p,n};
                        f = floor;
                    } else if(argc==1){
                        // we don't have command line arguments
                        Floor floor {p,n};
                        f = floor;
                    }
                    if (hostile) {
                        f.setHostile();
                    }
                    action += " and go upstair";
                }
            } else {
                f.move_enemy(action);
                shared_ptr<Display> display = f.getDisplay();
                bool state = false;
                for(int i = -1;i<2;i++){
                    for(int j = -1;j<2;j++){
                        char c = display->getChar(p->getRow()+i,p->getCol()+j);
                        if(c=='P'){
                            action +=" and see an unknown Potion";
                            state = true;
                            break;
                        }
                    }
                    if(state) break;
                }
            }
        } else if(s == "a"){
            cin>>s;
            if(s == "no" || s == "ne" || s == "ea" || s == "se" || s == "so" || s == "sw" || s == "we" || s == "nw"){
                f.attack(s,action);
                f.move_enemy(action);
                if (f.getMerchantHostile()) {
                    hostile = true;
                }
            }
        } else if(s == "u"){
            cin>>s;
            if(s == "no" || s == "ne" || s == "ea" || s == "se" || s == "so" || s == "sw" || s == "we" || s == "nw"){
                f.use_potion(s,action);
                f.move_enemy(action);
            }
        } else if(s=="r"){
            break;
        } else if(s=="q"){
            cout<<"Thanks for your adventure. Good luck next time."<<endl;
            break;
        } else {
            action = "Invalid command";
        }
        if (n <= 5) {
            cout<<f;
            cout<<"Race:: "<<race<<" Gold:"<<p->getGold();
            cout<<"                                                  "<<"Floor: "<<n << endl;
            cout<<"HP: "<<p->getHealth()<<endl;
            cout<<"Atk: "<<p->getAttack()<<endl;
            cout<<"Def: "<<p->getDefence()<<endl;
            cout << "Action: ";
            cout<< action <<"."<<endl;
        }
        if (f.isLost()) {
            string read;
            cout << "DEFEATED. You have been slained by enemies." << endl;
            cout << "Do you wanna try again?"<<endl;
            cout<<endl<<endl;
            cout<<"r for yes and q for no"<<endl;
            while (1) {
                cin >> read;
                if (read == "r" || read == "q") {
                    break;
                }
                cout << "Invalid Command. Please choose r for yes and q for no.";
            }
            if (read == "q") {
                s = "q";
            }
            break;
        }
    }
        if (s == "q") {
            cout<<"Game ended."<<endl;
            break;
        }
    }
}

