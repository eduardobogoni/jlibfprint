#include "jlibfprint_Device.h"
#include "libfprintWrapper.h"
#include "JniUtils.h"
#include "jlibfprint_EnrollResult.h"

jobject createDevice(JNIEnv *env, fp_dev * fpDevice) {
    const jclass driverClass = env->FindClass(DEVICE_CLASS);
    jobject driver = env->AllocObject(driverClass);
    JniUtils::setInternalPointer(env, driver, fpDevice);
    return driver;
}

JNIEXPORT jint JNICALL Java_jlibfprint_Device_getNumberEnrollStages(JNIEnv * env, jobject object) {
    return fp_dev_get_nr_enroll_stages((fp_dev*) JniUtils::getInternalPointer(env, object));
}

JNIEXPORT jint JNICALL Java_jlibfprint_Device_getImageWidth(JNIEnv * env, jobject object) {
    return fp_dev_get_img_width((fp_dev*) JniUtils::getInternalPointer(env, object));
}

JNIEXPORT jint JNICALL Java_jlibfprint_Device_getImageHeight(JNIEnv * env, jobject object) {
    return fp_dev_get_img_height((fp_dev*) JniUtils::getInternalPointer(env, object));
}

JNIEXPORT void JNICALL Java_jlibfprint_Device_nativeClose(JNIEnv * env, jobject object) {
    return fp_dev_close((fp_dev*) JniUtils::getInternalPointer(env, object));
}

JNIEXPORT jobject JNICALL Java_jlibfprint_Device_enroll(JNIEnv * env, jobject object) {
    fp_dev* fpDevice = (fp_dev*) JniUtils::getInternalPointer(env, object);
    fp_print_data* fpPrintData;
    int code = fp_enroll_finger(fpDevice, &fpPrintData);
    return createEnrollResult(env, fpPrintData, code);
}
