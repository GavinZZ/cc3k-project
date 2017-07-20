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

struct AllFloors{
    Floor **floors;
    int n;
};

int main(int argc, const char * argv[]) {
    AllFloors af;
    Player * p = new Shade;// default setting
    for(int i = 1; i<6;++i){
        Floor *f = new Floor{p,i};
        af.floors[i-1]= f;
    }
    if(argc>=2){
        // we have command line arguments
        string filename = argv[1];
        ifstream if{filename};
        string line;
        Floor *f = af.floors[0];
        Display *d = new Display;
        for(int n = 0; n < 5;n++){
           for(int i = 0; i<30 ; i++){
               getline(if,line);
               if(if.fail()){
                   break;
               }
               for(int j = 0;j<79;++j){
                   // inteprete items
                   if(line[j] == '0'){
                       Display->changeChar(i,j,"RH");
                   } else if(line[j] == '1'){
                       Display->changeChar(i,j,"BA");
                   } else if(line[j] == '2'){
                       Display->changeChar(i,j,"BD");
                   } else if(line[j] == '3'){
                       Display->changeChar(i,j,"PH");
                   } else if(line[j] == '4'){
                       Display->changeChar(i,j,"WA");
                   } else if(line[j] == '5'){
                       Display->changeChar(i,j,"WD");
                   } else if(line[j] == '6'){
                       Display->changeChar(i,j,"NORMAL");
                   } else if(line[j] == '7'){
                       Display->changeChar(i,j,"SMALLH");
                   } else if(line[j] == '8'){
                       Display->changeChar(i,j,"MERCHANTH");
                   } else if(line[j] == '9'){
                       Display->changeChar(i,j,"DRAGONH");
                   } else if(line[j] == '@'){
                       Display->changeChar(i,j,"@");
                       // need a function to change the position of player
                   } else if(line[j] == ''){
                       Display->changeChar(i,j,"BD");
                   }
                       
                       
                
        
    } else if(argc==1){
        // we don't have command line arguments
        f = new Floor{p,n};
    }
    char r;
    // s, d, v, g, t: specifies the race the player wishes to be when starting a game.
    cout<<"select your race: v for vampire, g for goblin, d for drow, t for troll, and s for shade";
    cin>>r;
    if(r == 'v'){
        Player *temp = p;
        p = nullptr;
        delete temp;
        p = new Vampire;
    } else if (r =='g'){
        Player *temp = p;
        p = nullptr;
        delete temp;
        p = new Goblin;
    } else if(r == 'd'){
        Player *temp = p;
        p = nullptr;
        delete temp;
        p = new Drow;
    } else if(r == 't'){
        Player *temp = p;
        p = nullptr;
        delete temp;
        p = new Troll;
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
                delete p;
                p = new Shade;
                for(int i = 1; i<6;++i){
                    Floor *f = new Floor{p,i};
                    delete af.floors[i-1];
                    af.floors[i-1]= f;
                }
                cout<<"select your race: v for vampire, g for goblin, d for drow, t for troll, and s for shade";
                cin>>r;
                if(r == 'v'){
                    Player *temp = p;
                    p = nullptr;
                    delete temp;
                    p = new Vampire;
                } else if (r =='g'){
                    Player *temp = p;
                    p = nullptr;
                    delete temp;
                    p = new Goblin;
                } else if(r == 'd'){
                    Player *temp = p;
                    p = nullptr;
                    delete temp;
                    p = new Drow;
                } else if(r == 't'){
                    Player *temp = p;
                    p = nullptr;
                    delete temp;
                    p = new Troll;
                }
            } else if(s=="q"){
                delete f;
                exit(0);
            }
        }
    }
}
