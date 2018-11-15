//
// Created by Youssef Hanna on 11/9/18.
//

#ifndef JNIRESOLVER_ISUBJECT_H
#define JNIRESOLVER_ISUBJECT_H

#include "Observer.h"

/*
 * ISubject - Interface for the Subject
 * */
class ISubject {


public:

    /*
     * Register observer
     * @param observer the observer subject to be registered
     * */
    virtual void registerObserver(Observer *observer) = 0;


    /*
     * remove an Observer
     *@param Observer the Observer object to be unregistered
     * */
    virtual void removeObserver(Observer *observer) = 0;

    /*
     * Notify All registered observers
     * */
    virtual void notifyObservers() = 0;

};


#endif //JNIRESOLVER_ISUBJECT_H
