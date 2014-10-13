#ifndef _Included_jlibfprint_Device
#define _Included_jlibfprint_Device

#include "libfprintWrapper.h"
#include <jni.h>

#define DEVICE_CLASS "jlibfprint/Device"

#ifdef __cplusplus
extern "C" {
#endif   

    jobject createDevice(JNIEnv *env, fp_dev * fpDevice);
    
    JNIEXPORT jint JNICALL Java_jlibfprint_Device_getNumberEnrollStages
    (JNIEnv *, jobject);
    
    JNIEXPORT jint JNICALL Java_jlibfprint_Device_getImageWidth
    (JNIEnv *, jobject);
    
    JNIEXPORT jint JNICALL Java_jlibfprint_Device_getImageHeight
    (JNIEnv *, jobject);
    
    JNIEXPORT void JNICALL Java_jlibfprint_Device_nativeClose
    (JNIEnv *, jobject);
   
    
#ifdef __cplusplus
}
#endif
#endif
