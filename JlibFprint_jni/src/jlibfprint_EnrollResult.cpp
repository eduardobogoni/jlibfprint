#include "jlibfprint_EnrollResult.h"
#include "jlibfprint_PrintData.h"
#include "libfprintWrapper.h"
#include "JniUtils.h"

jobject createEnrollResult(JNIEnv *env, fp_print_data* fpPrintData, int enrollCode) {
    jobject printData = createPrintData(env, fpPrintData);
    const jclass clazz = env->FindClass(ENROLL_RESULT_CLASS);
    const jmethodID constructor = env->GetMethodID(clazz, "<init>", "(ILjlibfprint/PrintData;)V");
    return env->NewObject(clazz, constructor, enrollCode, printData);
}