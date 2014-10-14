#include "jlibfprint_PrintData.h"
#include "libfprintWrapper.h"
#include "JniUtils.h"

jobject createPrintData(JNIEnv *env, fp_print_data* printData) {
    const jclass driverClass = env->FindClass(PRINT_DATA_CLASS);
    jobject driver = env->AllocObject(driverClass);
    JniUtils::setInternalPointer(env, driver, printData);
    return driver;
}

JNIEXPORT void JNICALL Java_jlibfprint_PrintData_free(JNIEnv* env, jobject object) {
    fp_print_data_free((fp_print_data*) JniUtils::getInternalPointer(env, object));
}
