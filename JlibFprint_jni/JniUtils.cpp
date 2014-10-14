#include "JniUtils.h"

void JniUtils::setObjectAttribute(JNIEnv* env, jobject object,
        const char* attributeName, const char* typeSignature, jobject value) {
    const jclass clazz = env->GetObjectClass(object);
    jfieldID fieldId = env->GetFieldID(clazz, attributeName, typeSignature);
    env->SetObjectField(object, fieldId, value);
}

void JniUtils::setIntegerAttribute(JNIEnv* env, jobject object, 
        const char* attributeName, int value) {
    const jclass clazz = env->GetObjectClass(object);
    jfieldID fieldId = env->GetFieldID(clazz, attributeName, "I");
    env->SetIntField(object, fieldId, value);
}

void* JniUtils::getInternalPointer(JNIEnv* env, jobject object) {
    const jclass clazz = env->GetObjectClass(object);
    jfieldID internalPointerFieldId = env->GetFieldID(clazz, "internalPointer", "J");
    return (void*) env->GetLongField(object, internalPointerFieldId);
}

void JniUtils::setInternalPointer(JNIEnv* env, jobject object, void* pointer) {
    const jclass clazz = env->GetObjectClass(object);
    jfieldID internalPointerFieldId = env->GetFieldID(clazz, "internalPointer", "J");
    env->SetLongField(object, internalPointerFieldId, (long) pointer);
}

