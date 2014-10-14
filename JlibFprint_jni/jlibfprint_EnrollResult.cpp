#include "jlibfprint_EnrollResult.h"
#include "jlibfprint_PrintData.h"
#include "libfprintWrapper.h"
#include "JniUtils.h"

jobject createEnrollResult(JNIEnv *env, fp_print_data* printData, int enrollCode) {
    const jclass clazz = env->FindClass(ENROLL_RESULT_CLASS);
    jobject enrollResult = env->AllocObject(clazz);
    JniUtils::setObjectAttribute(
            env,
            enrollResult,
            "printData",
            "L" PRINT_DATA_CLASS ";",
            createPrintData(env, printData)
    );
    JniUtils::setIntegerAttribute(
            env,
            enrollResult,
            "code",            
            enrollCode
    );
    return enrollResult;
}