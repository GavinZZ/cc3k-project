#ifndef _OBSERVER_H_
#define _OBSERVER_H_
#include "subscriptions.h"
class Subject;
class Enemy;

class Observer {
public:
    virtual void notify(Subject &whoNotified, string action) = 0;
    virtual ~Observer() = default;
};
#endif
