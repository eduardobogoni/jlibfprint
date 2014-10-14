#ifndef _Included_jlibfprint_PrintData
#define _Included_jlibfprint_PrintData

#include "libfprintWrapper.h"
#include <jni.h>

#define PRINT_DATA_CLASS "jlibfprint/PrintData"

#ifdef __cplusplus
extern "C" {
#endif   

    jobject createPrintData(JNIEnv *env, fp_print_data* printData);
    
    JNIEXPORT void JNICALL Java_jlibfprint_PrintData_free
    (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
