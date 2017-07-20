#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>
class Observer;

class Subject {
protected:
    std::vector<Observer *> observers;
public:
    void attach(Observer *o);
    void notifyObservers();
    virtual ~Subject() = 0;
};

#endif
