//
// Created by Youssef Hanna on 11/9/18.
//
#include <stdio.h>
#include <jni.h>

#ifndef JNIRESOLVER_CLIENTAPI_H
#define JNIRESOLVER_CLIENTAPI_H

#include "Observer.h"

class ClientApi :public Observer{


public:
    JavaVM * java_virtualMachine;
    jclass callingObjet;
    JNIEnv *env;

    ClientApi(){

    }
    ~ClientApi(){}
    void update(bool update) override ;
    void callback ();


};


#endif //JNIRESOLVER_CLIENTAPI_H
