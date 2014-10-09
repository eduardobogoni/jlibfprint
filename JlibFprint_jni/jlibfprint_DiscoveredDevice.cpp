#include "jlibfprint_DiscoveredDevice.h"
#include "libfprintWrapper.h"

JNIEXPORT jint JNICALL Java_jlibfprint_DiscoveredDevice_getType(JNIEnv* env, jobject object) {
    const jclass deviceClass = env->FindClass("jlibfprint/DiscoveredDevice");
    jfieldID ptrFieldId = env->GetFieldID(deviceClass, "pointer", "J");
    fp_dscv_dev* discoveredDevice = (fp_dscv_dev*) env->GetLongField(object, ptrFieldId);
    return fp_dscv_dev_get_devtype(discoveredDevice);
}
