#include "jlibfprint_Driver.h"
#include "libfprintWrapper.h"
#include "JniUtils.h"

jobject createDriver(JNIEnv *env, fp_driver* fpDriver) {
    const jclass driverClass = env->FindClass(DRIVER_CLASS);
    jobject driver = env->AllocObject(driverClass);
    JniUtils::setInternalPointer(env, driver, fpDriver);
    return driver;
}

JNIEXPORT jint JNICALL Java_jlibfprint_Driver_getId(JNIEnv * env, jobject object) {
    fp_driver* fpDriver = (fp_driver*) JniUtils::getInternalPointer(env, object);
    return fp_driver_get_driver_id(fpDriver);
}

JNIEXPORT jstring JNICALL Java_jlibfprint_Driver_getName(JNIEnv * env, jobject object) {
    fp_driver* fpDriver = (fp_driver*) JniUtils::getInternalPointer(env, object);
    const char* name = fp_driver_get_name(fpDriver);
    return env->NewStringUTF(name);
}

JNIEXPORT jstring JNICALL Java_jlibfprint_Driver_getFullName(JNIEnv * env, jobject object) {
    fp_driver* fpDriver = (fp_driver*) JniUtils::getInternalPointer(env, object);
    const char* fullName = fp_driver_get_full_name(fpDriver);
    return env->NewStringUTF(fullName);
}