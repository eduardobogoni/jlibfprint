#include "jlibfprint_DiscoveredDeviceList.h"
#include "JniUtils.h"
#include "jlibfprint_DiscoveredDevice.h"

jobject createDiscoveredDeviceList(JNIEnv *env, fp_dscv_dev** fpDiscoveredDevices) {
    const jclass discoveredDeviceListClass = env->FindClass(DISCOVERED_DEVICE_LIST_CLASS);
    jobject list = env->AllocObject(discoveredDeviceListClass);
    JniUtils::setInternalPointer(env, list, fpDiscoveredDevices);

    int count = 0;
    for (int i = 0; fpDiscoveredDevices[i] != NULL; ++i) {
        count++;
    }
    const jclass discoveredDeviceClass = env->FindClass(DISCOVERED_DEVICE_CLASS);
    jobjectArray discoveredDeviceArray = env->NewObjectArray(count, discoveredDeviceClass, 0);

    for (int i = 0; i < count; ++i) {
        jobject discoveredDevice = createDiscoveredDevice(env, fpDiscoveredDevices[i]);
        env->SetObjectArrayElement(discoveredDeviceArray, i, discoveredDevice);
    }
    JniUtils::setObjectAttribute(env, list, "discoveredDevices", "[L" DISCOVERED_DEVICE_CLASS ";",
            discoveredDeviceArray);
    return list;
}

