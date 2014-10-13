#include "jlibfprint_DiscoveredDevice.h"
#include "libfprintWrapper.h"
#include "JniUtils.h"
#include "jlibfprint_Driver.h"

jobject createDiscoveredDevice(JNIEnv *env, fp_dscv_dev* fpDiscoveredDevice) {
    const jclass discoveredDeviceClass = env->FindClass(DISCOVERED_DEVICE_CLASS);
    jobject device = env->AllocObject(discoveredDeviceClass);
    JniUtils::setInternalPointer(env, device, fpDiscoveredDevice);
    return device;
}

JNIEXPORT jint JNICALL Java_jlibfprint_DiscoveredDevice_getType(JNIEnv* env, jobject object) {
    fp_dscv_dev* fpDiscoveredDevice = (fp_dscv_dev*) JniUtils::getInternalPointer(env, object);
    return fp_dscv_dev_get_devtype(fpDiscoveredDevice);
}

JNIEXPORT jint JNICALL Java_jlibfprint_DiscoveredDevice_getDriverId(JNIEnv* env, jobject object) {
    fp_dscv_dev* fpDiscoveredDevice = (fp_dscv_dev*) JniUtils::getInternalPointer(env, object);
    return fp_dscv_dev_get_driver_id(fpDiscoveredDevice);
}

JNIEXPORT jobject JNICALL Java_jlibfprint_DiscoveredDevice_nativeGetDriver(JNIEnv* env, jobject object) {
    fp_dscv_dev* fpDiscoveredDevice = (fp_dscv_dev*) JniUtils::getInternalPointer(env, object);
    fp_driver* fpDriver = fp_dscv_dev_get_driver(fpDiscoveredDevice);
    return createDriver(env, fpDriver);
}