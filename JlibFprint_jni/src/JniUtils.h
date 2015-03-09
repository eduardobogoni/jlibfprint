#ifndef JNIUTILS_H
#define	JNIUTILS_H

#include <jni.h>

class JniUtils {
public:
    static void setObjectAttribute(JNIEnv* env, jobject object, const char* attributeName, 
            const char* typeSignature, jobject value);
    static void setIntegerAttribute(JNIEnv* env, jobject object, const char* attributeName, 
            int value);
    static void* getInternalPointer(JNIEnv* env, jobject object);
    static void setInternalPointer(JNIEnv* env, jobject object, void* pointer);

};
#endif	/* JNIUTILS_H */