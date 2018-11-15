//
// Created by Youssef Hanna on 11/8/18.
//

#ifndef JNIRESOLVER_FORCEUPDATE_H
#define JNIRESOLVER_FORCEUPDATE_H

#include <vector>
#include <iostream>
#include <algorithm>
#include "ISubject.h"

/**/
class ForceUpdate : public  ISubject{

    std::vector<Observer *> observers;
    bool isUpdated;
public:

    void registerObserver(Observer *observer) override;
    void removeObserver(Observer *observer) override;
    void notifyObservers() override ;

    /*
     * set the new dictionary data
     * @param dictionary data which loaded from the service
     * */
    void setUpdated(bool isUpdated);


};


#endif //JNIRESOLVER_FORCEUPDATE_H
