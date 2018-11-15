#include <jni.h>
#include "ClientApi.h"
#include "ForceUpdate.h"

ForceUpdate forceUpdate;
ClientApi clientApi;

/*
 * JNI Call is created to be an interface for the Java Activity
 * This function should create the C++ Force Update Object and register the Observer
 * */

extern "C"
JNIEXPORT jboolean

JNICALL
Java_com_example_youssefhanna_myapplication_MainActivity_isForceUpdate(JNIEnv *env,jclass callingObjet , jobject callbacks){

    env -> GetJavaVM ( & clientApi.java_virtualMachine);
    clientApi.env = env;
    clientApi.callingObjet = callingObjet;

    /*
     * Init the Observer Class and register the Observer
     * */
    forceUpdate.registerObserver(&clientApi);
    /*Return false but it has no effect you can check if the function created normally*/
    return true;
}




/*
   Get the Global Reference of the Java Class

   callbacksInstance = env->NewGlobalRef(callingObjet);

   jclass objClass = env->GetObjectClass(callbacksInstance);

   if(objClass == NULL)
   {
      return  false;
   }
   else
   {
   jmethodID methodId = env->GetMethodID(objClass,"forceUpdate","(Z)V");
   if(methodId == NULL){
   return false;
   }
   jboolean v = true;
   env->CallVoidMethod(callbacksInstance,methodId,v);
   return true;
 }
*/