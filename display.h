#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include "subject.h"
#include <string>
#include "observer.h"

class Display: public Observer{
    std::vector<std::vector<char>> display;
public:
    void notify(Subject &whoNotified, std::string action) override;
    ~Display();
};

#endif
