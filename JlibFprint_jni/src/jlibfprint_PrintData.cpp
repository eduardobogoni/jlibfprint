#include "jlibfprint_PrintData.h"
#include "libfprintWrapper.h"
#include "JniUtils.h"
#include "jlibfprint_Exceptions.h"
#include <string.h>

jobject createPrintData(JNIEnv *env, fp_print_data* printData) {
    const jclass driverClass = env->FindClass(PRINT_DATA_CLASS);
    jobject driver = env->AllocObject(driverClass);
    JniUtils::setInternalPointer(env, driver, printData);
    return driver;
}

JNIEXPORT void JNICALL Java_jlibfprint_PrintData_free(JNIEnv* env, jobject object) {
    fp_print_data_free((fp_print_data*) JniUtils::getInternalPointer(env, object));
}

JNIEXPORT jbyteArray JNICALL Java_jlibfprint_PrintData_getData(JNIEnv * env, jobject object) {
    fp_print_data* fpPrintData = (fp_print_data*) JniUtils::getInternalPointer(env, object);
    unsigned char* buffer;
    int writed = fp_print_data_get_data(fpPrintData, &buffer);
    if (writed == 0) {
        throw_core_exception(env, "PrintData data buffer could not be allocated");
        return NULL;
    } else {
        jbyteArray byteData = env->NewByteArray(writed);
        jboolean isCopy;
        void *data = env->GetPrimitiveArrayCritical((jarray) byteData, &isCopy);
        memcpy(data, buffer, writed);
        env->ReleasePrimitiveArrayCritical(byteData, data, 0);
        return byteData;
    }
}
