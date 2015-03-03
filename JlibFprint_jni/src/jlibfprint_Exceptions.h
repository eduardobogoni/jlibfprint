#ifndef _Included_jlibfprint_Exceptions
#define _Included_jlibfprint_Exceptions

#include <jni.h>

#define CORE_EXCEPTION_CLASS "jlibfprint/CoreException"
#define ENROLL_EXCEPTION_CLASS "jlibfprint/JlibFprint$EnrollException"

#ifdef __cplusplus
extern "C" {
#endif   

    void throw_core_exception(JNIEnv* env, const char* message);

    void throw_enroll_exception(JNIEnv* env, int errorCode);
    
#ifdef __cplusplus
}
#endif
#endif
