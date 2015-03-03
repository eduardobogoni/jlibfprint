#ifndef _Included_jlibfprint_Driver
#define _Included_jlibfprint_Driver

#include "libfprintWrapper.h"
#include <jni.h>

#define DRIVER_CLASS "jlibfprint/Driver"

#ifdef __cplusplus
extern "C" {
#endif   

    jobject createDriver(JNIEnv *env, fp_driver* fpDriver);
    
    JNIEXPORT jint JNICALL Java_jlibfprint_Driver_getId(JNIEnv *, jobject);
    JNIEXPORT jstring JNICALL Java_jlibfprint_Driver_getName(JNIEnv *, jobject);
    JNIEXPORT jstring JNICALL Java_jlibfprint_Driver_getFullName(JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
