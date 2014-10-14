#ifndef _Included_jlibfprint_EnrollResult
#define _Included_jlibfprint_EnrollResult

#include "libfprintWrapper.h"
#include <jni.h>

#define ENROLL_RESULT_CLASS "jlibfprint/EnrollResult"

#ifdef __cplusplus
extern "C" {
#endif   

    jobject createEnrollResult(JNIEnv *env, fp_print_data* printData, int enrollCode);

#ifdef __cplusplus
}
#endif
#endif
