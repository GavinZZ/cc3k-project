#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include "floor.h"
using namespace std;

int main(int argc, const char * argv[]) {
    int n = 1;
    Floor *f = nullptr;
    if(argc>=2){
        // we have command line arguments
        string filename = argv[1];
        ifstream if{filename};
        ......;// create a new floor and use f to point to it
    } else if(argc==1){
        // we don't have command line arguments
        f = new Floor;
    }
    
}
