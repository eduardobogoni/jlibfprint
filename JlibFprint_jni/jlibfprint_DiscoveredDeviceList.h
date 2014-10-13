#ifndef _Included_jlibfprint_DiscoveredDeviceList
#define _Included_jlibfprint_DiscoveredDeviceList

#include <jni.h>
#include "libfprintWrapper.h"

#define DISCOVERED_DEVICE_LIST_CLASS "jlibfprint/DiscoveredDeviceList"

#ifdef __cplusplus
extern "C" {
#endif

    jobject createDiscoveredDeviceList(JNIEnv *env, fp_dscv_dev** fpDiscoveredDevices);

#ifdef __cplusplus
}
#endif
#endif
