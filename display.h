#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include "subject.h"
#include <string>
#include "observer.h"

class Display {
    std::vector<std::vector<char>> display;
public:
    Display();
    Display(std::string filename);
    void changeChar(int row, int col, char sign);
    char getChar(int row, int col);
    ~Display();
};

#endif
