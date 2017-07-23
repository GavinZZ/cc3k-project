#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include "subject.h"
#include <string>
#include <map>
#include "observer.h"

class Display {
    std::vector<std::vector<char>> display;
public:
    Display();
    Display(std::string filename);
    void changeChar(int row, int col, char sign);
    char getChar(int row, int col);
    ~Display();
    friend std::ostream &operator<<(std::ostream &out, const Display &d);
};

#endif
