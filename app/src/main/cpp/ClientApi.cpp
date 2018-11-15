//
// Created by Youssef Hanna on 11/9/18.
//
#include <jni.h>
#include <iostream>
#include <pthread.h>
#include "ClientApi.h"
#include <thread>

jclass objClass;
jobject callbacksInstance;
jmethodID methodId;

void ClientApi::update(bool forceUpdate){

     /*
     * Get the Global Reference of the Java Class
     * */
     callbacksInstance = env->NewGlobalRef(callingObjet);

    /*
     * Get Object Class
     * */
     objClass = env->GetObjectClass(callbacksInstance);

      /*
      * Check if Null return false
      * */
      if(objClass == NULL)
      {
            printf("objClass Its null");
      }
      else
      {

     /*
       * Get the Callback Method which you need to Notify
       * from C++ to proceed with your functions
     * */

      methodId = env->GetMethodID(objClass,"forceUpdate","(Z)V");

    /*
     * If Method Not there then return null
     */
     if(methodId == NULL){

         printf("methodId Its null");

     }

     }

    std::thread thread = std::thread( std::bind( &ClientApi::callback, this) );
    thread.detach();


}


void ClientApi::callback () {


    JNIEnv * g_env;

    /*
     * Attach the current Thread and get the virtual Machine
     * */
    java_virtualMachine -> AttachCurrentThread ((JNIEnv * * ) & g_env, NULL);

    int getEnvStat = java_virtualMachine -> GetEnv (( void  * * ) & g_env, JNI_VERSION_1_6);

    if (g_env == NULL) {
        printf ("Adding - ############ callback JNIEnv fail" );
    }
    if (getEnvStat == JNI_EDETACHED) {
        printf ( "Adding - ############ callback edetached" );
    } else  if (getEnvStat == JNI_OK) {
        printf ( "Adding - ############ callback ok" );
    } else  if (getEnvStat == JNI_EVERSION) {
        printf ("Adding - ############ callback eversion" );
    }


    jboolean v = true;

    g_env->CallVoidMethod(callbacksInstance,methodId,v);


    //g_env -> CallVoidMethod (g_obj, g_mid, val);
    if (g_env -> ExceptionCheck ()) {
        g_env -> ExceptionDescribe ();
    }

    java_virtualMachine -> DetachCurrentThread ();
}
