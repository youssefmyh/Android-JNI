//
// Created by Youssef Hanna on 11/8/18.

//

#ifndef JNIRESOLVER_OBSERVER_H
#define JNIRESOLVER_OBSERVER_H

/*
 * Define and interface the Observer
 * */
class Observer {

public:

    /*
     *Update the state of the observer
     *@param updated
     **/
    virtual void update(bool isUpdate) = 0;

};


#endif //JNIRESOLVER_OBSERVER_H
