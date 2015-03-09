#include "jlibfprint_DiscoveredDevice.h"
#include "libfprintWrapper.h"
#include "JniUtils.h"
#include "jlibfprint_Driver.h"
#include "jlibfprint_Device.h"
#include "jlibfprint_DiscoveredDeviceList.h"

jobject createDiscoveredDevice(JNIEnv *env, fp_dscv_dev* fpDiscoveredDevice, jobject discoveredDeviceList) {
    const jclass discoveredDeviceClass = env->FindClass(DISCOVERED_DEVICE_CLASS);
    jobject device = env->AllocObject(discoveredDeviceClass);
    JniUtils::setInternalPointer(env, device, fpDiscoveredDevice);
    JniUtils::setObjectAttribute(env, device, "sourceList", "L"DISCOVERED_DEVICE_LIST_CLASS";", discoveredDeviceList);
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

JNIEXPORT jobject JNICALL Java_jlibfprint_DiscoveredDevice_open(JNIEnv* env, jobject object) {
    fp_dscv_dev* fpDiscoveredDevice = (fp_dscv_dev*) JniUtils::getInternalPointer(env, object);
    fp_dev* fpDevice = fp_dev_open(fpDiscoveredDevice);
    printf("Device: %p\n", fpDevice);
    return createDevice(env, fpDevice);
}