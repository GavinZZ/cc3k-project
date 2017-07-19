#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include "floor.h"
#include "character.h"
#include "item.h"
class Shade;
class Vampire;
class Orc;
class Dwarf;
class Elf;
using namespace std;

int main(int argc, const char * argv[]) {
    int n = 1;
    Floor *f = nullptr;
    Player * p = new Shade;// default setting
    if(argc>=2){
        // we have command line arguments
        string filename = argv[1];
        ifstream if{filename};
        ......;// create a new floor and use f to point to it
    } else if(argc==1){
        // we don't have command line arguments
        f = new Floor{p,n};
    }
    char r;
    cout<<"select your race: v for vampire, o for orc, d for dwarf, e for elf, and else for shade";
    cin>>r;
    if(r == 'v'){
        Player *temp = p;
        p = nullptr;
        delete temp;
        p = new Vampire;
    } else if (r =='o'){
        Player *temp = p;
        p = nullptr;
        delete temp;
        p = new Orc;
    } else if(r == 'd'){
        Player *temp = p;
        p = nullptr;
        delete temp;
        p = new Dwarf;
    } else if(r == 'e'){
        Player *temp = p;
        p = nullptr;
        delete temp;
        p = new Elf;
    }
    while(!f->isWon()){
        string s;
        while(cin>>s){
            if(s == "no" || s == "ne" || s == "ea" || s == "se" || s == "so" || s == "sw" || s == "we" || s == "nw"){
                f->mover_player(s);
            } else if(s == "a"){
                cin>>s;
                if(s == "no" || s == "ne" || s == "ea" || s == "se" || s == "so" || s == "sw" || s == "we" || s == "nw"){
                  f->attack(s);
                } else {
                  cout<<"Wrong direction. Please enter new command again"
                }
            } else if(s == "u"){
                cin>>s;
                if(s == "no" || s == "ne" || s == "ea" || s == "se" || s == "so" || s == "sw" || s == "we" || s == "nw"){
                  f->use_potion(s);
                } else {
                  cout<<"Wrong direction. Please enter new command again"
                }
            } else if(s=="r"){
                // reset race? I don't know what to do here
            } else if(s=="q"){
                delete f;
                exit(0);
            }
        }
    }
}
