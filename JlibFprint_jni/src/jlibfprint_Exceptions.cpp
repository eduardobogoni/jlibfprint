#include "jlibfprint_Exceptions.h"

void throw_core_exception(JNIEnv* env, const char* message) {
    const jclass clazz = env->FindClass(CORE_EXCEPTION_CLASS);
    const jmethodID constructor = env->GetMethodID(clazz, "<init>", "(Ljava/lang/String;)V");
    jobject exception = env->NewObject(clazz, constructor, message);
    env->Throw((jthrowable) exception);
}

void throw_enroll_exception(JNIEnv* env, int errorCode) {
    const jclass eeClass = env->FindClass(ENROLL_EXCEPTION_CLASS);
    jobject enrollException = env->AllocObject(eeClass);
    jfieldID eeExcp_id = env->GetFieldID(eeClass, "enroll_exception", "I");
    env->SetIntField(enrollException, eeExcp_id, errorCode);
    env->Throw((jthrowable) enrollException);
}