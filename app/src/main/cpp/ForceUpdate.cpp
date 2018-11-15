//
// Created by Youssef Hanna on 11/8/18.
//

#include "ForceUpdate.h"

/*
 * register Observer
 * @param observer
 * */
void ForceUpdate::registerObserver(Observer *observer)
{

    this->observers.push_back(observer);

    this->setUpdated(true);

}

/*
 * remove observer
 * @param observer
 * */
void ForceUpdate::removeObserver(Observer *observer){

    auto iterator = std::find(observers.begin(),observers.end(),observer);

    if(iterator != observers.end()){

        observers.erase(iterator);

    }

}

/*
 *
 * notify the observers
 *
 * */
void ForceUpdate::notifyObservers(){

    for(Observer * observer: observers){

        observer->update(isUpdated);

    }
}

/*
 *
 * Set Dictionary Data
 * @param CCDictionary dictionary
 *
 * */
void ForceUpdate::setUpdated(bool isUpdated){

        this->isUpdated = isUpdated;

        this->notifyObservers();

}


