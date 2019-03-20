#include <jni.h>
#include <dlfcn.h>
#include "enhanced_dlfcn.h"


jstring Java_com_example_testapplication_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject thiz) {
    void *art_lib = NULL;
    void *art_quick_to_interpreter_bridge = NULL;
    char result[256];

    memset(result,0,sizeof(result));
    if(sizeof(long) == 4) {
        art_lib = enhanced_dlopen("/system/lib/libart.so", RTLD_NOW);
    }else {
        art_lib = enhanced_dlopen("/system/lib64/libart.so", RTLD_NOW);
    }

    art_quick_to_interpreter_bridge = enhanced_dlsym(art_lib,"art_quick_to_interpreter_bridge");
    snprintf(result, sizeof(result),"find art_quick_to_interpreter_bridge at %p",art_quick_to_interpreter_bridge);

    return (*env)->NewStringUTF(env,result);
}
