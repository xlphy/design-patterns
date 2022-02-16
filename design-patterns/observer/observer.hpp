//
//  observer.hpp
//  design-patterns
//
//  Created by Xin Li on 2/15/22.
//

#ifndef observer_hpp
#define observer_hpp

#include<list>


/* Sample code for observer patterns */

// base classes
class Subject;

// support multiple subjects for each observer, the subject passed to the update operation lets observer
// determine which subject changed when it observes more than one
class Observer{
public:
    virtual ~Observer(){}
    virtual void update(Subject* ptr_changed_subject)=0;
protected:
    Observer(){}
};

class Subject{
public:
    virtual ~Subject(){}
    
    virtual void attach(Observer* o){_observers.push_back(o);}
    virtual void detach(Observer* o){_observers.remove(o);}
    virtual void notify(){
        for(std::list<Observer*>::iterator i = _observers.begin(); i != _observers.end(); ++i){
            (*i)->update(this);  // *i = Observer*
        }
    }
    
protected:
    Subject(){}
private:
    std::list<Observer*> _observers;
};


// concrete classes








#endif /* observer_hpp */
