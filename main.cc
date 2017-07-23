#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include "floor.h"
#include "character.h"
#include "item.h"
class Shade;
class Vampire;
class Goblin;
class Drow;
class Troll;
using namespace std;

int main(int argc, const char * argv[]) {
    Shade shade;
    Player *p = &shade;// default setting
    cout<<"Welcome to the world of CC3K! Please chouse your character race"<<endl;
    char r;
    // s, d, v, g, t: specifies the race the player wishes to be when starting a game.
    cout<<"v for vampire, g for goblin, d for drow, t for troll, and s for shade"<<endl;
    string race = "Shade";
    cin>>r;
    if(r == 'v'){
        Vampire v;
        p = &v;
        race = "Vampire";
    } else if (r =='g'){
        Goblin g;
        p = &g;
        race = "Goblin";
    } else if(r == 'd'){
        Drow d;
        p = &d;
        race = "Drow";
    } else if(r == 't'){
        Troll t;
        p = &t;
        race = "Troll";
    }
    Floor *f = nullptr;
    if(argc == 2){
        string filename = argv[1];
        Floor floor {filename, p,1};
        f = &floor;
    } else if(argc==1){
        // we don't have command line arguments
        Floor floor {p,1};
        f = &floor;
    }
    string s;
    string action = "Player character has spawned."; // used to print action mode
    int n = 1;
    cout<<f<<endl;
    cout<<"Race:: "<<race<<" Gold:"<<p->getGold();
    cout<<"                                                  "<<"Floor: "<<n;
    cout<<"HP: "<<p->getHealth()<<endl;
    cout<<"Atk: "<<p->getAttack()<<endl;
    cout<<"Def: "<<p->getDefence()<<endl;
    cout<<action<<endl;
    while(true){
        if(p->getSign()== 'T'){
            p->change(5);
        }
        action = "";
        cin>> s;
        if(s == "no" || s == "ne" || s == "ea" || s == "se" || s == "so" || s == "sw" || s == "we" || s == "nw"){
            f->move_player(s);
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
            if(f->getState()){
                n++;
                if(n == 6){
                    cout<<"Congratulation! You reach the end of adventure."<<endl;
                    cout<<"Do you want to play again: r to play again, q to quit"<<endl;
                } else {
                    if(argc == 2){
                        string filename = argv[1];
                        Floor floor {filename, p,n};
                        f = &floor;
                    } else if(argc==1){
                        // we don't have command line arguments
                        Floor floor {p,n};
                        f = &floor;
                    }
                    action += " and go upstair";
                }
            } else {
                f->move_enemy();
                shared_ptr<Display> display = f->getDisplay();
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
                f->attack(s,action);
            }
        } else if(s == "u"){
            cin>>s;
            if(s == "no" || s == "ne" || s == "ea" || s == "se" || s == "so" || s == "sw" || s == "we" || s == "nw"){
                f->use_potion(s,action);
                f->move_enemy();
            }
        } else if(s=="r"){
            Shade shade;
            p = &shade;
            cout<<"Resetting game..."<<endl;
            cout<<"select your race: v for vampire, g for goblin, d for drow, t for troll, and s for shade"<<endl;
            cin>>r;
            if(r == 'v'){
                Vampire v;
                p = &v;
            } else if (r =='g'){
                Goblin g;
                p = &g;
            } else if(r == 'd'){
                Drow d;
                p = &d;
            } else if(r == 't'){
                Troll t;
                p = &t;
            }
            n = 1;
            if(argc == 2){
                string filename = argv[1];
                Floor floor {filename, p,1};
                f = &floor;
            } else if(argc==1){
                // we don't have command line arguments
                Floor floor {p,1};
                f = &floor;
            }
        } else if(s=="q"){
            cout<<"Thanks for your adventure. Good luck next time"<<endl;
            break;
        }
        cout<<f;
        cout<<"Race:: "<<race<<" Gold:"<<p->getGold();
        cout<<"                                                  "<<"Floor: "<<n;
        cout<<"HP: "<<p->getHealth()<<endl;
        cout<<"Atk: "<<p->getAttack()<<endl;
        cout<<"Def: "<<p->getDefence()<<endl;
        cout<<action<<"."<<endl;
    }
}
