#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include "subscriptions.h"
#include "display.h"
#include <string>
class Subject;
class Enemy;

class Observer {
public:
    virtual void notify(Subject &whoNotified, std::string action) = 0;
    virtual ~Observer() = default;
};
#endif
